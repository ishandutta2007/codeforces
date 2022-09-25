program problem2;

const	md =	1000000007;

type	tEdge =	record
					v, w, next: longInt;
				end;

var	first, p, up, down, vis: array[ 0..100000 ] of longInt;
	e: array[ 1..3000000 ] of tEdge;

function pow( a, p: longInt ): longInt;
var	r: longInt;
begin
	r := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			r := ( r * int64(a) ) mod md;
		
		a := ( a * int64(a) ) mod md;
		p := p div 2;
	end;
	
	exit( r );
end;

procedure addEdge( u, v, w: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].w := w;
	e[ee].next := first[u];
	first[u] := ee;
end;

function dsu_get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := dsu_get( p[v] );
	
	exit( p[v] );
end;

procedure dsu_merge( u, v: longInt );
begin
	p[ dsu_get( u ) ] := dsu_get( v );
end;

function dfs( v, par: longInt ): longInt;
var	i, lca, res: longInt;
begin
	res := 0;

	vis[v] := 1;

	i := first[v];
	while ( i > 0 ) do
	begin
		if ( abs( e[i].w ) = 42 ) then
		begin
			if ( e[i].w = 42 ) then
				inc( up[v] )
			else
				inc( down[v] );
			
			if ( vis[ e[i].v ] = 1 ) then
			begin
				lca := dsu_get( e[i].v );
				
				dec( up[lca] );
				dec( down[lca] );
			end;
		end;
	
		i := e[i].next;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( abs( e[i].w ) <> 42 ) and ( e[i].v <> par ) then
		begin
			res := ( res + dfs( e[i].v, v ) ) mod md; 
			
			inc( up[v], up[ e[i].v ] );
			inc( down[v], down[ e[i].v ] );
			
			dsu_merge( e[i].v, v );
			
			if ( e[i].w = 1 ) then
				res := ( res + pow( 2, up[ e[i].v ] ) - 1 ) mod md;
			
			if ( e[i].w = -1 ) then
				res := ( res + pow( 2, down[ e[i].v ] ) - 1 ) mod md;
		end;
	
		i := e[i].next;
	end;
	
//	writeln( v, ' ', up[v], ' ', down[v] );
	
	exit( res );
end;

var	n, k, i, u, v, w: longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		p[i] := i;
		up[i] := 0;
		down[i] := 0;
		vis[i] := 0;
	end;
	
	for i := 2 to n do
	begin
		readln( u, v, w );
		
		addEdge( u, v, w );
		addEdge( v, u, -w );
	end;
	
	v := 1;
	readln( k );
	for i := 1 to k do
	begin
		u := v;
		read( v );
		
		if ( u <> v ) then
		begin
			addEdge( u, v, 42 );
			addEdge( v, u, -42 );
		end;
	end;
	
	writeln( dfs( 1, 0 ) );
end.