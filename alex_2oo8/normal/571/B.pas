program problem2;
uses math;

const	inf: int64 = round( 1e+17 );

var	aa: array[ 1..300000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := aa[ l + random( r - l + 1 ) ];
		while ( i <= j ) do
		begin
			while ( aa[i] < med ) do
				inc( i );
			
			while ( aa[j] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := aa[i];
				aa[i] := aa[j];
				aa[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, k, i, j, a, b, p, l: longInt;
	dp: array[ 0..5000, 0..5000 ] of int64;
	f: array[ 1..300001 ] of int64;

begin
	readln( n, k );
	for i := 1 to n do
		read( aa[i] );
	
	qsort( 1, n );
	
	f[1] := 0;
	f[n + 1] := 0;
	for i := 2 to n do
		f[i] := f[i - 1] + abs( aa[i] - aa[i - 1] );
	
	l := n div k;
	b := n mod k;
	a := k - b;
	dp[0][0] := 0;
	for i := 0 to a do
		for j := 0 to b do
		begin
			if ( i + j = 0 ) then
				continue;
		
			p := l * i + (l + 1) * j;
		
			dp[i][j] := inf;
			if ( i > 0 ) then
				dp[i][j] := min( dp[i][j], dp[i - 1][j] + f[p] - f[p - l + 1] );
			
			if ( j > 0 ) then
				dp[i][j] := min( dp[i][j], dp[i][j - 1] + f[p] - f[p - l] );
		end;
	
	writeln( dp[a][b] );
end.