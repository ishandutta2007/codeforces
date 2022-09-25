program problem3;
uses math;


const	inf =	1000000;

var	s, p: ansistring;
	n, m, i, j, k: longInt;
	dp: array[ 0..2000, 0..2000 ] of longInt;

begin
	readln( s );
	readln( p );
	
	n := length(s);
	m := length(p);
	
	dp[0][0] := 0;
	for i := 1 to n do
		dp[0][i] := -inf;
		
	for i := 1 to n do
	begin
		k := i + 1;
		j := m;
		while ( j > 0 ) and ( k > 0 ) do
		begin
			dec( k );
			if ( p[j] = s[k] ) then
				dec( j );
		end;
		
		for j := 0 to n do
		begin
			dp[i][j] := dp[i - 1][j];
			
			
			if ( j > 0 ) then
				dp[i][j] := max( dp[i][j], dp[i - 1][j - 1] );
			
			if ( k > 0 ) and ( i - k + 1 - m <= j ) then
				dp[i][j] := max( dp[i][j], dp[k - 1][ j - (i - k + 1 - m) ] + 1 );
		end;
	end;
	
	for i := 0 to n do
		write( dp[n][i], ' ' );
	writeln();
end.