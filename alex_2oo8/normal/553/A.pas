program problem1;

const	md =	1000000007;

var	i, j, k, n, ans: longInt;
	c: array[ 0..1000, -1..1000 ] of longInt;
	a: array[ 1..1000 ] of longInt;

begin
	c[0][0] := 1;
	for i := 1 to 1000 do
		for j := 0 to i do
			c[i][j] := ( c[i - 1][j - 1] + c[i - 1][j] ) mod md;
	
	readln( k );
	for i := 1 to k do
		read( a[i] );
	
	n := 0;
	for i := 1 to k do
		inc( n, a[i] );
	
	ans := 1;
	for i := k downto 1 do
	begin
		ans := ( int64(ans) * c[n - 1][ a[i] - 1 ] ) mod md;
		
		dec( n, a[i] );
	end;
	
	writeln( ans );
end.