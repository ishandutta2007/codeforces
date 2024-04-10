program problem2;
uses math;

type	tTreeNode =	record
						l, r, lSon, rSon, mx: longInt;
					end;

var	x, w: array[ 1..500000 ] of longInt;
	t: array[ 1..10000000 ] of tTreeNode;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := x[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( x[i] < med ) do
				inc( i );
			while ( x[j] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := x[i];
				x[i] := x[j];
				x[j] := t;
				
				t := w[i];
				w[i] := w[j];
				w[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
begin
	inc( tw );
	
	t[tw].l := l;
	t[tw].r := r;
	t[tw].mx := 0;
	
	exit( tw );
end;

procedure update( v, x, val: longInt );
var	c: longInt;
begin
	t[v].mx := max( t[v].mx, val );
	if ( t[v].l = t[v].r ) then
		exit();
	
	c := ( int64( t[v].l ) + t[v].r ) div 2;
	if ( x <= c ) then
	begin
		if ( t[v].lSon = 0 ) then
			t[v].lSon := build_tree( t[v].l, c );
		
		update( t[v].lSon, x, val );
	end
	else
	begin
		if ( t[v].rSon = 0 ) then
			t[v].rSon := build_tree( c + 1, t[v].r );
		
		update( t[v].rSon, x, val );
	end;
end;

function getMax( v, x: longInt ): longInt;
begin
	if ( v = 0 ) or ( t[v].l > x ) then
		exit( 0 );
	
	if ( t[v].r <= x ) then
		exit( t[v].mx );
	
	exit( max( getMax( t[v].lSon, x ), getMax( t[v].rSon, x ) ) );
end;

var	n, i: longInt;

begin
	readln( n );
	for i := 1 to n do
		readln( x[i], w[i] );
	
	qsort( 1, n );
	
	build_tree( 1, 2000000000 );
	
	for i := 1 to n do
		update( 1, x[i] + w[i], getMax( 1, x[i] - w[i] ) + 1 );
	
	writeln( getMax( 1, 2000000000 ) );
end.