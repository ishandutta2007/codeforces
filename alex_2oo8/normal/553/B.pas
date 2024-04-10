program problem2;

var	n, i: longInt;
	f: array[ 0..50 ] of int64;
	k: int64;

begin
	f[0] := 1;
	f[1] := 1;
	for i := 2 to 50 do
		f[i] := f[i - 1] + f[i - 2];
	
	readln( n, k );
	
	i := 1;
	while ( i <= n ) do
		if ( k <= f[n - i] ) then
		begin
			write( i, ' ' );
			inc( i );
		end
		else
		begin
			dec( k, f[n - i] );
			
			write( i + 1, ' ', i, ' ' );
			inc( i, 2 );
		end;
	
	writeln();
end.