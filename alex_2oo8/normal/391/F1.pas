program problem6;
uses math;

var	n, i, j, k: longInt;
	f, g: array[ 1..3000, 0..3000 ] of int64;
	p: array[ 1..3000 ] of int64;
	ans: int64;

begin
	fillchar( f, sizeOf(f), 0 );
	fillchar( g, sizeOf(g), 0 );

	readln( n, k );
	for i := 1 to n do
		read( p[i] );

	ans := 0;
	for i := 2 to n do
		for j := 1 to k do
		begin
			f[i][j] := max( g[i - 1][j - 1], f[i - 1][j] + p[i] - p[i - 1] );
			g[i][j] := max( g[i - 1][j], f[i][j] );
			
			ans := max( ans, f[i][j] );
		end;
		
	writeln( ans );
end.