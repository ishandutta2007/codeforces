program problem5;

const	sx = 1;
		sy = 2;
		dx = 3;
		dy = 4;
		it = 5;
		un = 6;
		
type	tArr =	array[ 1..6 ] of qWord;
		t2Arr =	array[ 1..6 ] of tArr;

var	n: longInt;

procedure init( var m: tArr; vdx, vdy, vsx, vsy, vit, vun: longInt );
begin
	m[dx] := vdx;
	m[dy] := vdy;
	m[sx] := vsx;
	m[sy] := vsy;
	m[it] := vit;
	m[un] := vun;
end;

procedure multiply( var res: t2Arr; const p, q: t2Arr );
var	i, j, k: longInt;
begin
	for i := 1 to 6 do
		for j := 1 to 6 do
		begin
			res[i][j] := 0;
			for k := 1 to 6 do
				res[i][j] := ( res[i][j] + p[i][k] * q[k][j] ) mod n;
		end;
end;

var	sxx, syy, dxx, dyy, i, x, y: longInt;
	matrix: array[ 0..60 ] of t2Arr;
	ansMatrix, newMatrix: t2Arr;
	t: int64;

begin
	readln( n, sxx, syy, dxx, dyy, t );
	
	if ( t = 0 ) then
	begin
		writeln( sxx, ' ', syy );
		halt;
	end;
	
	while ( dxx < 0 ) do
		inc( dxx, n );
		
	while ( dyy < 0 ) do
		inc( dyy, n );
	
	init( matrix[0][dx], 1, 0, 1, 1, 1, 0 );
	init( matrix[0][dy], 0, 1, 1, 1, 1, 0 );
	init( matrix[0][sx], 1, 0, 2, 1, 1, 0 );
	init( matrix[0][sy], 0, 1, 1, 2, 1, 0 );
	init( matrix[0][it], 0, 0, 0, 0, 1, 1 );
	init( matrix[0][un], 0, 0, 0, 0, 0, 1 );
	for i := 1 to 60 do
		multiply( matrix[i], matrix[i - 1], matrix[i - 1] );
			
	ansMatrix := matrix[0];
	dec( t, 1 );
	for i := 60 downto 0 do
		if ( t >= ( qWord(1) shl i ) ) then
		begin
			multiply( newMatrix, ansMatrix, matrix[i] );
				
			ansMatrix := newMatrix;
			
			dec( t, qWord(1) shl i );
		end;

	x := ( ansMatrix[sx][dx] * dxx + ansMatrix[sx][dy] * dyy + ansMatrix[sx][sx] * sxx + ansMatrix[sx][sy] * syy + ansMatrix[sx][un] ) mod n;
	y := ( ansMatrix[sy][dx] * dxx + ansMatrix[sy][dy] * dyy + ansMatrix[sy][sx] * sxx + ansMatrix[sy][sy] * syy + ansMatrix[sy][un] ) mod n;
	
	if ( x = 0 ) then
		x := n;
		
	if ( y = 0 ) then
		y := n;

	writeln( x, ' ', y );
end.