program problem3;
uses math;

var	n, m: longInt;
	a, b: array[ 1..1000 ] of ansistring;
	
function check( w, h: longInt ): longInt;
var	lx, rx, ly, ry, i, j: longInt;
begin
	b[1] := '';
	for i := 1 to m do
		b[1] := b[1] + '.';
	
	for i := 2 to n do
		b[i] := b[1];
	
	lx := 1;
	ly := 1;
	while ( a[lx][ly] = '.' ) do
	begin
		inc( ly );
		
		if ( ly > m ) then
		begin
			inc( lx );
			ly := 1;
		end;
	end;
	
	rx := lx + h - 1;
	ry := ly + w - 1;
	
	if ( rx > n ) or ( ry > m ) then
		exit( -1 );
	
	for i := lx to rx do
		for j := ly to ry do
			b[i][j] := 'X';
	
	while ( true ) do
	begin
		if ( ry < m ) and ( a[lx][ry + 1] = 'X' ) then
		begin
			inc( ly );
			inc( ry );
			
			for i := lx to rx do
				b[i][ry] := 'X';
		end
		else if ( rx < n ) and ( a[rx + 1][ly] = 'X' ) then
		begin
			inc( lx );
			inc( rx );
			
			for j := ly to ry do
				b[rx][j] := 'X';
		end
		else
			break;
	end;
	
	for i := 1 to n do
		for j := 1 to m do
			if ( a[i][j] <> b[i][j] ) then
			begin
				if ( b[i][j] = 'X' ) xor ( ( i > rx ) or ( j > ry ) ) then
					exit( -1 )
				else
					exit( 1 );
			end;
	
	exit( 0 );
end;

function fixWidth( w: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := n;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( check( w, c ) <= 0 ) then
			r := c
		else
			l := c + 1;
	end;
	
	if ( check( w, l ) = 0 ) then
		exit( w * l );
	
	exit( -1 );
end;
	
function fixHeight( h: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := m;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( check( c, h ) <= 0 ) then
			r := c
		else
			l := c + 1;
	end;

	if ( check( l, h ) = 0 ) then
		exit( l * h );
	
	exit( -1 );
end;
	
var	i, j, ans, x: longInt;
	lRow, rRow, lCol, rCol: array[ 1..1000 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( a[i] );
	
	for i := 1 to n do
	begin
		j := 1;
		while ( j <= m ) and ( a[i][j] = '.' ) do
			inc( j );
		
		lRow[i] := j;
		
		j := m;
		while ( j > 0 ) and ( a[i][j] = '.' ) do
			dec( j );
			
		rRow[i] := j;
		
		if ( j = 0 ) then
			lRow[i] := 0;
	end;
	
	for j := 1 to m do
	begin
		i := 1;
		while ( i <= n ) and ( a[i][j] = '.' ) do
			inc( i );
		
		lCol[j] := i;
		
		i := n;
		while ( i > 0 ) and ( a[i][j] = '.' ) do	
			dec( i );
		
		rCol[j] := i;
		
		if ( i = 0 ) then
			lCol[j] := 0;
	end;
	
	i := 1;
	while ( lRow[i] = 0 ) do
		inc( i );
		
	j := 1;
	while ( lCol[j] = 0 ) do
		inc( j );
	
	ans := -1;
	
	x := fixWidth( rRow[i] - lRow[i] + 1 );
	if ( x <> -1 ) and ( ( ans = -1 ) or ( x < ans ) ) then
		ans := x;
	
	x := fixHeight( rCol[j] - lCol[j] + 1 );
	if ( x <> -1 ) and ( ( ans = -1 ) or ( x < ans ) ) then
		ans := x;
	
	writeln( ans );
end.