program problem2;
uses math;

var	n, m: longInt;
	a, b, g, ans, f_a, f_g: array[ 0..5000 ] of longInt;
	dp: array[ 0..5000, 0..5000 ] of longInt;
	
function gcd( a, b: longInt ): longInt;
var	c: longInt;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;
	
	exit( a );
end;

function find( x: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := m;
	while ( l < r ) do
	begin
		c := (l + r) div 2;
		
		if ( b[c] < x ) then
			l := c + 1
		else
			r := c;
	end;
	
	if ( b[l] = x ) then
		exit( -1 )
	else
		exit( +1 );
end;

function f( x: longInt ): longInt;
var	i, res, d: longInt;
begin
	res := 0;

	i := 2;
	while ( i * i <= x ) do
	begin
		if ( x mod i = 0 ) then
		begin
			d := find( i );
			
			while ( x mod i = 0 ) do
			begin
				inc( res, d );
				x := x div i;
			end;
		end;
		
		inc( i );
	end;
	
	if ( x > 1 ) then
		inc( res, find( x ) );
		
	exit( res );
end;

var	i, j: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to m do
		read( b[i] );
	
	g[1] := a[1];
	for i := 2 to n do
		g[i] := gcd( g[i - 1], a[i] );
		
	for i := 1 to n do
	begin
		f_a[i] := f( a[i] );
		f_g[i] := f( g[i] );
	end;
	
	ans[0] := 0;
	for i := 1 to n do
	begin
		for j := i to n do
			dp[i][j] := max( dp[i - 1][j] + f_a[i] - f_g[j], dp[i - 1][i] + f_a[i] - f_g[i] );
		
		ans[i] := max( ans[i - 1] + f_a[i], dp[i][i] );
	end;
	
	writeln( ans[n] );
end.