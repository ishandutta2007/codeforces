program problem2;
uses math;

const	inf: int64 =	trunc(2.0e+18);

procedure swap( var a, b: longInt );
var	c: longInt;
begin
	c := a;
	a := b;
	b := c;
end;

var	n, m, b, i, j, cnt, xx, ci, li: longInt;
	x, k, p: array[ 1..100 ] of longInt;
	dp: array[ 0..1, 0..1 shl 20 ] of int64;
	ans: int64;

begin
	readln( n, m, b );
	for i := 1 to n do
	begin
		readln( x[i], k[i], cnt );
		
		p[i] := 0;
		for j := 1 to cnt do
		begin
			read( xx );
			
			p[i] := p[i] or ( 1 shl (xx - 1) );
		end;
	end;
	
	for i := 1 to n do
		for j := i + 1 to n do
			if ( k[j] < k[i] ) then
			begin
				swap( k[i], k[j] );
				swap( x[i], x[j] );
				swap( p[i], p[j] );
			end;
	
	ans := inf;
	dp[0][0] := 0;
	for i := 1 to (1 shl m) - 1 do
		dp[0][i] := inf;

	ci := 0;
	li := 1;
	for i := 1 to n do
	begin
		swap( ci, li );
		
		for j := 0 to (1 shl m) - 1 do
			dp[ci][j] := dp[li][j];
	
		for j := 0 to (1 shl m) - 1 do
			dp[ci][ j or p[i] ] := min( dp[ci][ j or p[i] ], dp[li][j] + x[i] );
		
		ans := min( ans, dp[ci][ (1 shl m) - 1 ] + k[i] * int64(b) );
	end;
	
	if ( ans = inf ) then
		writeln( -1 )
	else
		writeln( ans );
end.