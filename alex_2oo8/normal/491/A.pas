program problem1;

var	n, m, i: longInt;

begin
	readln( n, m );
	
	for i := 1 to n + 1 do
		write( m + i, ' ' );
	
	for i := 1 to m do
		write( m + 1 - i, ' ' );
	
	writeln();
end.