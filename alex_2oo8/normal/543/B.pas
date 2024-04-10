program problem1;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;

var	dist: array[ 1..3000, 1..3000 ] of longInt;
	first, s: array[ 1..3000 ] of longInt;
	e: array[ 1..10000 ] of tEdge;
	n: longInt;
	
procedure addEdge( u, v: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure bfs( start: longInt );
var	l, r, i: longInt;
begin
	for i := 1 to n do
		dist[start][i] := 1000000;

	l := 1;
	r := 2;
	s[1] := start;
	dist[start][start] := 0;
	while ( l < r ) do
	begin
		i := first[ s[l] ];
		while ( i > 0 ) do
		begin
			if ( dist[start][ e[i].v ] = 1000000 ) then
			begin
				dist[start][ e[i].v ] := dist[start][ s[l] ] + 1;
				
				s[r] := e[i].v;
				inc( r );
			end;
		
			i := e[i].next;
		end;
		
		inc( l );
	end;
end;

var	m, i, j, u, v, s1, t1, l1, s2, t2, l2, d1, d2, ans: longInt;

begin
	readln( n, m );
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	for i := 1 to n do
		bfs( i );
	
	readln( s1, t1, l1, s2, t2, l2 );
	
	if ( dist[s1][t1] > l1 ) or ( dist[s2][t2] > l2 ) then
	begin
		writeln( -1 );
		
		halt;
	end;
	
	ans := m - dist[s1][t1] - dist[s2][t2];
	for i := 1 to n do
		for j := i to n do
		begin
			d1 := min( dist[s1][i] + dist[j][t1], dist[s1][j] + dist[i][t1] );
			d2 := min( dist[s2][i] + dist[j][t2], dist[s2][j] + dist[i][t2] );
			
			if ( d1 + dist[i][j] <= l1 ) and ( d2 + dist[i][j] <= l2 ) then
				ans := max( ans, m - dist[i][j] - d1 - d2 );
		end;
	
	writeln( ans );
end.