program problem2;

var	n, i, j, k: longInt;
	s: array[ 1..100 ] of ansistring;
	a, x: array[ 1..100 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		readln( s[i] );
	
	for i := 1 to n do
		read( a[i] );
	
	k := 0;
	while ( true ) do
	begin
		i := 1;
		while ( i <= n ) and ( a[i] <> 0 ) do
			inc( i );
		
		if ( i > n ) then
			break;
		
		inc( k );
		x[k] := i;
		
		for j := 1 to n do
			if ( s[i][j] = '1' ) then
				dec( a[j] );
	end;
	
	writeln( k );
	for i := 1 to k do
		write( x[i], ' ' );
	writeln();
end.