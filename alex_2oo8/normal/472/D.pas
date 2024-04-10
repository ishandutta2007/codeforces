program problem4;

type	tEdge =	record
					u, v, w, next: longInt;
				end;

var	a: array[ 1..4000000 ] of tEdge;
	p, first: array[ 1..2000 ] of longInt;
	d: array[ 1..2000, 1..2000 ] of int64;
	e: array[ 1..1000000 ] of tEdge;
	ee: longInt = 0;
	
procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tEdge;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ].w;
		while ( i <= j ) do
		begin
			while ( a[i].w < med ) do
				inc( i );
			while ( a[j].w > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := a[i];
				a[i] := a[j];
				a[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

procedure addEdge( u, v, w: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].w := w;
	e[ee].next := first[u];
	first[u] := ee;
end;

function get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := get( p[v] );
	
	exit( p[v] );
end;

procedure merge( u, v: longInt );
begin
	u := get( u );
	v := get( v );
	
	if ( u <> v ) then
		p[u] := v;
end;

procedure DFS( v, p, s: longInt; dd: int64 );
var	i: longInt;
begin
	d[s][v] := dd;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v, s, dd + e[i].w );
	
		i := e[i].next;
	end;
end;

var	n, i, j, k: longInt;
	bufIn: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn, sizeOf(bufIn) );
	
	readln( n );
	
	k := 0;
	for i := 1 to n do
		for j := 1 to n do
		begin
			inc( k );
			read( a[k].w );
			
			a[k].u := i;
			a[k].v := j;
		end;
	
	qsort( 1, k );
	
	for i := 1 to n do
		p[i] := i;
	
	for i := 1 to k do
		if ( a[i].w > 0 ) and ( get( a[i].u ) <> get( a[i].v ) ) then
		begin
			merge( a[i].u, a[i].v );
			
			addEdge( a[i].u, a[i].v, a[i].w );
			addEdge( a[i].v, a[i].u, a[i].w );
		end;
	
	for i := 1 to n do
		if ( get(i) <> get(1) ) then
		begin
			writeln( 'NO' );
			halt;
		end;
	
	for i := 1 to n do
		DFS( i, 0, i, 0 );
	
	for i := 1 to k do
		if ( d[ a[i].u ][ a[i].v ] <> a[i].w ) then
		begin
			writeln( 'NO' );
			halt;
		end;
		
	writeln( 'YES' );
end.