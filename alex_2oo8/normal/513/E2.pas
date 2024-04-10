program problem5;
uses math;

const	inf: int64 =	round( 1.0e+18 );

var	n, k, i, j, p: longInt;
	a, s, mn, mx: array[ 0..30001 ] of longInt;
	f, g, f2, g2, ff, gg: array[ 1..30000, 1..200 ] of int64;
	ans: int64;

begin
	readln( n, k );
	for i := 1 to n do
		read( a[i] );
	
	s[0] := 0;
	mn[0] := 0;
	mx[0] := 0;
	for i := 1 to n do
	begin
		s[i] := s[i - 1] + a[i];
		mn[i] := min( mn[i - 1], s[i] );
		mx[i] := max( mx[i - 1], s[i] );
	end;
	
	for i := 1 to n do
		for j := 1 to k do
		begin
			f[i][j] := -inf;
			f2[i][j] := -inf;
			g[i][j] := -inf;
			g2[i][j] := -inf;
		end;
	
	for i := 1 to n do
	begin
		f[i][1] := s[i] - mn[i - 1];
		f2[i][1] := 3 * s[i] - mn[i - 1];
		g[i][1] := mx[i - 1] - s[i];
		g2[i][1] := mx[i - 1] - 3 * s[i];
		
		ff[i][1] := f[i][1];
		gg[i][1] := g[i][1];
	end;
	
	for i := 2 to n do
	begin
		f[i][1] := max( f[i - 1][1], f[i][1] );
		f2[i][1] := max( f2[i - 1][1], f2[i][1] );
		g[i][1] := max( g[i - 1][1], g[i][1] );
		g2[i][1] := max( g2[i - 1][1], g2[i][1] );
	end;
	
	for p := 2 to k - 1 do
		for i := p to n do
		begin
			f[i][p] := max( f[i - 1][p - 1], g2[i - 1][p - 1] + 2 * s[i] );
			g[i][p] := max( g[i - 1][p - 1], f2[i - 1][p - 1] - 2 * s[i] );
			f2[i][p] := f[i][p] + 2 * s[i];
			g2[i][p] := g[i][p] - 2 * s[i];
			
			ff[i][p] := f[i][p];
			gg[i][p] := g[i][p];
			
			f[i][p] := max( f[i - 1][p], f[i][p] );
			f2[i][p] := max( f2[i - 1][p], f2[i][p] );
			g[i][p] := max( g[i - 1][p], g[i][p] );
			g2[i][p] := max( g2[i - 1][p], g2[i][p] );
		end;
	
	s[n + 1] := 0;
	mn[n + 1] := 0;
	mx[n + 1] := 0;
	for i := n downto 1 do
	begin
		s[i] := s[i + 1] + a[i];
		mn[i] := min( mn[i + 1], s[i] );
		mx[i] := max( mx[i + 1], s[i] );
	end;
	
	ans := 0;
	for i := k to n do
		ans := max( ans, max( ff[i - 1][k - 1] - ( s[i] - mx[i + 1] ), gg[i - 1][k - 1] + ( s[i] - mn[i + 1] ) ) );
	
	writeln( ans );
end.