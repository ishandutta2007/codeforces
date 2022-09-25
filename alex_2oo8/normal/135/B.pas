program problem2;
uses math;

const	eps =	1.0e-8;

var	x, y, p: array[ 1..8 ] of longInt;

procedure getSides( t: longInt; var a, b, c, d, s: extended );
var	xx, yy: array[ 1..4 ] of longInt;

function dd( i1, i2: longInt ): extended;
begin
	s := s + ( ( ( xx[i1] * yy[i2] ) - ( xx[i2] * yy[i1] ) ) / 2 );

	exit( sqrt( sqr( xx[i1] - xx[i2] ) + sqr( yy[i1] - yy[i2] ) ) );
end;

function multVector( p1, p2, p3: longInt ): int64;
begin
	exit( ( xx[p2] - xx[p1] ) * ( yy[p3] - yy[p1] ) - ( xx[p3] - xx[p1] ) * ( yy[p2] - yy[p1] ) );
end;

function checkCross( p1, p2, p3, p4: longInt ): boolean;
var	res: boolean;
begin
	res := true;
	res := res and ( max( min( xx[p1], xx[p2] ), min( xx[p3], xx[p4] ) ) <= min( max( xx[p1], xx[p2] ), max( xx[p3], xx[p4] ) ) );
	res := res and ( max( min( yy[p1], yy[p2] ), min( yy[p3], yy[p4] ) ) <= min( max( yy[p1], yy[p2] ), max( yy[p3], yy[p4] ) ) );
	res := res and ( ( multVector( p1, p2, p3 ) * multVector( p1, p2, p4 ) ) <= 0 );
	res := res and ( ( multVector( p3, p4, p1 ) * multVector( p3, p4, p2 ) ) <= 0 );
	
	exit( res );
end;

var	i, k: longInt;
begin
	a := -1.0;
	b := -2.0;
	c := 1.0;
	d := 2.0;
	
	k := 0;
	for i := 1 to 8 do
		if ( t = p[i] ) then
		begin
			inc( k );
			xx[k] := x[i];
			yy[k] := y[i];
		end;
		
	s := 0;
		
	if ( checkCross( 1, 2, 3, 4 ) ) then
	begin
		a := dd( 1, 3 );
		b := dd( 3, 2 );
		c := dd( 2, 4 );
		d := dd( 4, 1 );
	end;
	
	if ( checkCross( 1, 3, 2, 4 ) ) then
	begin
		a := dd( 1, 2 );
		b := dd( 2, 3 );
		c := dd( 3, 4 );
		d := dd( 4, 1 );
	end;
	
	if ( checkCross( 1, 4, 2, 3 ) ) then
	begin
		a := dd( 1, 2 );
		b := dd( 2, 4 );
		c := dd( 4, 3 );
		d := dd( 3, 1 );
	end;
	
	s := abs(s);
end;

function check(): boolean;
var	a, b, c, d, s: extended;
begin
	getSides( 0, a, b, c, d, s );
	if ( abs( a - b ) > eps ) or ( abs( a - c ) > eps ) or ( abs( a - d ) > eps ) or ( abs( s - sqr(a) ) > eps ) then
		exit( false );
		
	getSides( 1, a, b, c, d, s );
	if ( abs( a - c ) > eps ) or ( abs( b - d ) > eps ) or ( abs( s - ( a * b ) ) > eps ) then
		exit( false );
		
	exit( true );
end;

var	i, j, k: longInt;

begin
	for i := 1 to 8 do
		readln( x[i], y[i] );
		
	for i := 0 to 255 do
	begin
		k := 0;
		for j := 1 to 8 do
		begin
			p[j] := ( i shr (j-1) ) and 1;
			inc( k, p[j] );
		end;
		
		if ( k = 4 ) and ( check() ) then
		begin
			writeln( 'YES' );
			for j := 1 to 8 do
				if ( p[j] = 0 ) then
					write( j, ' ' );
			writeln();
			
			for j := 1 to 8 do
				if ( p[j] = 1 ) then
					write( j, ' ' );
			writeln();
			
			halt;
		end;
	end;
	
	writeln( 'NO' );
end.