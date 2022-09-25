program problem2;

const	md = 1000000007;

var	s, t: ansistring;
	n, m, i, j, last: longInt;
	dp, sum, kmp: array[ 0..200000 ] of longInt;

begin
	readln( s );
	readln( t );
	
	n := length(s);
	m := length(t);
	
	s := t + '#' + s;
	kmp[1] := 0;
	for i := 2 to n + m + 1 do
	begin
		j := kmp[i - 1];
		while ( j > 0 ) and ( s[i] <> s[j + 1] ) do
			j := kmp[j];
		
		if ( s[i] = s[j + 1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
	end;
	
	dp[0] := 1;
	sum[0] := 1;
	last := -1;
	for i := 1 to n do
	begin
		if ( kmp[m + 1 + i] = m ) then
			last := i - m;
		
		dp[i] := dp[i - 1];
		if ( last > -1 ) then
			dp[i] := ( dp[i] + sum[last] ) mod md;
		
		sum[i] := ( sum[i - 1] + dp[i] ) mod md;
	end;
	
	writeln( ( dp[n] + md - 1 ) mod md );
end.