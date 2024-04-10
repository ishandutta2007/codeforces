program problem2;

var	s: ansistring;
	cnt: array[ 'a'..'z' ] of longInt;
	c: char;
	k, i: longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );
	readln( s );
	for i := 1 to length(s) do
		inc( cnt[ s[i] ] );
		
	k := 0;
	for c := 'a' to 'z' do
		inc( k, ( cnt[c] mod 2 ) );
		
	if ( odd(k) ) or ( k = 0 ) then
		writeln( 'First' )
	else
		writeln( 'Second' );
end.