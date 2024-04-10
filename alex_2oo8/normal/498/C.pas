program problem3;
uses math;

const inf = 1000000000;

type tEdge = record
               u, v, next, q, d, id, pair: longInt;
             end;

var firstEdge, next, prev, h, p: array[ 0..300 ] of longInt;
    e: array[ 1..500 ] of tEdge;
    f: array[ 1..500 ] of longInt;
    ee, id: longInt;

procedure addEdge( u, v, q: longInt );
begin
	inc( id );

    inc( ee );
    e[ee].u := u;
    e[ee].v := v;
    e[ee].d := 1;
    e[ee].q := q;
    e[ee].id := id;
    e[ee].pair := ee + 1;
    e[ee].next := firstEdge[u];
    firstEdge[u] := ee;

    inc( ee );
    e[ee].u := v;
    e[ee].v := u;
    e[ee].d := -1;
    e[ee].q := 0;
    e[ee].id := id;
    e[ee].pair := ee - 1;
    e[ee].next := firstEdge[v];
    firstEdge[v] := ee;
end;

procedure increaseFlowOnEdge( ee, d: longInt );
begin
    dec( e[ee].q, d );
    inc( e[ e[ee].pair ].q, d );
    dec( p[ e[ee].u ], d );
    inc( p[ e[ee].v ], d );

    inc( f[ e[ee].id ], e[ee].d * d );
end;

procedure setNext( u, v: longInt );
begin
    next[u] := v;
    prev[v] := u;
end;

procedure lift( v: longInt );
var i: longInt;
begin
    h[v] := inf;

    i := firstEdge[v];
    while ( i > 0 ) do
    begin
        if ( e[i].q > 0 ) then
            h[v] := min( h[v], h[ e[i].v ] + 1 );

        i := e[i].next;
    end;

    setNext( prev[v], next[v] );
    setNext( v, next[0] );
    setNext( 0, v );
end;

procedure push( v: longInt );
var i: longInt;
begin
    i := firstEdge[v];
    while ( i > 0 ) and ( p[v] > 0 ) do
    begin
        if ( h[v] = h[ e[i].v ] + 1 ) then
            increaseFlowOnEdge( i, min( p[v], e[i].q ) );

        i := e[i].next;
    end;
end;

function max_flow( source, target, n: longInt ): longInt;
var	i, v, flow: longInt;
	ok: boolean;
begin
	fillchar( h, sizeOf(h), 0 );
	fillchar( p, sizeOf(p), 0 );
	fillchar( f, sizeOf(f), 0 );
	
    h[source] := n;

    i := firstEdge[source];
    while ( i > 0 ) do
    begin
        increaseFlowOnEdge( i, e[i].q );

        i := e[i].next;
    end;

    for i := 0 to n do
        setNext( i, i + 1 );

    setNext( n, 0 );
    setNext( prev[source], next[source] );
    setNext( prev[target], next[target] );

    v := 0;
    ok := false;
    while not ( ( v = 0 ) and ok ) do
    begin
        ok := ( ok or ( v = 0 ) ) and ( p[v] = 0 );

        while ( p[v] > 0 ) do
        begin
            push( v );

            if ( p[v] > 0 ) then
                lift( v );
        end;

        v := next[v];
    end;

    flow := 0;
    i := firstEdge[source];
    while ( i > 0 ) do
    begin
        inc( flow, f[ e[i].id ] );

        i := e[i].next;
    end;

    exit( flow );
end;

var	n, m: longInt;
	u, v, a, q: array[ 1..100 ] of longInt;
	
function calc( p: longInt ): longInt;
var	i: longInt;
begin
	fillchar( firstEdge, sizeOf(firstEdge), 0 );
	ee := 0;
	id := 0;
	
	for i := 1 to n do
	begin
		q[i] := 0;
		while ( a[i] mod p = 0 ) do
		begin
			a[i] := a[i] div p;
			inc( q[i] );
		end;
		
		if ( q[i] > 0 ) then
		begin
			if ( odd(i) ) then
				addEdge( n + 1, i, q[i] )
			else
				addEdge( i, n + 2, q[i] );
		end;
	end;
	
	for i := 1 to m do
		if ( q[ u[i] ] > 0 ) and ( q[ v[i] ] > 0 ) then
			addEdge( u[i], v[i], inf );
	
	exit( max_flow( n + 1, n + 2, n + 2 ) );
end;

var	ans, i, j: longInt;

begin
    readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to m do
	begin
		readln( u[i], v[i] );
		
		if ( odd( v[i] ) ) then
		begin
			u[i] := u[i] xor v[i];
			v[i] := u[i] xor v[i];
			u[i] := u[i] xor v[i];
		end;
	end;

	ans := 0;
	while ( true ) do
	begin
		i := 1;
		while ( i <= n ) and ( a[i] = 1 ) do
			inc( i );
		
		if ( i > n ) then
			break;
		
		j := 2;
		while ( j * j <= a[i] ) and ( a[i] mod j > 0 ) do
			inc( j );
		
		if ( a[i] mod j = 0 ) then
			inc( ans, calc( j ) )
		else
			inc( ans, calc( a[i] ) );
	end;
	
	writeln( ans );
end.