program problem1;

var	s: ansistring;
	ok: array[ 'A'..'Z' ] of boolean;
	n, i: longInt;

begin
	fillchar( ok, sizeOf(ok), false );
	
	ok['A'] := true;
	ok['H'] := true;
	ok['I'] := true;
	ok['M'] := true;
	ok['O'] := true;
	ok['T'] := true;
	ok['U'] := true;
	ok['V'] := true;
	ok['W'] := true;
	ok['X'] := true;
	ok['Y'] := true;

	readln( s );
	n := length(s);
	
	for i := 1 to n do
		if ( not ok[ s[i] ] ) or ( s[i] <> s[n + 1 - i] ) then
		begin
			writeln( 'NO' );
			halt;
		end;
		
	writeln( 'YES' );
end.