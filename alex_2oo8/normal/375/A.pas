program problem1;

const	a: array[ 1..24 ] of longInt = (1689, 1698, 1869, 1896, 1968, 1986, 6189, 6198, 6819, 6891, 6918, 6981, 8169, 8196, 8619, 8691, 8916, 8961, 9168, 9186, 9618, 9681, 9816, 9861);

var	n, i, j, x: longInt;
	s: ansistring;
	cnt: array[ 0..9 ] of longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( s );
	n := length(s);
	
	for i := 1 to n do
		inc( cnt[ ord( s[i] ) - ord( '0' ) ] );
		
	dec( cnt[1] );
	dec( cnt[6] );
	dec( cnt[8] );
	dec( cnt[9] );
	
	x := 0;
	for i := 1 to 9 do
		for j := 1 to cnt[i] do
		begin
			write( i );
			
			x := ( 10 * x + i ) mod 7;
		end;
		
	x := ( x * 10000 ) mod 7;
	
	for i := 1 to 24 do
		if ( ( x + a[i] ) mod 7 = 0 ) then
		begin
			write( a[i] );
			break;
		end;
		
	for i := 1 to cnt[0] do
		write( 0 );
end.