program problem1;

var	n, m, b, i, j, k, md, a: longInt;
	dp: array[ 0..500, 0..500 ] of longInt;

begin
	readln( n, m, b, md );
	
	dp[0][0] := 1;
	for i := 1 to n do
	begin
		read( a );
		
		for j := 1 to m do
			for k := a to b do
			begin
				inc( dp[j][k], dp[j - 1][k - a] );
				
				if ( dp[j][k] >= md ) then
					dec( dp[j][k], md );
			end;
	end;
	
	a := 0;
	for i := 0 to b do
		a := ( a + dp[m][i] ) mod md;
	
	writeln( a );
end.