program problem5;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;

var	first, f, g, leafCnt: array[ 1..200000 ] of longInt;
	e: array[ 1..400000 ] of tEdge;

procedure addEdge( u, v: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure dfs( v: longInt );
var	i: longInt;
begin
	f[v] := 1;
	g[v] := 1;
	leafCnt[v] := 0;
	if ( first[v] = 0 ) then
	begin
		leafCnt[v] := 1;
		
		exit();
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		dfs( e[i].v );
		
		inc( leafCnt[v], leafCnt[ e[i].v ] );
		
		i := e[i].next;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		inc( f[v], g[ e[i].v ] - 1 );
		g[v] := max( g[v], leafCnt[v] + f[ e[i].v ] - leafCnt[ e[i].v ] );
		
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
	end;
	
	dfs( 1 );
	
	writeln( g[1], ' ', leafCnt[1] + 1 - f[1] );
end.