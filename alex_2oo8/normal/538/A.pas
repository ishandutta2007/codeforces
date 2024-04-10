program problem1;

var	s: ansistring;
	n, i, j: longInt;

begin
	readln( s );
	
	n := length(s);
	
	for i := 1 to n do
		for j := i + 1 to n + 1 do
			if ( copy( s, 1, i - 1 ) + copy( s, j, n - j + 1 ) = 'CODEFORCES' ) then
			begin
				writeln( 'YES' );
				
				halt;
			end;
	
	writeln( 'NO' );
end.