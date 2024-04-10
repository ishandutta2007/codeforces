program problem1;

var	s: ansistring;

begin
	readln( s );
	
	if ( pos( '0', s ) > 0 ) then
		delete( s, pos( '0', s ), 1 )
	else
		delete( s, 1, 1 );
		
	writeln( s );
end.