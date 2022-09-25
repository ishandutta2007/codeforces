program peoblem1;

var	n, m: longInt;
	s, t: string;

begin
	readln( n, m );
	readln( s );
	readln( t );
	
	if ( s[1] = s[n] ) or ( t[1] = t[m] ) or ( ( s[1] = '>' ) and ( t[1] = 'v' ) ) or ( ( s[1] <> '>' ) and ( t[1] <> 'v' ) ) then
		writeln( 'NO' )
	else
		writeln( 'YES' );
end.