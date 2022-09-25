program problem1;

var	n, a, b, i, x, y, k: longInt;
	s: ansistring;
	sumX, sumY: array[ 0..1000 ] of longInt;
	ok: boolean;

begin
	readln( a, b );
	readln( s );
	
	n := length(s);
	
	for i := 1 to n do
	begin
		sumX[i] := sumX[i-1];
		sumY[i] := sumY[i-1];
	
		if ( s[i] = 'U' ) then
			inc( sumY[i] )
		else if ( s[i] = 'D' ) then
			dec( sumY[i] )
		else if ( s[i] = 'L' ) then
			dec( sumX[i] )
		else
			inc( sumX[i] );
	end;
	
	for i := 0 to n do
		if ( sumX[i] = a ) and ( sumY[i] = b ) then
		begin
			writeln( 'Yes' );
			halt;
		end;
		
	if ( sumX[n] = 0 ) and ( sumY[n] = 0 ) then
	begin
		writeln( 'No' );
		halt;
	end;
	
	ok := false;
	for i := 0 to n do
	begin
		x := a - sumX[i];
		y := b - sumY[i];
		
		if ( sumX[n] = 0 ) then
			k := y div sumY[n]
		else
			k := x div sumX[n];
			
		ok := ok or ( ( sumX[n] * k = x ) and ( sumY[n] * k = y ) and ( k >= 0 ) );
	end;
	
	if ( ok ) then
		writeln( 'Yes' )
	else
		writeln( 'No' );
end.