program problem4;

var	n, i, j, dx, dy: longInt;
	f: array[ 1..50 ] of ansistring;
	ok: array[ -50..50, -50..50 ] of boolean;

begin
	readln( n );
	for i := 1 to n do
		readln( f[i] );
	
	for i := -n to n do
		for j := -n to n do
			ok[i][j] := true;
	
	for i := 1 to n do
		for j := 1 to n do
			if ( f[i][j] = 'o' ) then
				for dx := -n to n do
					for dy := -n to n do
						if ( i + dx > 0 ) and ( i + dx <= n ) and ( j + dy > 0 ) and ( j + dy <= n ) and ( f[i + dx][j + dy] = '.' ) then
							ok[dx][dy] := false;
	
	for i := 1 to n do
		for j := 1 to n do
			if ( f[i][j] = 'o' ) then
				for dx := -n to n do
					for dy := -n to n do
						if ( ok[dx][dy] ) and ( i + dx > 0 ) and ( i + dx <= n ) and ( j + dy > 0 ) and ( j + dy <= n ) and ( f[i + dx][j + dy] = 'x' ) then
							f[i + dx][j + dy] := '.';
	
	for i := 1 to n do
		for j := 1 to n do
			if ( f[i][j] = 'x' ) then
			begin
				writeln( 'NO' );
				
				halt;
			end;
	
	writeln( 'YES' );
	for i := -n + 1 to n - 1 do
	begin
		for j := -n + 1 to n - 1 do
			if ( abs(i) + abs(j) = 0 ) then
				write( 'o' )
			else if ( ok[i][j] ) then
				write( 'x' )
			else
				write( '.' );
	
		writeln();
	end;
end.