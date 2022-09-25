program problem1;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	first, a, b, ans: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	ee, cnt: longInt;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure DFS( v, p, x, y: longInt );
var	i: longInt;
begin
	a[v] := a[v] xor x;
	
	if ( a[v] <> b[v] ) then
	begin
		inc( cnt );
		ans[cnt] := v;
		
		x := x xor 1;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v, y, x );
	
		i := e[i].next;
	end;
end;

var	n, i, u, v: longInt;

begin
	readln( n );
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
		read( b[i] );
	
	DFS( 1, 0, 0, 0 );
	
	writeln( cnt );
	for i := 1 to cnt do
		writeln( ans[i] );
end.