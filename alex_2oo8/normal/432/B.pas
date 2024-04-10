program problem2;

var	n, i: longInt;
	x, y, cnt: array[ 1..100000 ] of longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n );
	for i := 1 to n do
	begin
		readln( x[i], y[i] );
		
		inc( cnt[ x[i] ] );
	end;
	
	for i := 1 to n do
		writeln( n - 1 + cnt[ y[i] ], ' ', n - 1 - cnt[ y[i] ] );
end.