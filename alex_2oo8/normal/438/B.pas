program problem2;
uses math;

type	tEdge =	record
					u, v, next: longInt;
				end;

var	a, first, p, sz: array[ 0..100000 ] of longInt;
	e: array[ 1..100000 ] of tEdge;
	ee: longInt = 0;
	
procedure addEdge( u, v: longInt );
var	w: longInt;
begin
	w := min( a[u], a[v] );
	
	inc( ee );
	e[ee].u := u;
	e[ee].v := v;
	e[ee].next := first[w];
	first[w] := ee;
end;

function get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := get( p[v] );
	
	exit( p[v] );
end;

function join( u, v: longInt ): int64;
var	res: int64;
begin
	u := get(u);
	v := get(v);
	
	if ( u = v ) then
		exit( 0 );
		
	res := int64( sz[u] ) * sz[v];
	
	p[v] := u;
	inc( sz[u], sz[v] );
	
	exit( res );
end;

var	n, m, i, j, u, v: longInt;
	ans: int64;

begin
	fillchar( first, sizeOf(first), 0 );

	readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
	end;
	
	for i := 1 to n do
	begin
		p[i] := i;
		sz[i] := 1;
	end;
	
	ans := 0;
	for i := 100000 downto 0 do
	begin
		j := first[i];
		while ( j > 0 ) do
		begin
			inc( ans, join( e[j].u, e[j].v ) * i );
		
			j := e[j].next;
		end;
	end;
	
	writeln( ( 2 * ans / ( n * int64(n - 1) ) ):0:15 );
end.