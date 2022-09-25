program problem1;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	first, visited: array[ 1..1000 ] of longInt;
	e: array[ 1..100000 ] of tEdge;
	
procedure DFS( v: longInt );
var	i: longInt;
begin
	if ( visited[v] = 1 ) then
		exit();
		
	visited[v] := 1;
	i := first[v];
	while ( i > 0 ) do
	begin
		DFS( e[i].v );
		
		i := e[i].next;
	end;
end;

var	n, m, i, j, k, ee, a, ans: longInt;

begin
	readln( n, m );
	ee := 0;
	ans := 0;
	for i := 1 to n do
	begin
		read( k );
		for j := 1 to k do
		begin
			read( a );
			
			inc( ee );
			e[ee].v := a + n;
			e[ee].next := first[i];
			first[i] := ee;
			
			inc( ee );
			e[ee].v := i;
			e[ee].next := first[a+n];
			first[a+n] := ee;
		end;
		readln();
		
		if ( k > 0 ) then
			ans := -1;
	end;
	
	for i := 1 to n do
		if ( visited[i] = 0 ) then
		begin
			inc( ans );
			DFS( i );
		end;
		
	writeln( ans );
end.