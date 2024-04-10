program problem2;

type	tPoint =	array[ 1..3 ] of int64;

const	bullshit: array[ 1..6, 1..3 ] of longInt = ((1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1));

var	dst: array[ 1..6 ] of int64;
	isSquare: array[ 1..8, 1..6, 2..8, 1..6, 3..8, 1..6, 4..8, 1..6 ] of boolean;
	shit, cnt: array[ 1..8 ] of longInt;

function dist( const a, b: tPoint ): int64;
begin
	exit( sqr( a[1] - b[1] ) + sqr( a[2] - b[2] ) + sqr( a[3] - b[3] ) );
end;

function checkSquare( const a, b, c, d: tPoint ): boolean;
var	i, j: longInt;
begin
	dst[1] := dist( a, b );
	dst[2] := dist( a, c );
	dst[3] := dist( a, d );
	dst[4] := dist( c, b );
	dst[5] := dist( d, b );
	dst[6] := dist( c, d );
	
	for i := 1 to 6 do
		for j := i + 1 to 6 do
			if ( dst[j] < dst[i] ) then
			begin
				dst[i] := dst[i] xor dst[j];
				dst[j] := dst[i] xor dst[j];
				dst[i] := dst[i] xor dst[j];
			end;
	
	exit( ( dst[1] = dst[4] ) and ( dst[5] = dst[6] ) and ( dst[6] = 2 * dst[1] ) );
end;

function isCube( j1, j2, j3, j4, j5, j6, j7, j8: longInt ): boolean;
var	i, j, k, l, x: longInt;
begin
	fillchar( cnt, sizeOf(cnt), 0 );

	shit[1] := j1;
	shit[2] := j2;
	shit[3] := j3;
	shit[4] := j4;
	shit[5] := j5;
	shit[6] := j6;
	shit[7] := j7;
	shit[8] := j8;
	
	x := 0;
	for i := 1 to 5 do
		for j := i + 1 to 6 do
			for k := j + 1 to 7 do
				for l := k + 1 to 8 do
					if ( isSquare[i][ shit[i] ][j][ shit[j] ][k][ shit[k] ][l][ shit[l] ] ) then
					begin
						inc( x );
						inc( cnt[i] );
						inc( cnt[j] );
						inc( cnt[k] );
						inc( cnt[l] );
					end;
	
	if ( x <> 6 ) then
		exit( false );
	
	for i := 1 to 8 do
		if ( cnt[i] <> 3 ) then
			exit( false );
		
	exit( true );
end;

var	i, j, k, i1, i2, i3, i4, j1, j2, j3, j4, j5, j6, j7, j8: longInt;
	perm: array[ 1..8, 1..6 ] of tPoint;

begin
	for i := 1 to 8 do
	begin
		readln( perm[i][1][1], perm[i][1][2], perm[i][1][3] );
		
		for j := 2 to 6 do
			for k := 1 to 3 do
				perm[i][j][k] := perm[i][1][ bullshit[j][k] ];
	end;
	
	for i1 := 1 to 8 do
		for i2 := i1 + 1 to 8 do
			for i3 := i2 + 1 to 8 do
				for i4 := i3 + 1 to 8 do
					for j1 := 1 to 6 do
						for j2 := 1 to 6 do
							for j3 := 1 to 6 do
								for j4 := 1 to 6 do
									isSquare[i1][j1][i2][j2][i3][j3][i4][j4] := checkSquare( perm[i1][j1], perm[i2][j2], perm[i3][j3], perm[i4][j4] );
	
	for j1 := 1 to 6 do
		for j2 := 1 to 6 do
			for j3 := 1 to 6 do
				for j4 := 1 to 6 do
					for j5 := 1 to 6 do
						for j6 := 1 to 6 do
							for j7 := 1 to 6 do
								for j8 := 1 to 6 do
									if ( isCube( j1, j2, j3, j4, j5, j6, j7, j8 ) ) then
									begin
										writeln( 'YES' );
										writeln( perm[1][j1][1], ' ', perm[1][j1][2], ' ', perm[1][j1][3] );
										writeln( perm[2][j2][1], ' ', perm[2][j2][2], ' ', perm[2][j2][3] );
										writeln( perm[3][j3][1], ' ', perm[3][j3][2], ' ', perm[3][j3][3] );
										writeln( perm[4][j4][1], ' ', perm[4][j4][2], ' ', perm[4][j4][3] );
										writeln( perm[5][j5][1], ' ', perm[5][j5][2], ' ', perm[5][j5][3] );
										writeln( perm[6][j6][1], ' ', perm[6][j6][2], ' ', perm[6][j6][3] );
										writeln( perm[7][j7][1], ' ', perm[7][j7][2], ' ', perm[7][j7][3] );
										writeln( perm[8][j8][1], ' ', perm[8][j8][2], ' ', perm[8][j8][3] );
										
										halt;
									end;
	
	writeln( 'NO' );
end.