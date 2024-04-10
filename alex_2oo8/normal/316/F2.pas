program problem6;
uses math;

var	h, w, cnt, k: longInt;
	f, id: array[ 1..1600, 1..1600 ] of longInt;
	ans, sx, sy: array[ 1..100000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := ans[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( ans[i] < med ) do
				inc( i );
			while ( ans[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := ans[i];
				ans[i] := ans[j];
				ans[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

procedure init_DFS( x, y, idd: longInt );
begin
	if ( id[x][y] = idd ) then
		exit();
		
	id[x][y] := idd;
	inc( k );
	sx[k] := x;
	sy[k] := y;
	
	if ( x > 1 ) and ( f[x-1][y] = 1 ) then
		init_DFS( x - 1, y, idd );
	
	if ( x < h ) and ( f[x+1][y] = 1 ) then
		init_DFS( x + 1, y, idd );
		
	if ( y > 1 ) and ( f[x][y-1] = 1 ) then
		init_DFS( x, y - 1, idd );
	
	if ( y < w ) and ( f[x][y+1] = 1 ) then
		init_DFS( x, y + 1, idd );
end;

function count( x, y, idd: longInt ): longInt;
var	i, j, res: longInt;
begin
	res := 0;
	
	for i := 0 to min( 6, h - x ) do
		for j := 0 to min( 6, w - y ) do
			if ( id[x+i][y+j] = idd ) then
				inc( res );
				
	exit( res );
end;

procedure delete_square( x, y, idd: longInt );
var	i, j: longInt;
begin
	for i := 0 to min( 6, h - x ) do
		for j := 0 to min( 6, w - y ) do
			if ( id[x+i][y+j] = idd ) then
				f[x+i][y+j] := 0;
end;

function delete_DFS( x, y: longInt ): longInt;
var	res: longInt;
begin
	res := 1;

	f[x][y] := 0;
	
	if ( x > 1 ) and ( f[x-1][y] = 1 ) then
		inc( res, delete_DFS( x - 1, y ) );
	
	if ( x < h ) and ( f[x+1][y] = 1 ) then
		inc( res, delete_DFS( x + 1, y ) );
		
	if ( y > 1 ) and ( f[x][y-1] = 1 ) then
		inc( res, delete_DFS( x, y - 1 ) );
	
	if ( y < w ) and ( f[x][y+1] = 1 ) then
		inc( res, delete_DFS( x, y + 1 ) );
		
	exit( res );
end;

var	i, j, p: longInt;

begin
	readln( h, w );
	for i := 1 to h do
		for j := 1 to w do
			read( f[i][j] );
			
	cnt := 0;
	for i := 1 to h do
		for j := 1 to w do
			if ( f[i][j] = 1 ) then
			begin
				inc( cnt );
			
				k := 0;
				init_DFS( i, j, cnt );
				
				for p := 1 to k do
					if ( count( sx[p], sy[p], cnt ) = 49 ) then
						delete_square( sx[p], sy[p], cnt );
						
				ans[cnt] := 0;
				for p := 1 to k do
					if ( f[ sx[p] ][ sy[p] ] = 1 ) and ( delete_DFS( sx[p], sy[p] ) > 7 ) then
						inc( ans[cnt] );
			end;
			
	qsort( 1, cnt );
	
	writeln( cnt );
	for i := 1 to cnt do
		write( ans[i], ' ' );
	writeln();
end.