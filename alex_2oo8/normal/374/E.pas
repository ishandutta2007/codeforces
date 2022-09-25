program problem5;
uses math;

var	n, m: longInt;
	x, y, xl, xr, yl, yr: array[ 0..1, 1..2000 ] of longInt;
	used: array[ 1..2000, 1..2000 ] of boolean;
	s: array[ 1..2000 ] of longInt;
	
function intersects( a, b: longInt ): boolean;
var	res: boolean;
begin
	res := ( xl[0][a] < xr[0][a] ) and ( xl[1][b] < xr[1][b] );
	res := res and ( xl[1][b] + yl[1][b] <= xl[0][a] + yl[0][a] ) and ( xr[1][b] + yr[1][b] >= xl[0][a] + yl[0][a] );
	res := res and ( xl[0][a] - yl[0][a] <= xl[1][b] - yl[1][b] ) and ( xr[0][a] - yr[0][a] >= xl[1][b] - yl[1][b] );
	
	exit( res );
end;
	
function check( t: longInt ): boolean;
var	i, j, jj, k: longInt;
begin
	fillchar( used, sizeOf(used), 0 );

	for i := 1 to n do
	begin
		xl[0][i] := x[0][i] - t;
		yl[0][i] := y[0][i] + t;
		
		xr[0][i] := x[0][i] + t;
		yr[0][i] := y[0][i] - t;
	end;
	
	for i := 1 to n do
		for j := 1 to i - 1 do
			if ( x[0][i] + y[0][i] = x[0][j] + y[0][j] ) and ( max( xl[0][i], xl[0][j] ) <= min( xr[0][i], xr[0][j] ) ) then
			begin
				if ( xl[0][j] < xl[0][i] ) then
				begin
					xl[0][i] := xl[0][j];
					yl[0][i] := yl[0][j];
				end;
				
				if ( xr[0][j] > xr[0][i] ) then
				begin
					xr[0][i] := xr[0][j];
					yr[0][i] := yr[0][j];
				end;
				
				xl[0][j] := 0;
				yl[0][j] := 0;
				xr[0][j] := 0;
				yr[0][j] := 0;
			end;
			
	for i := 1 to m do
	begin
		xl[1][i] := x[1][i] - t;
		yl[1][i] := y[1][i] - t;
		
		xr[1][i] := x[1][i] + t;
		yr[1][i] := y[1][i] + t;
	end;
	
	for i := 1 to m do
		for j := 1 to i - 1 do
			if ( x[1][i] - y[1][i] = x[1][j] - y[1][j] ) and ( max( xl[1][i], xl[1][j] ) <= min( xr[1][i], xr[1][j] ) ) then
			begin
				if ( xl[1][j] < xl[1][i] ) then
				begin
					xl[1][i] := xl[1][j];
					yl[1][i] := yl[1][j];
				end;
				
				if ( xr[1][j] > xr[1][i] ) then
				begin
					xr[1][i] := xr[1][j];
					yr[1][i] := yr[1][j];
				end;
				
				xl[1][j] := 0;
				yl[1][j] := 0;
				xr[1][j] := 0;
				yr[1][j] := 0;
			end;
			
	for i := 1 to n do
	begin
		k := 0;
		for j := 1 to m do
			if ( intersects( i, j ) ) then
			begin
				inc( k );
				s[k] := j;
			end;

		for j := 1 to k do
			for jj := j + 1 to k do
				if ( used[ s[j] ][ s[jj] ] ) then
					exit( true )
				else
				begin
					used[ s[j] ][ s[jj] ] := true;
					used[ s[jj] ][ s[j] ] := true;
				end;
	end;
	
	exit( false );
end;

var	l, r, c, i: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( x[0][i], y[0][i] );

	for i := 1 to m do
		readln( x[1][i], y[1][i] );
		
	if ( not check( 1000000 ) ) then
	begin
		writeln( 'Poor Sereja!' );
		halt;
	end;
	
	r := 1;
	while ( not check(r) ) do
		r := 2 * r;
	
	l := r div 2 + 1;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( check(c) ) then
			r := c
		else
			l := c + 1;
	end;
	
	writeln( l );
end.