program problemA;
uses math;

var	n, i, l, r, x, y, z: longInt;
	s: ansistring;
	cnt: array[ 0..100000, 'x'..'z' ] of longInt;
	c: char;

begin
	readln( s );
	n := length( s );
	
	for i := 1 to n do
	begin
		for c := 'x' to 'z' do
			cnt[i][c] := cnt[i-1][c];
			
		inc( cnt[i][ s[i] ] );
	end;
	
	readln( n );
	for i := 1 to n do
	begin
		readln( l, r );
		
		x := cnt[r]['x'] - cnt[l-1]['x'];
		y := cnt[r]['y'] - cnt[l-1]['y'];
		z := cnt[r]['z'] - cnt[l-1]['z'];
		
		if ( r - l + 1 < 3 ) or ( max( max( x, y ), z ) - min( min( x, y ), z ) <= 1 ) then
			writeln( 'YES' )
		else
			writeln( 'NO' );
	end;
end.