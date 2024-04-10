program problem1;

var	n, k, i: longInt;

begin
	readln( n, k );
	
	for i := 1 to n - k - 1 do
		write( i, ' ' );
	
	for i := 1 to k + 1 do
		if ( odd(i) ) then
			write( n - k - 1 + (i + 1) div 2, ' ' )
		else
			write( n + 1 - (i div 2), ' ' );
		
	writeln();
end.