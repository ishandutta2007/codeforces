program problem2;

const	md =	1000000007;

type	tEdge =	record
				v, next: longInt;
			end;

var	x, f, g, first: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	ee: longInt = 0;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

function pow( a, p: int64 ): int64;
var	res: int64;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * a ) mod md;
			
		a := ( a * a ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

function getF( v, q: longInt ): longInt;
var	i, prod: longInt;
begin
	if ( q = 1 ) and ( f[v] <> -1 ) then
		exit( f[v] );
	
	if ( q = 0 ) and ( g[v] <> -1 ) then
		exit( g[v] );

	prod := 1;
	i := first[v];
	while ( i > 0 ) do
	begin
		prod := ( prod * int64( getF(e[i].v, 0) + getF(e[i].v, 1) ) ) mod md;
	
		i := e[i].next;
	end;
	
	if ( q = 0 ) then
	begin
		if ( x[v] = 1 ) then
			g[v] := 0
		else
			g[v] := prod;
		
		exit( g[v] );
	end
	else
	begin
		if ( x[v] = 1 ) then
			f[v] := prod
		else
		begin
			f[v] := 0;
			
			i := first[v];
			while ( i > 0 ) do
			begin
				f[v] := ( f[v] + getF(e[i].v, 1) * ( ( prod * pow(getF(e[i].v, 0) + getF(e[i].v, 1), md - 2) ) mod md ) ) mod md;
			
				i := e[i].next;
			end;
		end;
		
		exit( f[v] );
	end;
end;

var	n, i, p: longInt;

begin
	readln( n );
	f[1] := -1;
	g[1] := -1;
	for i := 2 to n do
	begin
		read( p );
		
		addEdge( p + 1, i );
		
		f[i] := -1;
		g[i] := -1;
	end;
	
	for i := 1 to n do
		read( x[i] );
	
	writeln( getF(1, 1) );
end.