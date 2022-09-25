program problem1;

var	n, m: longInt;

begin
	readln( n, m );
	
	if ( n > m ) then
		writeln( 'First' )
	else
		writeln( 'Second' );
end.