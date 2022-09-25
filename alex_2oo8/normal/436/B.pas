program problem2;

var	n, m, i, j: longInt;
	ans: array[ 1..2000 ] of longInt;
	buf: array[ 1..1 shl 16 ] of byte;
	c: char;

begin
	setTextBuf( input, buf );

	fillchar( ans, sizeOf(ans), 0 );

	readln( n, m, i );
	for i := 1 to n do
	begin
		for j := 1 to m do
		begin
			read( c );
			
			if ( c = 'U' ) and ( odd(i) ) then
				inc( ans[j] )
			else if ( c = 'L' ) and ( j - i + 1 > 0 ) then
				inc( ans[j - i + 1] )
			else if ( c = 'R' ) and ( j + i - 1 <= m ) then
				inc( ans[j + i - 1] );
		end;
		
		readln();
	end;
	
	for i := 1 to m do
		write( ans[i], ' ' );
	writeln();
end.