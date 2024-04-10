program problem3;
uses math;

const	inf =	10000000;

var	f: array[ 0..1001, 0..1001 ] of char;
	dp: array[ 0..1001, 0..1001 ] of longInt;
	next: array[ 'A'..'Z' ] of char;
	
function calc( x, y: longInt ): longInt;
var	dx, dy, res: longInt;
begin
	if ( dp[x][y] = -1 ) then
		exit( inf )
	else if ( dp[x][y] = 0 ) then
	begin
		dp[x][y] := -1;

		res := 1;
		
		for dx := -1 to 1 do
			for dy := -1 to 1 do
				if ( abs(dx) + abs(dy) = 1 ) and ( f[x+dx][y+dy] = next[ f[x][y] ] ) then
					res := max( res, calc( x + dx, y + dy ) + 1 );
					
		dp[x][y] := min( inf, res );
	end;
	
	exit( dp[x][y] );
end;

var	n, m, i, j, ans: longInt;

begin
	fillchar( f, sizeOf(f), '#' );
	fillchar( dp, sizeOf(dp), 0 );
	
	next['D'] := 'I';
	next['I'] := 'M';
	next['M'] := 'A';
	next['A'] := 'D';

	readln( n, m );
	for i := 1 to n do
	begin
		for j := 1 to m do
			read( f[i][j] );
		readln();
	end;

	ans := 0;
	for i := 1 to n do
		for j := 1 to m do
			if ( f[i][j] = 'D' ) then
				ans := max( ans, calc( i, j ) );
				
	if ( ans < 4 ) then
		writeln( 'Poor Dima!' )
	else if ( ans >= inf ) then
		writeln( 'Poor Inna!' )
	else
		writeln( ans div 4 );
end.