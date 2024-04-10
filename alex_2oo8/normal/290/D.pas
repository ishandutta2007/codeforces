program problem4;

var	s: string;
	k, i: longInt;

begin
	readln( s );
	readln( k );
	
	for i := 1 to length(s) do
	begin
		if ( s[i] in ['A'..'Z'] ) then
			s[i] := chr( ord( s[i] ) - ord( 'A' ) + ord( 'a' ) );
			
		if ( ord( s[i] ) < ( 97 + k ) ) then
			s[i] := chr( ord( s[i] ) - ord( 'a' ) + ord( 'A' ) );
	end;
	
	writeln( s );
end.