program problem4;
uses math, sysUtils, dateUtils;

var	n: longInt;
	x1, y1, x2, y2: array[ 1..100000 ] of longInt;
	f, g, h: array[ -3001..3001, -1..3000 ] of int64;
	
procedure check( xl, yl, xr, yr: longInt );
var	s, k, i: longInt;
begin
	k := 0;
	s := 0;
	for i := 1 to n do
		if ( x1[i] >= xl ) and ( x1[i] < xr ) and ( y1[i] >= yl ) and ( y1[i] < yr ) and ( x2[i] > xl ) and ( x2[i] <= xr ) and ( y2[i] > yl ) and ( y2[i] <= yr ) then
		begin
			inc( s, ( ( x2[i] - x1[i] ) * ( y2[i] - y1[i] ) ) );

			inc( k );
		end;

	if ( s <> ( xr - xl ) * ( yr - yl ) ) then
		exit;

	writeln( 'YES ', k );
	for i := 1 to n do
		if ( x1[i] >= xl ) and ( x1[i] < xr ) and ( y1[i] >= yl ) and ( y1[i] < yr ) and ( x2[i] > xl ) and ( x2[i] <= xr ) and ( y2[i] > yl ) and ( y2[i] <= yr ) then
			write( i, ' ' );
			
	writeln;
	
	halt;
end;

var	i, x, y, xm, ym, s, d: longInt;
	a: array[ 1..10000000 ] of int64;
	start: tDateTime;
	ss: int64;

begin
	start := now();

	readln( n );
	for i := 1 to n do
		readln( x1[i], y1[i], x2[i], y2[i] );
		
	for i := 1 to n do
		if ( x2[i] - x1[i] = y2[i] - y1[i] ) then
		begin
			writeln( 'YES 1' );
			writeln( i );
		
			halt;
		end;
	
	for x := -1 to 3000 do
		for y := -1 to 3000 do
			f[x][y] := random( 400000000 ) - 200000000;

	for i := 1 to n do
	begin
		ss := 0;
		for s := 1 to ( x2[i] - x1[i] ) * ( y2[i] - y1[i] ) do
		begin
			a[s] := -200000000 - ss + random( 400000000 );
			
			inc( ss, a[s] );
		end;

		dec( a[1], ss );
	
		s := 0;
		for x := x1[i] to x2[i] - 1 do
			for y := y1[i] to y2[i] - 1 do
			begin
				inc( s );
				
				f[x][y] := a[s];
			end;
				
	end;

	for x := 0 to 3000 do
		for y := 0 to 3000 do
			f[x][y] := f[x][y] + f[x-1][y] + f[x][y-1] - f[x-1][y-1];
	
	for x := -1 to 3000 do
		for y := -1 to 3000 do
		begin
			g[x][y] := f[y][x];
			h[x - y][x] := f[x][y];
		end;
			
	for i := 1 to n do
	begin
		if ( millisecondsBetween(start, now) > 1450 ) then
			break;
	
		x := x1[i];
		y := y1[i];
		xm := x - 1;
		ym := y - 1;
		ss := -f[xm][ym];
		d := x - y;
		for s := max(x2[i] - x, y2[i] - y) - 1 to 3000 - max(x, y) - 1 do
			if ( ss + f[xm][y + s] + g[ym][x + s] = h[d][x + s] ) then
				check( x, y, x + s + 1, y + s + 1 );
	end;

	writeln( 'NO' );
end.