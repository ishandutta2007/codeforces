program problem3;
uses math;

var	dp: array[ 0..1000000, 1..9, 0..1 ] of longInt;

function solve( x: int64 ): int64;
var	s: string;
	i, j, d: longInt;
	y, res: int64;
begin
	res := 0;

	while ( true ) do
	begin
		str( x, s );

		d := 0;
		for i := 1 to length(s) do
			if ( ord( s[i] ) - ord( '0' ) > d ) then
			begin
				d := ord( s[i] ) - ord( '0' );
				j := i;
			end;
			
		if ( d = 0 ) then
			exit( res );

		if ( x < 1000000 ) then
		begin
			inc( res, 1 );
			dec( x, d );
			
			continue;
		end;
			
		d := 0;
		for i := 1 to length(s) - 6 do
			if ( ord( s[i] ) - ord( '0' ) > d ) then
			begin
				d := ord( s[i] ) - ord( '0' );
				j := i;
			end;
			
		inc( res, dp[x mod 1000000][d][0] );
		x := x - ( x mod 1000000 ) + dp[x mod 1000000][d][1];
	end;
end;

var	i, j, k, d: longInt;
	s: string;
	n: int64;

begin
	readln( n );
	
	for i := 0 to 999999 do
		for j := 1 to 9 do
		begin
			str( i, s );
			
			d := j;
			for k := 1 to length(s) do
				if ( ord( s[k] ) - ord( '0' ) > d ) then
					d := ord( s[k] ) - ord( '0' );

			if ( ( i - d ) < 0 ) then
			begin
				dp[i][j][0] := 1;
				dp[i][j][1] := i - d;
			end
			else
			begin
				dp[i][j][0] := dp[i-d][j][0] + 1;
				dp[i][j][1] := dp[i-d][j][1];
			end;
		end;
	
	writeln( solve( n ) );
end.