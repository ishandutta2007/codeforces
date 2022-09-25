program problem2;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	e: array[ 1..200000 ] of tEdge;
	first, firstMaxDown, SecondMaxDown, maxUp: array[ 1..100000 ] of longInt;
	marked: array[ 1..100000 ] of boolean;
	ee, d, ans: longInt;
	
procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

function initDFS( v, p: longInt ): longInt;
var	i, q: longInt;
begin
	firstMaxDown[v] := -1000000000;
	secondMaxDown[v] := -1000000000;
	
	if ( marked[v] ) then
		firstMaxDown[v] := 0;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
		begin
			q := initDFS( e[i].v, v ) + 1;
			
			if ( q > firstMaxDown[v] ) then
			begin
				secondMaxDown[v] := firstMaxDown[v];
				firstMaxDown[v] := q;
			end
			else if ( q > secondMaxDown[v] ) then
				secondMaxDown[v] := q;
		end;
		
		i := e[i].next;
	end;
	
	exit( firstMaxDown[v] );
end;

procedure DFS( v, p: longInt );
var	i: longInt;
begin
	if ( p = 0 ) then
		maxUp[v] := -1000000000
	else
	begin
		if ( firstMaxDown[v] + 1 = firstMaxDown[p] ) then
			maxUp[v] := max( secondMaxDown[p], maxUp[p] ) + 1
		else
			maxUp[v] := max( firstMaxDown[p], maxUp[p] ) + 1;
	end;
	
//	writeln( v, ': maxDown = ', firstMaxDown[v]:10, ' maxUp = ', maxUp[v]:10, ' secondMaxDown = ', secondMaxDown[v]:10, ' ', p );
	
	if ( max( firstMaxDown[v], maxUp[v] ) <= d ) then
		inc( ans );
		
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v );
			
		i := e[i].next;
	end;
end;

var	n, m, i, u, v: longInt;

begin
	fillchar( marked, sizeOf(marked), false );

	readln( n, m, d );
	for i := 1 to m do
	begin
		read( v );
		
		marked[v] := true;
	end;
	
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	ans := 0;
	
	initDFS( 1, 0 );
	DFS( 1, 0 );
	
	writeln( ans );
end.