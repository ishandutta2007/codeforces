program problem2;

var	n, t, i, j, pp: longInt;
	dp: array[ 0..5000, 0..5000 ] of extended;
	p: array[ 1..5000 ] of extended;
	tt: array[ 1..5000 ] of longInt;
	ans, p_pow: extended;

begin
	readln( n, t );
	for i := 1 to n do
	begin
		readln( pp, tt[i] );
		
		p[i] := pp / 100;
	end;
	
	dp[0][0] := 1.0;
	for i := 1 to t do
		dp[0][i] := 0.0;
	
	ans := 0.0;
	for i := 1 to n do
	begin
		dp[i][0] := 0.0;
		for j := 1 to tt[i] - 1 do
			dp[i][j] := dp[i][j - 1] * ( 1 - p[i] ) + dp[i - 1][j - 1] * p[i];
			
		p_pow := 1;
		for j := 1 to tt[i] do
			p_pow := p_pow * ( 1 - p[i] );
		
		dp[i][ tt[i] ] := dp[i][ tt[i] - 1 ] * ( 1 - p[i] ) + dp[i - 1][ tt[i] - 1 ] * p[i] + dp[i - 1][0] * p_pow;
		
		for j := tt[i] + 1 to t do
			dp[i][j] := dp[i][j - 1] * ( 1 - p[i] ) + dp[i - 1][j - 1] * p[i] + ( dp[i - 1][ j - tt[i] ] - dp[i - 1][ j - tt[i] - 1 ] ) * p_pow;
		
		ans := ans + i * dp[i][t];
		p_pow := 1;
		for j := 1 to tt[i] - 1 do
		begin
			p_pow := p_pow * ( 1 - p[i] );
			ans := ans + (i - 1) * dp[i - 1][t - j] * p_pow;
		end;
	end;
	
	for i := 1 to t - 1 do
		ans := ans + n * dp[n][i];
	
	writeln( ans:0:15 );
end.