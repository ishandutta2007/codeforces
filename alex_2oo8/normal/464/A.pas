program problem1;

var	p: longInt;

function f( var s: ansistring; l, r: longInt ): boolean;
var	i: longInt;
begin
	for i := l to r do
	begin
		s[i] := 'a';
		while ( ( i > 1 ) and ( s[i] = s[i - 1] ) ) or ( ( i > 2 ) and ( s[i] = s[i - 2] ) ) do
			inc( s[i] );
		
		if ( ord( s[i] ) - ord( 'a' ) + 1 > p ) then
			exit( false );
	end;
	
	exit( true );
end;

var	n, i: longInt;
	s, t: ansistring;
	c: char;

begin
	readln( n, p );
	readln( s );
	
	for i := n downto 1 do
	begin
		t := s;
		
		c := succ( t[i] );
		while ( ( i > 1 ) and ( c = t[i - 1] ) ) or ( ( i > 2 ) and ( c = t[i - 2] ) ) do
			inc( c );
		
		if ( ord(c) - ord('a') + 1 > p ) then
			continue;
		
		t[i] := c;
		
		if ( f( t, i + 1, n ) ) then
		begin
			writeln( t );
			
			halt;
		end;
	end;
	
	writeln( 'NO' );
end.