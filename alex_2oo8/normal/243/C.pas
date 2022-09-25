program problem3;

type	tQRec =	record
					d: char;
					x: longInt;
				end;
		tArr = array[ 1..3003 ] of int64;
		
var	q: array[ 1..1000 ] of tQRec;
		
procedure qsort( var arr: tArr; l, r: longWord );
var i, j: longInt;
	t, med: int64;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := arr[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( arr[i] < med ) do
				inc( i );
			while ( arr[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := arr[i];
				arr[i] := arr[j];
				arr[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( arr, l, j );
		qsort( arr, i, r );
	end;
end;

procedure doMove( i: longInt; var x, y: int64 );
begin
	if ( q[i].d = 'L' ) then
		dec( x, q[i].x )
	else if ( q[i].d = 'R' ) then
		inc( x, q[i].x )
	else if ( q[i].d = 'U' ) then
		inc( y, q[i].x )
	else
		dec( y, q[i].x );
end;

var	n, i, j, k, xCnt, yCnt, xi, yi, l, r: longInt;
	x, y, ans: int64;
	f: array[ 0..3004, 0..3004 ] of longInt;
	s: array[ 1..10000000, 0..1 ] of longInt;
	xArr, yArr: tArr;

begin
	fillchar( f, sizeOf(f), 0 );

	readln( n );
	
	x := 100001;
	y := 100001;
	
	xArr[3*n+1] := x;
	xArr[3*n+2] := x + 1;
	xArr[3*n+3] := x - 1;
	yArr[3*n+1] := y;
	yArr[3*n+2] := y + 1;
	yArr[3*n+3] := y - 1;
	
	for i := 1 to n do
	begin
		readln( q[i].d, q[i].x );
		
		doMove( i, x, y );
		
		xArr[i] := x;
		xArr[i+n] := x + 1;
		xArr[i+n+n] := x - 1;
		
		yArr[i] := y;
		yArr[i+n] := y + 1;
		yArr[i+n+n] := y - 1;
	end;
	
	qsort( xArr, 1, (3*n+3) );
	qsort( yArr, 1, (3*n+3) );
	
	xCnt := 1;
	for i := 2 to (3*n+3) do
		if ( xArr[i] <> xArr[xCnt] ) then
		begin
			inc( xCnt );
			xArr[xCnt] := xArr[i];
		end;
		
	yCnt := 1;
	for i := 2 to (3*n+3) do
		if ( yArr[i] <> yArr[yCnt] ) then
		begin
			inc( yCnt );
			yArr[yCnt] := yArr[i];
		end;

	for i := 1 to xCnt do
	begin
		f[i][0] := 1;
		f[i][yCnt+1] := 1;
	end;

	for i := 1 to yCnt do
	begin
		f[0][i] := 1;
		f[xCnt+1][i] := 1;
	end;

	x := 100001;
	y := 100001;

	xi := 1;
	while ( xArr[xi] < x ) do
		inc( xi );

	yi := 1;
	while ( yArr[yi] < y ) do
		inc( yi );

	for i := 1 to n do
	begin
		f[xi][yi] := 1;
		
		doMove( i, x, y );
		
		while ( xArr[xi] < x ) do
		begin
			inc( xi );
			f[xi][yi] := 1;
		end;
		
		while ( xArr[xi] > x ) do
		begin
			dec( xi );
			f[xi][yi] := 1;
		end;
		
		while ( yArr[yi] < y ) do
		begin
			inc( yi );
			f[xi][yi] := 1;
		end;
		
		while ( yArr[yi] > y ) do
		begin
			dec( yi );
			f[xi][yi] := 1;
		end;
	end;
	
	l := 1;
	r := 1;
	for i := 1 to xCnt do
	begin
		f[i][1] := -1;
		s[r][0] := i;
		s[r][1] := 1;
		inc( r );
		
		f[i][yCnt] := -1;
		s[r][0] := i;
		s[r][1] := yCnt;
		inc( r );
	end;
	
	for i := 2 to (yCnt-1) do
	begin
		f[1][i] := -1;
		s[r][0] := 1;
		s[r][1] := i;
		inc( r );
		
		f[xCnt][i] := -1;
		s[r][0] := xCnt;
		s[r][1] := i;
		inc( r );
	end;
	
	while ( l < r ) do
	begin
		x := s[l][0];
		y := s[l][1];
		
		if ( f[x-1][y] = 0 ) then
		begin
			f[x-1][y] := -1;
			s[r][0] := x - 1;
			s[r][1] := y;
			inc( r );
		end;
		
		if ( f[x+1][y] = 0 ) then
		begin
			f[x+1][y] := -1;
			s[r][0] := x + 1;
			s[r][1] := y;
			inc( r );
		end;
		
		if ( f[x][y-1] = 0 ) then
		begin
			f[x][y-1] := -1;
			s[r][0] := x;
			s[r][1] := y - 1;
			inc( r );
		end;
		
		if ( f[x][y+1] = 0 ) then
		begin
			f[x][y+1] := -1;
			s[r][0] := x;
			s[r][1] := y + 1;
			inc( r );
		end;
		
		inc( l );
	end;
	
	ans := 0;
	for i := 1 to xCnt do
		for j := 1 to yCnt do
			if ( f[i][j] >= 0 ) then
				inc( ans, ( int64( xArr[i+1] - xArr[i] ) * ( yArr[j+1] - yArr[j] ) ) );
				
	writeln( ans );
end.