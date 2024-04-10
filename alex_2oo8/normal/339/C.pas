program problem3;

var	dp: array[ 1..1000, 1..10, 1..10 ] of longInt;

procedure writeAnswer( i, j, k: longInt );
begin
	if ( i = 1 ) then
	begin
		write( k, ' ' );
		exit();
	end;
		
	writeAnswer( i - 1, k - j, dp[i][j][k] );
	
	write( k, ' ' );
end;

var	n, i, j, k, q, jj, kk: longInt;
	p: array[ 1..10 ] of char;

begin
	for i := 1 to 10 do
		read( p[i] );

	readln( n );
	
	for i := 1 to 10 do
		if ( p[i] = '1' ) then
			dp[1][i][i] := i;
			
	for i := 1 to n - 1 do
		for j := 1 to 9 do
			for k := 1 to 10 do
				for q := j + 1 to 10 do
					if ( dp[i][j][k] > 0 ) and ( p[q] = '1' ) and ( q <> k ) then
						dp[i+1][q-j][q] := k;

	jj := -1;
	for j := 1 to 10 do
		for k := 1 to 10 do
			if ( dp[n][j][k] > 0 ) then
			begin
				jj := j;
				kk := k;
			end;
			
	if ( jj = -1 ) then
	begin
		writeln( 'NO' );
		halt;
	end;
	
	writeln( 'YES' );
	writeAnswer( n, jj, kk );
	writeln();
end.