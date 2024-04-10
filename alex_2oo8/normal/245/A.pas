program problem1;

var n, i, t, x, y: longInt;
	k: array[ 1..2, 0..1 ] of longInt;

begin
	fillchar( k, sizeOf(k), 0 );

	readln( n );
	for i := 1 to n do
	begin
		readln( t, x, y );
		inc( k[t][0], x );
		inc( k[t][1], y );
	end;

	for i := 1 to 2 do
		if ( k[i][0] >= k[i][1] ) then
			writeln( 'LIVE' )
		else
			writeln( 'DEAD' );
end.