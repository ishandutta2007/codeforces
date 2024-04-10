program problem5;
uses math;

type	tEdge =	record
					v, c, next: longInt;
				end;

var	first, x: array[ 1..3000 ] of longInt;
	e: array[ 1..10000 ] of tEdge;
	ee: longInt;

procedure addEdge( u, v, c: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].c := c;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure findMaxEdge( v, par: longInt; var l, r, c: longInt );
var	i: longInt;
begin
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].c > c ) then
		begin
			l := v;
			r := e[i].v;
			c := e[i].c;
		end;
		
		if ( e[i].v <> par ) then
			findMaxEdge( e[i].v, v, l, r, c );
		
		i := e[i].next;
	end;
end;

procedure deleteEdge( u, v: longInt );
var	i: longInt;
begin
	if ( e[ first[u] ].v = v ) then
		first[u] := e[ first[u] ].next
	else
	begin
		i := first[u];
		while ( e[ e[i].next ].v <> v ) do
			i := e[i].next;
		
		e[i].next := e[ e[i].next ].next;
	end;
end;

procedure dfs( v, par: longInt; var sz: longInt; var sum: int64 );
var	i, ssz: longInt;
	ssum: int64;
begin
	sz := 1;
	sum := x[v];
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) then
		begin
			dfs( e[i].v, v, ssz, ssum );
			
			inc( sz, ssz );
			inc( sum, ssum );
		end;
	
		i := e[i].next;
	end;
end;

function solve( v, q: longInt ): longInt;
var	l, r, c, nl, nr: longInt;
	sl, sr: int64;
begin
	c := 0;
	findMaxEdge( v, 0, l, r, c );
	
	if ( c = 0 ) then
		exit( 0 );
	
	deleteEdge( l, r );
	deleteEdge( r, l );
	
	dfs( l, 0, nl, sl );
	dfs( r, 0, nr, sr );
	
	if ( min(nl, sr) + min(nr, sl) >= q ) then
		exit( c );
	
	if ( sl >= nr ) then
		exit( solve( l, q - nr - sr ) )
	else
		exit( solve( r, q - nl - sl ) );
end;

var	n, i, u, v, c: longInt;

begin
	readln( n );

	for i := 1 to n - 1 do
	begin
		readln( u, v, c );
		
		addEdge( u, v, c );
		addEdge( v, u, c );
	end;
	
	for i := 1 to n do
		read( x[i] );
	
	writeln( solve( 1, n ) );
end.