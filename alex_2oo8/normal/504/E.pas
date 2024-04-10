program problem5;
uses math;

const	hash_base = 37;
		hash_mod = 1000000007;

type	tEdge =	record
					v, next: longInt;
				end;

var	c: ansistring;
	e: array[ 1..600000 ] of tEdge;
	first, dep: array[ 0..300000 ] of longInt;
	par, hash, inv_hash: array[ 0..300000, 0..18 ] of longInt;
	par64: array[ 0..300000, 0..3, 0..63 ] of longInt;
	hash_base_pow: array[ 0..300000 ] of int64;
	
procedure swap( var a, b: longInt );
var	c: longInt;
begin
	c := a;
	a := b;
	b := c;
end;
	
procedure addEdge( u, v: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure dfs( v, p: longInt );
var	i, j: longInt;
begin
	if ( p = 0 ) then
	begin
		dep[v] := 1;
		
		for j := 0 to 3 do
			par64[v][j][0] := v;
	end
	else
	begin
		dep[v] := dep[p] + 1;
		par[v][0] := p;
		hash[v][0] := ord( c[v] );
		inv_hash[v][0] := ord( c[p] );
		for i := 0 to 17 do
		begin
			par[v][i + 1] := par[ par[v][i] ][i];
			hash[v][i + 1] := ( hash[v][i] + hash_base_pow[1 shl i] * hash[ par[v][i] ][i] ) mod hash_mod;
			inv_hash[v][i + 1] := ( inv_hash[ par[v][i] ][i] + hash_base_pow[1 shl i] * inv_hash[v][i] ) mod hash_mod;
		end;
		
		for j := 0 to 3 do
		begin
			par64[v][j][0] := v;
			for i := 1 to 63 do
				par64[v][j][i] := par[ par64[v][j][i - 1] ][6 * j];
		end;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			dfs( e[i].v, v );
	
		i := e[i].next;
	end;
end;

function getParent( v, h: longInt ): longInt;
var	i: longInt;
begin
	for i := 0 to 3 do
	begin
		v := par64[v][i][ h and 63 ];
		h := h shr 6;
	end;
	
	exit( v );
end;

function lca( u, v: longInt ): longInt;
var	i: longInt;
begin
	if ( dep[v] > dep[u] ) then
		v := getParent( v, dep[v] - dep[u] );
	
	if ( dep[u] > dep[v] ) then
		u := getParent( u, dep[u] - dep[v] );
		
	if ( u = v ) then
		exit( u );
	
	for i := 18 downto 0 do
		if ( par[u][i] <> par[v][i] ) then
		begin
			u := par[u][i];
			v := par[v][i];
		end;
	
	exit( par[u][0] );
end;

function calcUpUp( u, v, h: longInt ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 18 downto 0 do
		if ( (1 shl i) <= h ) and ( hash[u][i] = hash[v][i] ) then
		begin
			dec( h, 1 shl i );
			inc( res, 1 shl i );
			u := par[u][i];
			v := par[v][i];
		end;
	
	exit( res );
end;

function calcUpDown( u, v, h: longInt ): longInt;
var	res, i: longInt;
begin
	res := 0;
	for i := 18 downto 0 do
		if ( (1 shl i) <= h ) and ( hash[u][i] = inv_hash[ getParent( v, h - (1 shl i) ) ][i] ) then
		begin
			dec( h, 1 shl i );
			inc( res, 1 shl i );
			u := par[u][i];
		end;
	
	exit( res );
end;

function calcDownDown( u, v, h: longInt ): longInt;
var	res, i: longInt;
begin
	res := 0;
	for i := 18 downto 0 do
		if ( (1 shl i) <= h ) and ( inv_hash[ getParent( u, h - (1 shl i) ) ][i] = inv_hash[ getParent( v, h - (1 shl i) ) ][i] ) then
		begin
			dec( h, 1 shl i );
			inc( res, 1 shl i );
		end;
	
	exit( res );
end;

function query( u, v, x, y: longInt ): longInt;
var	lca1, lca2, d, res, z, p: longInt;
begin
	lca1 := lca( u, v );
	lca2 := lca( x, y );
	
	d := min( dep[u] - dep[lca1], dep[x] - dep[lca2] );
	
	res := calcUpUp( u, x, d );

	if ( res < d ) then
		exit( res );
	
	u := getParent( u, d );
	x := getParent( x, d );
		
	if ( x <> lca2 ) then
	begin
		swap( u, x );
		swap( v, y );
		swap( lca1, lca2 );
	end;
	
	d := dep[u] - dep[lca1];
	
	if ( dep[y] - dep[x] < d ) then
	begin
		v := getParent( u, dep[y] - dep[x] );
		lca1 := v;
		d := dep[y] - dep[x];
	end;
	
	z := getParent( y, dep[y] - dep[x] - d );
	
	p := calcUpDown( u, z, d );
	inc( res, p );
	
	if ( p < d ) then
		exit( res );
	
	u := lca1;
	x := z;
	
	if ( dep[v] - dep[u] < dep[y] - dep[x] ) then
		y := getParent( y, ( dep[y] - dep[x] ) - ( dep[v] - dep[u] ) );
	
	if ( dep[y] - dep[x] < dep[v] - dep[u] ) then
		v := getParent( v, ( dep[v] - dep[u] ) - ( dep[y] - dep[x] ) );
	
	p := calcDownDown( v, y, dep[v] - dep[u] );
	inc( res, p );
	
	if ( p < dep[v] - dep[u] ) then
		exit( res );
	
	if ( c[v] = c[y] ) then
		inc( res );
	
	exit( res );
end;

var	n, m, i, u, v, x, y: longInt;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	fillchar( first, sizeOf(first), 0 );

	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );

	hash_base_pow[0] := 1;
	for i := 1 to 300000 do
		hash_base_pow[i] := ( hash_base_pow[i - 1] * hash_base ) mod hash_mod;

	readln( n );
	readln( c );
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	dfs( 1, 0 );
	
	readln( m );
	for i := 1 to m do
	begin
		readln( u, v, x, y );
		
		writeln( query( u, v, x, y ) );
	end;
end.