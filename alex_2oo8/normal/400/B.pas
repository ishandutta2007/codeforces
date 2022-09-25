program problem2;

var	n, m, i, k, ans: longInt;
	x: array[ 1..1000 ] of longInt;
	s: ansistring;

begin
	readln( n, m );
	for i := 1 to n do
	begin
		readln( s );
		
		x[i] := pos( 'S', s ) - pos( 'G', s );
	end;
	
	for i := 1 to n do
		if ( x[i] < 0 ) then
		begin
			writeln( -1 );
			halt;
		end;
		
	ans := 0;
	while ( true ) do
	begin
		i := 1;
		while ( i <= n ) and ( x[i] = 0 ) do
			inc( i );
			
		if ( i > n ) then
			break;

		k := x[i];
		for i := 1 to n do
			if ( x[i] > 0 ) and ( x[i] < k ) then
				k := x[i];
				
		for i := 1 to n do
			if ( x[i] > 0 ) then
				dec( x[i], k );
			
		inc( ans );
	end;
	
	writeln( ans );
end.