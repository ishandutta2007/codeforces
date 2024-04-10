program problem5;

var	s: ansistring;
	i, j, k, ans, n: longInt;
	a: array[ 1..2000000 ] of longInt;

begin
	readln( s );
	n := length(s);
	
	k := 0;
	i := 1;
	while ( i <= n ) do
	begin
		j := i;
		while ( j < n ) and ( s[i] = s[j+1] ) do
			inc( j );

		inc( k );
		if ( i = j ) then
			a[k] := ord( s[i] ) - ord( '0' )
		else if ( s[i] = '1' ) then
			a[k] := 2
		else
			a[k] := -1;
			
		i := j + 1;
	end;
	
	if ( a[k] < 1 ) then
		dec( k );
	
	ans := 0;
	for i := 1 to k do
		if ( a[i] > 0 ) then
			inc( ans, a[i] )
		else if ( a[i] = 0 ) and ( not ( ( a[i-1] = 1 ) and ( a[i+1] = 1 ) ) ) then
		begin
			a[i+1] := 2;
			if ( a[i-1] <> 1 ) then
				dec( ans );
		end;
		
	writeln( ans );
end.