program problem3;
uses math;

var	n: longInt;
	a: array[ 1..200000 ] of longInt;

function f( x: extended ): extended;
var	i: longInt;
	sum, minSum, maxSum, res: extended;
begin
	sum := 0;
	minSum := 0;
	maxSum := 0;
	res := 0;
	for i := 1 to n do
	begin
		sum := sum + a[i] - x;
		minSum := min( minSum, sum );
		maxSum := max( maxSum, sum );
		
		res := max( res, max( abs( sum - minSum ), abs( sum - maxSum ) ) );
	end;
	
	exit( res );
end;

var	i: longInt;
	l, r, m1, m2: extended;
	
begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	l := -1.0e+5;
	r := 1.0e+5;
	for i := 1 to 100 do
	begin
		m1 := l + (r - l) / 3;
		m2 := r - (r - l) / 3;
		
		if ( f( m1 ) < f( m2 ) ) then
			r := m2
		else
			l := m1;
	end;
	
	writeln( f( (l + r) / 2 ):0:12 );
end.