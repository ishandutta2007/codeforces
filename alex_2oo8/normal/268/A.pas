program problem1;

var	n, i, j, ans: longInt;
	a, b: array[ 1..50 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		readln( a[i], b[i] );
		
	ans := 0;
	for i := 1 to n do
		for j := 1 to n do
			if ( a[i] = b[j] ) then
				inc( ans );
				
	writeln( ans );
end.