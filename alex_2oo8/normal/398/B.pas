program problem2;

var	dp: array[ 0..2000, 0..2000 ] of extended;
	n: longInt;

function calc( r, c: longInt ): extended;
var	c1, c2: extended;
begin
	if ( ( r = 0 ) and ( c = 0 ) ) or ( r < 0 ) or ( c < 0 ) then
		exit( 0.0 );
	
	if ( dp[r][c] < 0 ) then
	begin
		c1 := ( (r * c) * calc(r - 1, c - 1) + r * (n - c) * calc(r - 1, c) + (n - r) * c * calc(r, c - 1) ) / sqr(n);
		c2 := (n - r) * (n - c) / sqr(n);
		
		dp[r][c] := ( 1 + c1 ) / ( 1 - c2 );
	end;
	
	exit( dp[r][c] );
end;

var	m, i, x, y, r, c: longInt;
	col, row: array[ 1..2000 ] of boolean;
	ans: extended;

begin
	fillchar( col, sizeOf(col), true );
	fillchar( row, sizeOf(row), true );
	
	readln( n, m );
	for i := 1 to m do
	begin
		readln( x, y );
		
		row[x] := false;
		col[y] := false;
	end;
	
	r := 0;
	c := 0;
	for i := 1 to n do
	begin
		if ( row[i] ) then
			inc( r );
		
		if ( col[i] ) then
			inc( c );
	end;
	
	for x := 0 to r do
		for y := 0 to c do
			dp[x][y] := -1.0;
			
	ans := calc( r, c );

	writeln( ans:0:15 );
end.