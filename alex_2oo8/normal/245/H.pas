program problem8;

var n, i, j, l, r: longInt;
	str: ansistring;
	dp: array[ 1..5000, 1..5000 ] of boolean;
	ans: array[ 1..5000, 1..5000 ] of longInt;

begin
	fillchar( dp, sizeOf(dp), 0 );
	fillchar( ans, sizeOf(ans), 0 );

	readln( str );
	n := length(str);
	
	for i := 1 to n do
	begin
		dp[i][i] := true;
		dp[i][i-1] := true;
		
		ans[i][i] := 1;
	end;
	
	for i := 2 to n do
		for l := 1 to (n-i+1) do
		begin
			r := l + i - 1;
			ans[l][r] := ans[l+1][r] + ans[l][r-1] - ans[l+1][r-1];
			
			if ( dp[l+1][r-1] ) and ( str[l] = str[r] ) then
			begin
				dp[l][r] := true;
				inc( ans[l][r] );
			end
			else
				dp[l][r] := false;
		end;
		
{	for i := 1 to n do
		for j := i to n do
			if ( dp[i][j] ) then
				writeln( i, ' ', j, ' ', copy( str, i, (j-i+1) ) );
}		
	readln( n );
	for i := 1 to n do
	begin
		readln( l, r );
		writeln( ans[l][r] );
	end;
end.