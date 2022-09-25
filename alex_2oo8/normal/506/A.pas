program problem1;
uses math;

var	n, d, i, j, x, ans: longInt;
	f: array[ 0..30000 ] of longInt;
	dp: array[ 0..30000, -333..333 ] of longInt;

begin
	fillchar( f, sizeOf(f), 0 );

	readln( n, d );
	for i := 1 to n do
	begin
		read( x );
		inc( f[x] );
	end;
	
	for i := 0 to 30000 do
		for j := -333 to 333 do
			dp[i][j] := -10000000;
	
	dp[d][0] := f[d];
	for i := d + 1 to 30000 do
	begin
		for j := -332 to 332 do
			if ( i - (d + j) >= 0 ) and ( (d + j) > 0 ) then
				dp[i][j] := max( dp[ i - (d + j) ][j], max( dp[ i - (d + j) ][j - 1], dp[ i - (d + j) ][j + 1] ) ) + f[i];
	end;
	
	ans := 0;
	for i := 0 to 30000 do
		for j := -332 to 332 do
			ans := max( ans, dp[i][j] );
	
	writeln( ans );
end.