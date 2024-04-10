program problem5;
uses math;

var	ans: array[ 0..101, 0..101 ] of char;
	used: array[ 'A'..'Z' ] of boolean;
	n, m: longInt;
	
function colorSquare( l, r, p, q: longInt; w: boolean ): char;
var	i, j: longInt;
	c: char;
begin
	fillchar( used, sizeOf(used), 0 );
	
	for i := l to r do
	begin
		used[ ans[i][p - 1] ] := true;
		used[ ans[i][q + 1] ] := true;
	end;
	
	for i := p to q do
	begin
		used[ ans[l - 1][i] ] := true;
		used[ ans[r + 1][i] ] := true;
	end;
	
	c := 'A';
	while ( used[c] ) do
		inc( c );
	
	if ( w ) then
		for i := l to r do
			for j := p to q do
				ans[i][j] := c;
	
	exit( c );
end;

procedure solve( x, y: longInt );
var	l, r, c: longInt;
begin
	if ( y > m ) then
	begin
		inc( x );
		y := 1;
	end;
	
	if ( x > n ) then
		exit();
	
	if ( ans[x][y] <> '#' ) then
	begin
		solve( x, y + 1 );
		
		exit();
	end;
	
	l := 1;
	r := 1;
	while ( y + r <= m ) and ( ans[x][y + r] = '#' ) do
		inc( r );
		
	r := min( r, n - x + 1 );

	if ( r = 1 ) or ( ( colorSquare( x, x, y + 1, y + 1, false ) < colorSquare( x, x, y, y, false ) ) ) then
	begin
		colorSquare( x, x, y, y, true );
		
		solve( x, y + 1 );
		
		exit();
	end;
	
	while ( l < r ) do
	begin
		c := (l + r + 1) div 2;
		
		if ( colorSquare( x, x + c - 1, y, y + c - 1, false ) = colorSquare( x, x, y, y, false ) ) then
			l := c
		else
			r := c - 1;
	end;
	
	colorSquare( x, x + l - 1, y, y + l - 1, true );
	
	solve( x, y + 1 );
end;

var i, j: longInt;

begin
	fillchar( ans, sizeOf(ans), '#' );

	readln( n, m );
	
	solve( 1, 1 );
	
	for i := 1 to n do
	begin
		for j := 1 to m do
			write( ans[i][j] );
		
		writeln();
	end;
end.