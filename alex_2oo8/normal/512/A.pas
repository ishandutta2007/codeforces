program problem1;
uses math;

var	n, i, j: longInt;
	s: array[ 1..100 ] of ansistring;
	b: array[ 1..100 ] of boolean;
	a: array[ 'a'..'z', 'a'..'z' ] of boolean;
	p, q, r: char;

begin
	readln( n );
	for i := 1 to n do
		readln( s[i] );
	
	for i := 1 to n - 1 do
	begin
		j := 1;
		while ( j <= min( length( s[i] ), length( s[i + 1] ) ) ) and ( s[i][j] = s[i + 1][j] ) do
			inc( j );
		
		if ( j > length( s[i + 1] ) ) then
		begin
			writeln( 'Impossible' );
			
			halt;
		end;
		
		if ( j <= length( s[i] ) ) then
			a[ s[i][j] ][ s[i + 1][j] ] := true;
	end;
	
	for p := 'a' to 'z' do
		for q := 'a' to 'z' do
			for r := 'a' to 'z' do
				a[q][r] := a[q][r] or ( a[q][p] and a[p][r] );
	
	for p := 'a' to 'z' do
		if ( a[p][p] ) then
		begin
			writeln( 'Impossible' );
			
			halt;
		end;
		
	for i := 1 to 26 do
	begin
		p := 'a';
		for q := 'a' to 'z' do
			if ( a[q][p] ) then
				p := q;
		
		for q := 'a' to 'z' do
		begin
			a[p][q] := false;
			a[q][p] := true;
		end;
		
		write( p );
	end;
	
	writeln();
end.