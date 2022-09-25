program problem4;

type	tEdge =	record
					v, next: longInt;
				end;

var	first, deg, bad, rem, f: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	n, k: longInt;

procedure addEdge( u, v: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
	
	inc( deg[u] );
end;

procedure remove( v: longInt; x: extended );
var	i: longInt;
begin
	if ( rem[v] = 1 ) then
		exit();
	
	rem[v] := 1;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		inc( bad[ e[i].v ] );
		if ( bad[ e[i].v ] / deg[ e[i].v ] > x ) then
			remove( e[i].v, x );
	
		i := e[i].next;
	end;
end;

function check( x: extended; w: boolean ): boolean;
var	i, p: longInt;
begin
	for i := 1 to n do
	begin
		bad[i] := 0;
		rem[i] := 0;
	end;
	
	for i := 1 to k do
		remove( f[i], x );
	
	p := 0;
	for i := 1 to n do
		if ( rem[i] = 0 ) then
			inc( p );
		
	if ( w ) then
	begin
		writeln( p );
		for i := 1 to n do
			if ( rem[i] = 0 ) then
				write( i, ' ' );
		
		writeln();
	end;
	
	exit( p > 0 );
end;

var	m, i, u, v: longInt;
	l, r, c: extended;

begin
	readln( n, m, k );
	for i := 1 to k do
		read( f[i] );
	
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	l := 0.0;
	r := 1.0;
	for i := 1 to 60 do
	begin
		c := (l + r) / 2.0;
		
		if ( check( c, false ) ) then
			r := c
		else
			l := c;
	end;
	
	check( r, true );
end.