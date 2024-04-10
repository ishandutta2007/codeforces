program problem6;
uses math;

const	inf: int64 = round( 1e18 );

var	a: array[ 1..10001 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random( r - l + 1 ) ];
		while ( i <= j ) do
		begin
			while ( a[i] < med ) do
				inc( i );
			
			while ( a[j] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := a[i];
				a[i] := a[j];
				a[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, m, x, i, j, d, li, ci: longInt;
	l, r: array[ 1..5000 ] of longInt;
	dp: array[ 0..1, 1..10001 ] of int64;
	lp, rp: array[ 0..10002 ] of int64;
	ans: int64;

begin
	readln( n, x );
	for i := 1 to n do
	begin
		readln( l[i], r[i] );
		
		a[2 * i] := l[i];
		a[2 * i - 1] := r[i];
	end;
	
	a[2 * n + 1] := x;
	
	m := 2 * n + 1;
	
	qsort( 1, m );
	
	for i := 1 to m do
		if ( a[i] = x ) then
		begin
			x := i;
			
			break;
		end;
	
	for i := 1 to m do
		dp[0][i] := inf;
	
	dp[0][x] := 0;
	ci := 0;
	li := 1;
	for i := 1 to n do
	begin
		ci := 1 xor ci;
		li := 1 xor li;
	
		lp[0] := inf;
		for j := 1 to m do
			lp[j] := min( lp[j - 1], dp[li][j] - a[j] );
		
		rp[m + 1] := inf;
		for j := m downto 1 do
			rp[j] := min( rp[j + 1], dp[li][j] + a[j] );
		
		for j := 1 to m do
		begin
			d := 0;
			if ( a[j] < l[i] ) then
				d := l[i] - a[j]
			else if ( a[j] > r[i] ) then
				d := a[j] - r[i];
			
			dp[ci][j] := min( lp[j] + a[j], rp[j] - a[j] ) + d;
		end;
	end;
	
	ans := inf;
	for i := 1 to m do
		ans := min( ans, dp[ci][i] );
	
	writeln( ans );
end.