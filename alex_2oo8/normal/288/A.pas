program problem1;

var	n, i, j, k: longInt;

begin
	readln( n, k );
	if ( k > n ) or ( ( k = 1 ) and ( n > 1 ) ) then
		writeln( -1 )
	else if ( n = 1 ) then
		writeln( 'a' )
	else
	begin
		for i := 1 to ( n - k + 2 ) do
			if ( odd(i) ) then
				write( 'a' )
			else
				write( 'b' );
			
		for i := 3 to k do
			write( chr( ord( 'a' ) + i - 1 ) );
		
		writeln();
	end;
end.