program problem3;
uses math;

var	n, x, i, j, k: longInt;
	a: array[ 1..100000 ] of int64;

begin
	readln( n, x );
	for i := 1 to n do
		read( a[i] );
		
	for i := (x+1) to n do
		inc( a[i] );
		
	j := 1;
	for i := 2 to n do
		if ( a[i] <= a[j] ) then
			j := i;
			
	k := a[j];
	for i := 1 to n do
		dec( a[i], k );
		
	a[j] := ( n * int64(k) ) - ( n - x );
	for i := (j+1) to n do
	begin
		dec( a[i] );
		inc( a[j] );
	end;
		
	for i := 1 to n do
		write( a[i], ' ' );
end.