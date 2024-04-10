program peoblem4;

type	tPair =	record
					g: longInt;
					cnt: int64;
				end;
				
var	a: array[ 1..10000000 ] of tPair;
	gcd_rmq: array[ 1..100000, 0..20 ] of longInt;
	max2pow: array[ 1..100000 ] of longInt;
	
function gcd( a, b: longInt ): longInt;
var	c: longInt;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;
	
	exit( a );
end;

function getGcd( l, r: longInt ): longInt;
var	p: longInt;
begin
	p := max2pow[r - l + 1];
	
	exit( gcd( gcd_rmq[l][p], gcd_rmq[ r - (1 shl p) + 1 ][p] ) );
end;

procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tPair;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ].g;
		
		while ( i <= j ) do
		begin
			while ( a[i].g < med ) do
				inc( i );
			while ( a[j].g > med ) do
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

var	n, m, i, j, l, r, c, g, ll, x: longInt;

begin
	max2pow[1] := 0;
	for i := 2 to 100000 do
	begin
		max2pow[i] := max2pow[i - 1];
		
		if ( i = 2 shl max2pow[i] ) then
			inc( max2pow[i] );
	end;

	readln( n );
	for i := 1 to n do
		read( gcd_rmq[i][0] );
	
	for j := 0 to 19 do
		for i := 1 to n - (2 shl j) + 1 do
			gcd_rmq[i][j + 1] := gcd( gcd_rmq[i][j], gcd_rmq[ i + (1 shl j) ][j] );
	
	m := 0;
	for i := 1 to n do
	begin
		r := i - 1;
		while ( r < n ) do
		begin
			g := getGcd( i, r + 1 );
			
			ll := r + 1;
			l := r + 1;
			r := n;
			while ( l < r ) do
			begin
				c := ( l + r + 1 ) div 2;
				
				if ( getGcd( i, c ) = g ) then
					l := c
				else
					r := c - 1;
			end;
			
			inc( m );
			a[m].g := g;
			a[m].cnt := r - ll + 1;
		end;
	end;
	
	qsort( 1, m );
	
	n := 1;
	for i := 2 to m do
		if ( a[i].g = a[n].g ) then
			inc( a[n].cnt, a[i].cnt )
		else
		begin
			inc( n );
			a[n] := a[i];
		end;
		
	readln( m );
	for i := 1 to m do
	begin
		readln( x );
		
		l := 1;
		r := n;
		while ( l < r ) do
		begin
			c := ( l + r ) div 2;
			
			if ( a[c].g < x ) then
				l := c + 1
			else
				r := c;
		end;
		
		if ( a[l].g = x ) then
			writeln( a[l].cnt )
		else
			writeln( 0 );
	end;
end.