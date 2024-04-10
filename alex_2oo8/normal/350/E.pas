program problem5;

var	n, k, m, i, j, v, l, r: longInt;
	marked: array[ 1..300 ] of boolean;

begin
	fillchar( marked, sizeOf(marked), 0 );
	
	readln( n, m, k );
	for i := 1 to k do
	begin
		read( v );
		
		marked[v] := true;
		
		if ( i = 1 ) then l := v;
		if ( i = 2 ) then r := v;
	end;
	
	if ( n = k ) or ( 2 * m > n * (n-1) - 2 * k + 2 ) then
	begin
		writeln( '-1' );
		halt;
	end;
	
	v := 1;
	while ( marked[v] ) do
		inc( v );

	writeln( l, ' ', v );
	writeln( v, ' ', r );
	for i := 1 to n do
		if ( i <> l ) and ( i <> r ) and ( i <> v ) then
			writeln( i, ' ', v );
			
	dec( m, n - 1 );
	
	for i := 1 to n do
		for j := i + 1 to n do
			if ( m > 0 ) and ( i <> v ) and ( j <> v ) and ( ( i <> l ) or ( j <> r ) ) and ( ( j <> l ) or ( i <> r ) ) and ( ( i <> r ) or ( not marked[j] ) ) and ( ( j <> r ) or ( not marked[i] ) ) then
			begin
				writeln( i, ' ', j );
				
				dec( m );
			end;
end.