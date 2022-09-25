program problem1;

var	n, m, i: longInt;
	s1, s2: ansistring;
	a, b: array[ 0..300000 ] of longInt;
	ok: boolean;

begin
	readln( s1 );
	readln( s2 );
	
	n := length(s1);
	m := length(s2);
	
	for i := 0 to n - 1 do
		a[i] := ord( s1[n - i] ) - ord('0');
	
	for i := 0 to m - 1 do
		b[i] := ord( s2[m - i] ) - ord('0');
	
	i := 2 * n - 2;
	while ( i >= 0 ) do
	begin
		ok := false;
		while ( a[i] > 0 ) and ( a[i + 1] > 0 ) do
		begin
			dec( a[i] );
			dec( a[i + 1] );
			inc( a[i + 2] );
			
			ok := true;
		end;
		
		if ( ok ) then
			inc( i, 2 )
		else
			dec( i );
	end;
	
	i := 2 * m - 2;
	while ( i >= 0 ) do
	begin
		ok := false;
		while ( b[i] > 0 ) and ( b[i + 1] > 0 ) do
		begin
			dec( b[i] );
			dec( b[i + 1] );
			inc( b[i + 2] );
			
			ok := true;
		end;
		
		if ( ok ) then
			inc( i, 2 )
		else
			dec( i );
	end;
	
	i := 300000;
	while ( i >= 0 ) and ( a[i] = b[i] ) do
		dec( i );

	if ( i < 0 ) then
		writeln( '=' )
	else if ( a[i] > b[i] ) then
		writeln( '>' )
	else
		writeln( '<' );
end.