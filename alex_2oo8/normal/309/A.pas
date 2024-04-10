program problem1;

var	a: array[ 1..2000000 ] of int64;

function findLast( l, r: longInt; x: int64 ): longInt;
var	c: longInt;
begin
	if ( a[l] > x ) then
		exit( l - 1 );
		
	while ( l < r ) do
	begin
		c := l + ( (r-l+1) div 2 );
		
		if ( a[c] > x ) then
			r := c - 1
		else
			l := c;
	end;
	
	exit( l );
end;

var	n, i: longInt;
	l, t: int64;
	ans: extended;

begin
	readln( n, l, t );
	for i := 1 to n do
		read( a[i] );
		
	for i := (n+1) to (n+n) do
		a[i] := a[i-n] + l;
		
	ans := ( t div l ) * ( n * 1.0 * (n-1) ) * 2;
	t := t mod l;
	
	if ( 2 * t >= l ) then
	begin
		ans := ans + ( n * 1.0 * (n-1) );
		
		dec( t, l div 2 );
	end;

	for i := 1 to n do
		ans := ans + ( findLast( i + 1, 2 * n, a[i] + 2 * t ) - i );

	writeln( ( ans / 4 ):0:15 );
end.