program problem3;
uses math;

type	tListNode =	record
						next, u, v: longInt;
					end;
				
var	first, p, firstEdge: array[ 0..100000 ] of longInt;
	lst, e: array[ 1..1000000 ] of tListNode;
	lw, iter, ee: longInt;
				
procedure add( u, v, w: longInt );
begin
	inc( lw );
	lst[lw].u := u;
	lst[lw].v := v;
	lst[lw].next := first[w];
	first[w] := lw;
end;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := firstEdge[u];
	firstEdge[u] := ee;
end;

function get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := get( p[v] );
	
	exit( p[v] );
end;

procedure getMinEdge( var u, v, w: longInt );
begin
	while ( first[iter] = 0 ) do
		inc( iter );
	
	u := lst[ first[iter] ].u;
	v := lst[ first[iter] ].v;
	w := iter;
	
	first[iter] := lst[ first[iter] ].next;
end;

procedure DFS( v, p: longInt );
var	i: longInt;
begin
	if ( p <> -1 ) then
		writeln( v, ' ', p );
	
	i := firstEdge[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v );
	
		i := e[i].next;
	end;
end;

var	a, b, n, w, i, j, k, l, d, uu, vv, u, v, ans: longInt;
	f: array[ 1..1000, 1..10 ] of ansistring;

begin
	iter := 0;
	ee := 0;
	lw := 0;

	readln( a, b, n, w );
	
	ans := 0;
	for i := 1 to n do
		for j := 1 to a do
			readln( f[i][j] );
	
	for i := 1 to n do
		for j := i + 1 to n do
		begin
			d := 0;
			for k := 1 to a do
				for l := 1 to b do
					if ( f[i][k][l] <> f[j][k][l] ) then
						inc( d );
			
			add( i, j, d * w );
		end;
	
	for i := 1 to n do
		add( 0, i, a * b );
	
	for i := 1 to n do
		p[i] := i;
	
	k := 0;
	while ( k < n ) do
	begin
		getMinEdge( u, v, w );
		
		uu := get(u);
		vv := get(v);
		if ( uu <> vv ) then
		begin
			p[uu] := vv;
			
			addEdge( u, v );
			addEdge( v, u );
			
			inc( k );
			inc( ans, w );
		end;
	end;
	
	writeln( ans );
	
	DFS( 0, -1 );
end.