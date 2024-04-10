program problem5;
uses math;

const	inf =	trunc( 1.0e+9 );

type	tRec =	record
					p: longInt;
					c1, c2: char;
				end;

var	n, m, i, j, ans: longInt;
	c1, c2, c3, c4: char;
	dp: array[ 0..500, 'a'..'z', 'a'..'z' ] of tRec;
	cnt: array[ 0..1, 'a'..'z' ] of longInt;
	res: array[ 1..500, 0..1 ] of char;
	s: ansistring;

begin
	fillchar( dp, sizeOf(dp), 0 );

	readln( n, m );
	for i := 1 to n do
	begin
		fillchar( cnt, sizeOf(cnt), 0 );
		
		readln( s );
		for c1 := 'a' to 'z' do
			for j := 1 to m do
				if ( s[j] <> c1 ) then
					inc( cnt[ j mod 2 ][c1] );
					
		for c1 := 'a' to 'z' do
			for c2 := 'a' to 'z' do
			begin
				dp[i][c1][c2].p := inf;
				if ( c1 <> c2 ) then
				begin
					for c3 := 'a' to 'z' do
						for c4 := 'a' to 'z' do
							if ( c1 <> c3 ) and ( c2 <> c4 ) and ( dp[i-1][c3][c4].p < dp[i][c1][c2].p ) then
							begin
								dp[i][c1][c2].p  := dp[i-1][c3][c4].p;
								dp[i][c1][c2].c1 := c3;
								dp[i][c1][c2].c2 := c4;
							end;
								
					inc( dp[i][c1][c2].p, ( cnt[0][c1] + cnt[1][c2] ) );
				end;
			end;
			
	end;
	
	ans := inf;
	for c1 := 'a' to 'z' do
		for c2 := 'a' to 'z' do
			if ( dp[n][c1][c2].p < ans ) then
			begin
				ans := dp[n][c1][c2].p;
				c3 := c1;
				c4 := c2;
			end;
			
	c1 := c3;
	c2 := c4;
	for i := n downTo 1 do
	begin
		res[i][0] := c1;
		res[i][1] := c2;
		
		c3 := c1;
		c4 := c2;
		
		c1 := dp[i][c3][c4].c1;
		c2 := dp[i][c3][c4].c2;
	end;
			
	writeln( ans );
	for i := 1 to n do
	begin
		for j := 1 to m do
			write( res[i][ j mod 2 ] );
		writeln();
	end;
end.