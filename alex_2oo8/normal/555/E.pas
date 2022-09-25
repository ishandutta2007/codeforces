program problem5;
uses math;

type	tEdge =	record
					v, w, next: longInt;
				end;
		tArr =	array[ 1..200000 ] of longInt;

var	firstQuery, first, f, g, depth, minUp, dsu, p, comp: tArr;
	e: array[ 1..1000000 ] of tEdge;
	ee: longInt = 0;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure addQuery( u, v, w: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].w:= w;
	e[ee].next := firstQuery[u];
	firstQuery[u] := ee;
end;
	
function dsu_get( var p: tArr; v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := dsu_get( p, p[v] );
	
	exit( p[v] );
end;

procedure dsu_merge( var p: tArr; u, v: longInt );
begin
	p[ dsu_get( p, u ) ] := dsu_get( p, v );
end;
	
function dfs1( v, par, dep: longInt ): longInt;
var	i, cntToPar: longInt;
begin
	dsu[v] := v;

	depth[v] := dep;
	minUp[v] := dep;
	
	cntToPar := 0;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) then
		begin
			e[i].w := depth[ e[i].v ];
			if ( depth[ e[i].v ] = 0 ) then
				minUp[v] := min( minUp[v], dfs1( e[i].v, v, dep + 1 ) )
			else
				minUp[v] := min( minUp[v], depth[ e[i].v ] );
		end
		else
			inc( cntToPar );
	
		i := e[i].next;
	end;
	
	if ( cntToPar > 1 ) then
		minUp[v] := min( minUp[v], dep - 1 );
	
	exit( minUp[v] );
end;

procedure dfs2( v, par: longInt );
var	i, lca: longInt;
begin
	if ( minUp[v] = depth[v] ) then
		comp[v] := v
	else
		comp[v] := comp[par];
	
	i := firstQuery[v];
	while ( i > 0 ) do
	begin
		if ( comp[ e[i].v ] > 0 ) then
		begin
			lca := comp[ dsu_get( dsu, e[i].v ) ];
			
			if ( e[i].w = 1 ) then
			begin
				inc( f[ comp[v] ] );
				inc( g[ comp[ e[i].v ] ] );
			end
			else
			begin
				inc( g[ comp[v] ] );
				inc( f[ comp[ e[i].v ] ] );
			end;
			
			dec( f[lca] );
			dec( g[lca] );
		end;
		
		i := e[i].next;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) and ( e[i].w = 0 ) then
		begin
			dfs2( e[i].v, v );
			
			dsu_merge( dsu, e[i].v, v );
		end;
		
		i := e[i].next;
	end;
end;

procedure dfs3( v, par: longInt );
var	i: longInt;
begin
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) and ( e[i].w = 0 )	then
		begin
			dfs3( e[i].v, v );
			
			inc( f[v], f[ e[i].v ] );
			inc( g[v], g[ e[i].v ] );
		end;
	
		i := e[i].next;
	end;
	
	if ( comp[v] = v ) and ( f[v] > 0 ) and ( g[v] > 0 ) then
	begin
		writeln( 'No' );
		
		halt;
	end;
end;

procedure solve( v: longInt );
begin
	dfs1( v, 0, 1 );
	dfs2( v, 0 );
	dfs3( v, 0 );
end;

var	n, m, i, u, v, q: longInt;

begin
	readln( n, m, q );
	for i := 1 to n do
		p[i] := i;
	
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
		
		dsu_merge( p, u, v );
	end;
	
	for i := 1 to q do
	begin
		readln( u, v );
		
		if ( dsu_get( p, u ) <> dsu_get( p, v ) ) then
		begin
			writeln( 'No' );
			
			halt;
		end;
		
		addQuery( u, v, 1 );
		addQuery( v, u, 0 );
	end;
	
	for i := 1 to n do
		if ( dsu_get( p, i ) = i ) then
			solve( i );
	
	writeln( 'Yes' );
end.