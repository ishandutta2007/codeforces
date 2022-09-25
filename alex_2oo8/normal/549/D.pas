program problem4;

var	n, m, i, j, ans, x: longInt;
	s: array[ 1..100 ] of ansistring;
	f: array[ 1..101, 1..101 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( s[i] );
	
	ans := 0;
	for i := n downto 1 do
		for j := m downto 1 do
		begin
			inc( f[i][j], f[i + 1][j] + f[i][j + 1] - f[i + 1][j + 1] );
			
			x := -1;
			if ( s[i][j] = 'W' ) then
				x := 1;
			
			if ( f[i][j] <> x ) then
			begin
				f[i][j] := x;
				
				inc( ans );
			end;
		end;
		
	writeln( ans );
end.