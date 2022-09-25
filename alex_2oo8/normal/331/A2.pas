program problem1;

type	tTreeRec =	record
						l, r, lSon, rSon: longInt;
						sum: int64;
					end;

var	a, x: array[ 1..300000 ] of longInt;
	m, tw: longInt;
	t: array[ 1..1000000 ] of tTreeRec;
	
procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := x[ l + random(r-l+1) ];
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
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function find( y: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := m;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( x[c] < y ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

function new( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	t[res].sum := 0;
	
	if ( l = r ) then
	begin
		t[res].lSon := 0;
		t[res].rSon := 0;
	end
	else
	begin
		t[res].lSon := new( l, ( l + r ) div 2 );
		t[res].rSon := new( ( l + r ) div 2 + 1, r );
	end;
	
	exit( res );
end;

procedure t_update( s, p, val: longInt );
begin
	if ( t[s].l = t[s].r ) then
	begin
		t[s].sum := val;
		exit();
	end;
	
	if ( p <= t[ t[s].lSon ].r ) then
		t_update( t[s].lSon, p, val )
	else
		t_update( t[s].rSon, p, val );
		
	t[s].sum := t[ t[s].lSon ].sum + t[ t[s].rSon ].sum;
end;

function t_read( s, l, r: longInt ): int64;
var res: int64;
begin
	if ( l > r ) then
		exit( 0 );

	if ( t[s].l >= l ) and ( t[s].r <= r ) then
		exit( t[s].sum );
		
	res := 0;
	if ( t[ t[s].lSon ].r >= l ) then
		inc( res, t_read( t[s].lSon, l, r ) );
		
	if ( t[ t[s].rSon ].l <= r ) then
		inc( res, t_read( t[s].rSon, l, r ) );
		
	exit( res );
end;

var	n, i, k, ansL, ansR: longInt;
	last: array[ 1..300000 ] of longInt;
	ansSum: int64;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to n do
		x[i] := a[i];
		
	qsort( 1, n );
	
	m := 1;
	for i := 2 to n do
		if ( x[i] <> x[m] ) then
		begin
			inc( m );
			x[m] := x[i];
		end;
	
	for i := 1 to n do
		a[i] := find( a[i] );
		
	new( 1, n );
	for i := 1 to n do
		if ( x[ a[i] ] > 0 ) then
			t_update( 1, i, x[ a[i] ] );
			
	for i := 1 to n do
		last[ a[i] ] := i;
		
	ansSum := -10000000000000000;
	for i := 1 to n do
		if ( last[ a[i] ] > i ) and ( t_read( 1, i + 1, last[ a[i] ] - 1 ) + 2 * x[ a[i] ] > ansSum ) then
		begin
			ansSum := t_read( 1, i + 1, last[ a[i] ] - 1 ) + 2 * x[ a[i] ];
			ansL := i;
			ansR := last[ a[i] ];
		end;
		
	k := ansL - 1 + ( n - ansR );
	for i := ansL + 1 to ansR - 1 do
		if ( x[ a[i] ] < 0 ) then
			inc( k );
		
	writeln( ansSum, ' ', k );
	for i := 1 to ansL - 1 do
		write( i, ' ' );
		
	for i := ansL + 1 to ansR - 1 do
		if ( x[ a[i] ] < 0 ) then
			write( i, ' ' );
			
	for i := ansR + 1 to n do
		write( i, ' ' );
		
	writeln();
end.