program problem1;

var	n, i, j: longInt;
	s: ansistring;
	dp: array[ 1..100, 1..100 ] of longInt;
	ok: boolean;

begin
	readln( n );
	readln( s );
	
	ok := false;
	for i := n downto 1 do
		for j := 1 to n do
		begin
			if ( s[i] = '.' ) then
				dp[i][j] := 0
			else if ( i + j > n ) then
				dp[i][j] := 1
			else
				dp[i][j] := dp[i + j][j] + 1;
			
			ok := ok or ( dp[i][j] > 4 );
		end;
	
	if ( ok ) then
		writeln( 'yes' )
	else
		writeln( 'no' );
end.