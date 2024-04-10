program problem2;
uses math;

var	n, m, i, j: longInt;
	a: array[ 1..1000, 1..1000 ] of longInt;
	b, c, d, e: array[ 0..1001, 0..1001 ] of int64;
	ans: int64;

begin
	readln( n, m );
	for i := 1 to n do
		for j := 1 to m do
			read( a[i][j] );
	
	for i := 1 to n do
		for j := 1 to m do
			b[i][j] := max( b[i - 1][j], b[i][j - 1] ) + a[i][j];
			
	for i := 1 to n do
		for j := m downto 1 do
			c[i][j] := max( c[i - 1][j], c[i][j + 1] ) + a[i][j];
	
	for i := n downto 1 do
		for j := 1 to m do
			d[i][j] := max( d[i + 1][j], d[i][j - 1] ) + a[i][j];
	
	for i := n downto 1 do
		for j := m downto 1 do
			e[i][j] := max( e[i + 1][j], e[i][j + 1] ) + a[i][j];
			
	ans := 0;
	for i := 2 to n - 1 do
		for j := 2 to m - 1 do
			ans := max( ans, max( b[i - 1][j] + e[i + 1][j] + d[i][j - 1] + c[i][j + 1], b[i][j - 1] + e[i][j + 1] + d[i + 1][j] + c[i - 1][j] ) );
			
	writeln( ans );
end.