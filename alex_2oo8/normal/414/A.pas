program problem1;

var	n, k, i, s: longInt;

begin
	readln( n, k );
	
	if ( n div 2 > k ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	if ( n = 1 ) then
	begin
		if ( k = 0 ) then
			writeln( 1 )
		else
			writeln( -1 );
		
		halt;
	end;
	
	s := 300000000;
	for i := 1 to (n div 2) - 1 do
	begin
		write( s, ' ', s + 1, ' ' );
		inc( s, 2 );
	end;
	
	dec( k, (n div 2) - 1 );
	
	write( k, ' ', 2 * k );
	
	if ( odd(n) ) then
		write( ' 1000000000' );
	
	writeln();
end.