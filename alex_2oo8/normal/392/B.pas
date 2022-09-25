program problem2;
uses math;

var	t: array[ 1..3, 1..3 ] of longInt;
	f: array[ 1..3, 1..3, 1..40 ] of int64;

function calc( l, r, k: longInt ): int64;
begin
	if ( k = 0 ) then
		exit( 0 );
	
	if ( f[l][r][k] = -1 ) then
		f[l][r][k] := min	(
								calc( l, l xor r, k - 1 ) + t[l][r] + calc( l xor r, r, k - 1 ),
								2 * calc( l, r, k - 1 ) + t[l][l xor r] + calc( r, l, k - 1 ) + t[l xor r][r]
							);
	
	exit( f[l][r][k] );
end;
	
var	n, i, j, k: longInt;

begin
	for i := 1 to 3 do
		for j := 1 to 3 do
			read( t[i][j] );
			
	readln( n );
	
	for i := 1 to 3 do
		for j := 1 to 3 do
			for k := 1 to n do
				f[i][j][k] := -1;
	
	writeln( calc( 1, 3, n ) );
end.