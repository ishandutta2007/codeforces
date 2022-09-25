program problem3;
uses math;

const	md =	1000000007;

var	x, y: array[ 0..301 ] of int64;
	d: array[ 0..301, 0..301 ] of boolean;
	dp: array[ 1..300, 1..300 ] of longInt;
	ss: array[ 0..300 ] of int64;
	n: longInt;
	s: int64;
	
function getSquare( l, r: longInt ): int64;
var	res: int64;
begin
	res := int64( x[r] * y[l] ) - ( y[r] * x[l] ) + ss[r] - ss[l];
	if ( r < l ) then
		inc( res, ss[n] );

	exit( res );
end;

function multVector( p1, p2, p3: longInt ): longInt;
var	res: int64;
begin
	res := int64( x[p2] - x[p1] ) * ( y[p3] - y[p1] ) - int64( x[p3] - x[p1] ) * ( y[p2] - y[p1] );
	
	if ( res < 0 ) then
		exit( -1 )
	else if ( res > 0 ) then
		exit( 1 )
	else
		exit( 0 );
end;

function checkCross( p1, p2, p3, p4: longInt ): boolean;
var	res: boolean;
begin
	res := true;
	res := res and ( max( min( x[p1], x[p2] ), min( x[p3], x[p4] ) ) <= min( max( x[p1], x[p2] ), max( x[p3], x[p4] ) ) );
	res := res and ( max( min( y[p1], y[p2] ), min( y[p3], y[p4] ) ) <= min( max( y[p1], y[p2] ), max( y[p3], y[p4] ) ) );
	res := res and ( ( multVector( p1, p2, p3 ) * multVector( p1, p2, p4 ) ) <= 0 );
	res := res and ( ( multVector( p3, p4, p1 ) * multVector( p3, p4, p2 ) ) <= 0 );
	
	exit( res );
end;
	
function checkDiagonal( p1, p2: longInt ): boolean;
var	i: longInt;
	s1, s2: int64;
begin
	s1 := getSquare( p1, p2 );
	s2 := getSquare( p2, p1 );
	if ( s1 = 0 ) or ( s2 = 0 ) or ( ( s > 0 ) <> ( s1 > 0 ) ) or ( ( s > 0 ) <> ( s2 > 0 ) ) or ( ( s1 + s2 ) <> s ) then
		exit( false );

	for i := 1 to n do
		if ( i <> p1 ) and ( i <> p2 ) and ( (i-1) <> (p1 mod n) ) and ( (i-1) <> (p2 mod n) ) and ( checkCross( p1, p2, i, (i-1) ) ) then
			exit( false );

	exit( true );
end;

function calc( l, r: longInt ): int64;
var	i: longInt;
begin
	if ( (r-l+1) <= 3 ) then
		exit( 1 );

	if ( dp[l][r] = -1 ) then
	begin
		dp[l][r] := 0;
		for i := (l+1) to (r-1) do
			if ( d[l][i] ) and ( d[r][i] ) then
				dp[l][r] := ( dp[l][r] + ( calc( l, i ) * calc( i, r ) ) ) mod md;
	end;

	exit( dp[l][r] );
end;

var	i, j, k: longInt;

begin
	fillchar( d, sizeOf(d), 0 );
	fillDWord( dp, sizeOf(dp) div sizeOf(dp[1][1]), longWord(-1) );

	readln( n );
	for i := 1 to n do
		readln( x[i], y[i] );

	x[0] := x[n];
	y[0] := y[n];
	
	ss[0] := 0;
	for i := 1 to n do
		ss[i] := ss[i-1] + ( int64( x[i-1] * y[i] ) - ( y[i-1] * x[i] ) );

	s := getSquare( 1, n );
		
	k := 0;
	for i := 1 to n do
		for j := (i+2) to n do
			if ( not ( ( i = 1 ) and ( j = n ) ) ) and ( checkDiagonal( i, j ) ) then
			begin
				inc( k );
				d[i][j] := true;
				d[j][i] := true;
			end;

	for i := 1 to n do
	begin
		d[i][i-1] := true;
		d[i][i+1] := true;
	end;
	d[1][n] := true;
	d[n][1] := true;

	writeln( calc( 1, n ) );
end.