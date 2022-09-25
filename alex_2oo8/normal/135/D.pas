program problem4;

var	n, m, r: longInt;
	a: array[ 0..1001, 0..1001 ] of char;
	b: array[ 0..1001, 0..1001 ] of longInt;
	s: array[ 1..1000000, 0..1 ] of longInt;
	ok: boolean;
	
procedure DFS( x, y, k: longInt );
var	i, j: longInt;
begin
	b[x][y] := 1;
	
	if ( x = 1 ) or ( y = 1 ) or ( x = n ) or ( y = m ) then
		ok := false;
	
	for i := -1 to 1 do
		for j := -1 to 1 do
			if ( a[x+i][y+j] = '0' ) and ( b[x+i][y+j] = 0 ) then
				DFS( (x+i), (y+j), k )
			else if ( a[x+i][y+j] = '1' ) and ( b[x+i][y+j] <> k ) then
			begin
				inc( r );
				s[r][0] := x + i;
				s[r][1] := y + j;
				
				b[x+i][y+j] := k;
			end;
end;

procedure DFS2( x, y: longInt );
var	k: longInt;
begin
	k := b[x][y];
	inc( b[x][y] );
	
	if ( b[x-1][y] = k ) then
		DFS2( (x-1), y );
		
	if ( b[x+1][y] = k ) then
		DFS2( (x+1), y );
		
	if ( b[x][y-1] = k ) then
		DFS2( x, (y-1) );
		
	if ( b[x][y+1] = k ) then
		DFS2( x, (y+1) );
end;

function check( var k: longInt ): boolean;
var	i, p: longInt;
begin
	DFS2( s[1][0], s[1][1] );
	
	inc( k );
	for i := 1 to r do
	begin
		p := 0;
		
		if ( b[ s[i][0] - 1 ][ s[i][1] ] = k ) then
			inc( p );
			
		if ( b[ s[i][0] + 1 ][ s[i][1] ] = k ) then
			inc( p );
			
		if ( b[ s[i][0] ][ s[i][1] - 1 ] = k ) then
			inc( p );
			
		if ( b[ s[i][0] ][ s[i][1] + 1 ] = k ) then
			inc( p );
			
		if ( p <> 2 ) or ( b[ s[i][0] ][ s[i][1] ] <> k ) then
			exit( false );
	end;
	
	exit( true );
end;

var	i, j, k, ans: longInt;

begin
	fillchar( a, sizeOf(a), '#' );

	readln( n, m );
	for i := 1 to n do
	begin
		for j := 1 to m do
			read( a[i][j] );
		readln();
	end;
		
	ans := 0;
	for i := 2 to n do
		for j := 2 to m do
			if ( a[i][j] = '1' ) and ( a[i-1][j] = '1' ) and ( a[i][j-1] = '1' ) and ( a[i-1][j-1] = '1' ) then
				ans := 4;
				
	k := 5;
	for i := 1 to n do
		for j := 1 to m do
			if ( a[i][j] = '0' ) and ( b[i][j] = 0 ) then
			begin
				ok := true;
				r := 0;
				inc( k );
				DFS( i, j, k );
				
				if ( r > ans ) and ( ok ) and ( check( k ) ) then
					ans := r;
			end;
			
	writeln( ans );
end.