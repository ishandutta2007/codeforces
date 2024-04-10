program problem3;

var	n, i, j, k: longInt;
	s: ansistring;
	cnt: array[ #0..#255 ] of longInt;
	b: boolean;

begin
	readln( s );
	n := length(s);
	
	for i := 1 to n do
		inc( cnt[ s[i] ] );
		
	if ( cnt['1'] <= ( (n-1) div 2 ) ) then
		writeln( '00' );
		
	if ( s[n] = '?' ) then
	begin
		s[n] := '1';
		inc( cnt['1'] );
		dec( cnt['?'] );
		b := true;
	end;
	
	if ( s[n] = '1' ) and ( cnt['1'] <= ( (n+1) div 2 ) ) and ( ( (n+1) div 2 ) <= ( cnt['1'] + cnt['?'] ) ) then
		writeln( '01' );
		
	if ( b ) then
	begin
		s[n] := '0';
		dec( cnt['1'] );
	end;
	
	if ( s[n] = '0' ) and ( cnt['1'] <= ( (n+1) div 2 ) ) and ( ( (n+1) div 2 ) <= ( cnt['1'] + cnt['?'] ) ) then
		writeln( '10' );
		
	if ( cnt['0'] <= ( (n-2) div 2 ) ) then
		writeln( '11' );
end.