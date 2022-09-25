program problem3;

const	md =	1000000007;

var	dp: array[ 0..2000, 1..2000 ] of longInt;
	n, i, j, k1, k2: longInt;
	a: array[ 1..2000 ] of longInt;
	free, used: array[ 1..2000 ] of boolean;
	fact: array[ 0..2000 ] of int64;

begin
	fact[0] := 1;
	for i := 1 to 2000 do
		fact[i] := ( fact[i-1] * i ) mod md;
		
	for i := 1 to 2000 do
		dp[0][i] := 1;
		
	for i := 1 to 2000 do
	begin
		if ( i = 1 ) then
			dp[i][i] := 0
		else if ( odd(i) ) then
			dp[i][i] := ( int64(i) * dp[i-1][i-1] - 1 ) mod md
		else
			dp[i][i] := ( int64(i) * dp[i-1][i-1] + 1 ) mod md;

		for j := i + 1 to 2000 do
			dp[i][j] := ( dp[i][j-1] + int64(i) * dp[i-1][j-1] ) mod md;
	end;

	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to n do
		if ( a[i] = -1 ) then
			free[i] := true
		else
			used[ a[i] ] := true;
			
	k1 := 0;
	k2 := 0;
	for i := 1 to n do
		if ( not used[i] ) then
		begin
			if ( free[i] ) then
				inc( k1 )
			else
				inc( k2 );
		end;
		
	writeln( ( dp[k1][k1+k2] * fact[k2] ) mod md );
end.