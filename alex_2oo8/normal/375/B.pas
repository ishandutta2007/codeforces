program problem2;
uses math;

var	n, m, i, j, k: longInt;
	a: array[ 1..5000 ] of ansistring;
	f: array[ 0..5001, 0..5001 ] of longInt;
	ans: int64;

begin
	fillchar( f, sizeOf(f), 0 );

	readln( n, m );
	for i := 1 to n do
		readln( a[i] );
	
	for i := 1 to n do
	begin
		k := 0;
		while ( k < m ) do
		begin
			j := k + 1;
			while ( j <= m ) and ( a[i][j] = '0' ) do
				inc( j );
				
			if ( j > m ) then
				break;

			k := j;
			while ( k < m ) and ( a[i][k + 1] = '1' ) do
				inc( k );
			
			inc( f[j][k] );
		end;
	end;
	
	for i := m downto 1 do
		for j := 1 to m - i + 1 do
			inc( f[j][j + i - 1], f[j - 1][j + i - 1] + f[j][j + i] - f[j - 1][j + i] );
	
	ans := 0;
	for i := 1 to m do
		for j := i to m do
			ans := max( ans, f[i][j] * int64(j - i + 1) );
			
	writeln( ans );
end.