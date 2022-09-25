program problem2;

var	n: longInt;
	a: array[ 2..300000 ] of longInt;
	dp: array[ 1..300000, 2..3 ] of int64;
	ans: int64;
	
function calc( x, step: longInt ): int64;
var	res: int64;
begin
	if ( x <= 0 ) or ( x > n ) then
		exit( 0 );

	if ( dp[x][step] = -2 ) then
	begin
		dp[x][step] := -3;

		if ( step = 2 ) then
			res := calc( ( x + a[x] ), 3 )
		else
			res := calc( ( x - a[x] ), 2 );
			
		if ( res <> -1 ) then
			inc( res, a[x] );
			
		dp[x][step] := res;
	end
	else if ( dp[x][step] = -3 ) then
		dp[x][step] := -1;
	
	exit( dp[x][step] );
end;
	
var	i, j: longInt;

begin
	readln( n );
	for i := 2 to n do
		read( a[i] );
		
	for i := 1 to n do
		for j := 2 to 3 do
			dp[i][j] := -2;
		
	for i := 1 to (n-1) do
	begin
		ans := calc( i + 1, 3 );
		if ( ans <> -1 ) then
			inc( ans, i );
			
		writeln( ans );
	end;
end.