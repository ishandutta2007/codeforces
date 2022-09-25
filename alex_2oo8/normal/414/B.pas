program problem2;

const	md =	1000000007;

var	n, m, i, j, k, ans: longInt;
	dp: array[ 0..2000, 1..2000 ] of longInt;

begin
	readln( m, n );
	
	dp[0][1] := 1;
	for i := 0 to n - 1 do
		for j := 1 to m do
			for k := 1 to m div j do
				dp[i + 1][k * j] := ( dp[i + 1][k * j] + dp[i][j] ) mod md;
				
	ans := 0;
	for i := 1 to m do
		ans := ( ans + dp[n][i] ) mod md;
	
	writeln( ans );
end.