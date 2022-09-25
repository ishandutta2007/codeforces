program problem3;
uses math;

var	n, i, j: longInt;
	dp: array[ 0..1000000 ] of longInt;
	s: string;

begin
	readln( n );
	
	dp[0] := 0;
	for i := 1 to n do
	begin
		dp[i] := 100000000;
	
		str( i, s );
		
		for j := 1 to 9 do
			if ( pos( chr( ord( '0' ) + j ), s ) > 0 ) then
				dp[i] := min( dp[i], dp[i-j] + 1 );
	end;
	
	writeln( dp[n] );
end.