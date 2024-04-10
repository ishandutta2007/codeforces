program problem3;
uses math;

const	inf =	round(1e9);

var	n, m, i, j, k, p, free: longInt;
	s: array[ 1..20 ] of ansistring;
	mask, cost: array[ 1..220 ] of longInt;
	dp: array[ 0..1 shl 20 ] of longInt;
	msk, sum, mx: array[ 'a'..'z' ] of longInt;
	a: array[ 1..20, 1..20 ] of longInt;
	c: char;

begin
	readln( n, m );
	for i := 1 to n do
		readln( s[i] );
	
	for i := 1 to n do
		for j := 1 to m do
			read( a[i][j] );
	
	dp[0] := 0;
	for i := 1 to (1 shl n) - 1 do
		dp[i] := inf;
	
	free := 0;
	k := n;
	for i := 1 to n do
	begin
		mask[i] := 1 shl (i - 1);
		cost[i] := a[i][1];
		for j := 1 to m do
			cost[i] := min( cost[i], a[i][j] );
	end;
	
	for i := 1 to m do
	begin
		for c := 'a' to 'z' do
		begin
			msk[c] := 0;
			sum[c] := 0;
			mx[c] := 0;
		end;
		
		for j := 1 to n do
		begin
			msk[ s[j][i] ] := msk[ s[j][i] ] or (1 shl (j - 1));
			inc( sum[ s[j][i] ], a[j][i] );
			mx[ s[j][i] ] := max( mx[ s[j][i] ], a[j][i] );
		end;
		
		for c := 'a' to 'z' do
			if ( msk[c] > 0 ) then
			begin
				if ( msk[c] and ( msk[c] - 1 ) = 0 ) then
					free := free or msk[c]
				else
				begin
					inc( k );
					mask[k] := msk[c];
					cost[k] := sum[c] - mx[c];
				end;
			end;
	end;
	
//	for i := 1 to k do
//		writeln( mask[i], ' ', cost[i] );
	
	dp[free] := 0;
	for i := 0 to (1 shl n) - 1 do
		for j := 1 to k do
		begin
			p := i or mask[j];
			dp[p] := min( dp[p], dp[i] + cost[j] );
		end;
	
	writeln( dp[ (1 shl n) - 1 ] );
end.