program problem1;

var	w, h, i, j: longInt;
	s: array[ 1..100 ] of ansistring;

begin
	readln( w, h );
	for i := 1 to h do
		readln( s[i] );
	
	for i := 1 to 2 * w do
	begin
		for j := 1 to 2 * h do
			write( s[ (j + 1) div 2 ][ (i + 1) div 2 ] );
		
		writeln();
	end;
end.