program problem4;
uses math;

const	md =	1000000007;

var	t, n, k, i, j: longInt;
	dp: array[ 1..1000, 1..1000 ] of longInt;
	c: array[ 0..2000, 0..2000 ] of int64;
	f: array[ 0..1000, 0..50, 0..1000 ] of longInt;
	fact: array[ 1..50 ] of int64;

begin
	c[0][0] := 1;
	for i := 1 to 2000 do
	begin
		c[i][0] := 1;
		for j := 1 to i do
			c[i][j] := ( c[i - 1][j - 1] + c[i - 1][j] ) mod md;
	end;

	for k := 0 to 1000 do
	begin
		f[0][0][k] := 1;
		f[0][1][k] := 1;
	end;
	
	for i := 1 to 1000 do
		for j := 1 to 50 do
		begin
			for k := 1 to i do
			begin
				f[i][j][k] := f[i][j][k - 1] + f[i - k][j - 1][k - 1];
				
				if ( f[i][j][k] >= md ) then
					dec( f[i][j][k], md );
			end;
			
			for k := i + 1 to 1000 do
				f[i][j][k] := f[i][j][k - 1];
		end;

	fact[1] := 1;
	for i := 2 to 50 do
		fact[i] := ( fact[i - 1] * i ) mod md;
		
	dp[1][1] := 1;
	for i := 2 to 1000 do
		for j := 1 to min(i, 50) do
			for k := 0 to i - j do
				dp[i][j] := ( dp[i][j] + ( ( f[i - j - k][j][i - j - k] * fact[j] ) mod md ) * c[k + j][j] ) mod md;
	
	readln( t );
	while ( t > 0 ) do
	begin
		readln( n, k );
		
		writeln( dp[n][k] );
		
		dec( t );
	end;
end.