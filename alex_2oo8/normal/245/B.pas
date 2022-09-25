program problem2;

var str: ansistring;
	x: longInt;

begin
	readln( str );
	if ( str[1] = 'h' ) then
	begin
		write( 'http://' );
		delete( str, 1, 4 );
	end
	else
	begin
		write( 'ftp://' );
		delete( str, 1, 3 );
	end;
	
	x := pos( 'ru', str );
	if ( x = 1 ) then
	begin
		delete( str, 1, 2 );
		write( 'ru' );
		x := pos( 'ru', str );
	end;
	
	write( copy( str, 1, (x-1) ) );
	delete( str, 1, (x+1) );
	write( '.ru' );
	if ( length(str) > 0 ) then
		write( '/', str );
		
	writeln();
end.