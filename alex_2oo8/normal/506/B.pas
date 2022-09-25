program problem2;

type	tEdge =	record
					v, next: longInt;
				end;

var	p, first, vis: array[ 1..100000 ] of longInt;
	onCycle: array[ 1..100000 ] of boolean;
	e: array[ 1..100000 ] of tEdge;

function dsu_get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := dsu_get( p[v] );
	
	exit( p[v] );
end;

procedure dsu_merge( u, v: longInt );
begin
	p[ dsu_get( v ) ] := dsu_get( u );
end;

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
	if ( vis[v] = 2 ) then
		exit();
	
	if ( vis[v] = 1 ) then
	begin
		onCycle[v] := true;
		exit();
	end;
	
	vis[v] := 1;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		dfs( e[i].v );
		
		i := e[i].next;
	end;
	
	vis[v] := 2;
end;

var	n, m, i, u, v, ans: longInt;
	compSz: array[ 1..100000 ] of longInt;
	hasCycle: array[ 1..100000 ] of boolean;

begin
	fillchar( vis, sizeOf(vis), 0 );

	readln( n, m );
	for i := 1 to n do
		p[i] := i;
	
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
		
		dsu_merge( u, v );
	end;
	
	for i := 1 to n do
		if ( vis[i] = 0 ) then
			dfs( i );
	
	for i := 1 to n do
	begin
		inc( compSz[ dsu_get(i) ] );
		hasCycle[ dsu_get(i) ] := hasCycle[ dsu_get(i) ] or onCycle[i];
	end;
	
	ans := n;
	for i := 1 to n do
		if ( dsu_get( i ) = i ) and ( not hasCycle[i] ) then
			dec( ans );
	
	writeln( ans );
end.