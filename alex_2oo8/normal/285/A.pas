program problem1;

var	n, k, i: longInt;

begin
	readln( n, k );
	inc( k );
	for i := 1 to k do
		write( k - i + 1, ' ' );
		
	for i := (k+1) to n do
		write( i, ' ' );
		
	writeln();
end.