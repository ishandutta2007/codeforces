program problem6;
uses math;

var	n, m, i, j, k: longInt;
	t, q: array[ 1..1000 ] of longInt;
	dp: array[ 0..100, 0..1000 ] of longInt;
	cnt: array[ 0..100 ] of longInt;
	sum: array[ 0..100, 0..1000 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( t[i], q[i] );
	
	for i := 1000 downto 1 do
		for j := 1 to n do
			if ( q[j] = i ) then
			begin
				inc( cnt[ t[j] ] );
				sum[ t[j] ][ cnt[ t[j] ] ] := sum[ t[j] ][ cnt[ t[j] ] - 1 ] + i;
			end;
	
	for i := 1 to n do
		dp[0][i] := max( dp[0][i - 1], sum[0][i] );
	
	for i := 1 to m do
	begin
		for j := 0 to n do
			for k := 0 to min( j, cnt[i] ) do
				dp[i][j] := max( dp[i][j], dp[i - 1][ min( n, (j - k) * 2 ) ] + sum[i][k] );
		
		for j := 1 to n do
			dp[i][j] := max( dp[i][j], dp[i][j - 1] );
	end;
	
	writeln( dp[m][1] );
end.