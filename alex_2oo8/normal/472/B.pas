program problem2;

var	n, k, i, j, ans: longInt;
	f: array[ 1..2000 ] of longInt;

begin
	readln( n, k );
	for i := 1 to n do
		read( f[i] );
	
	for i := 1 to n do
		for j := i + 1 to n do
			if ( f[j] > f[i] ) then
			begin
				f[i] := f[i] xor f[j];
				f[j] := f[i] xor f[j];
				f[i] := f[i] xor f[j];
			end;
			
	i := 1;
	ans := 0;
	while ( i <= n ) do
	begin
		inc( ans, 2 * ( f[i] - 1 ) );
		inc( i, k );
	end;
	
	writeln( ans );
end.