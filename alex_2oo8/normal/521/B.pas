program problem2;

const	md =	1000000009;

type	tNode =	record
					x, y, id: longInt;
				end;
		tArr =	array[ 1..100000 ] of longInt;
				
var	a: array[ 1..100000 ] of tNode;
	n: longInt;
	
procedure upd( var fwt: tArr; x, d: longInt );
begin
	while ( x <= n ) do
	begin
		inc( fwt[x], d );
		
		inc( x, x and -x );
	end;
end;

function get( var fwt: tArr ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 20 downto 0 do
		if ( res + (1 shl i) <= n ) and ( fwt[res + 1 shl i] = 0 ) then
			inc( res, 1 shl i );
	
	exit( res + 1 );
end;
	
function less( const a, b: tNode ): boolean;
begin
	if ( a.x = b.x ) then
		exit( a.y < b.y )
	else
		exit( a.x < b.x );
end;
	
procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tNode;
begin
	if ( l > r ) then
		exit();
	
	i := l;
	j := r;
	med := a[ l + random(r - l + 1) ];
	while ( i <= j ) do
	begin
		while ( less( a[i], med ) ) do
			inc( i );
		while ( less( med, a[j] ) ) do
			dec( j );
		
		if ( i <= j ) then
		begin
			t := a[i];
			a[i] := a[j];
			a[j] := t;
			
			inc( i );
			dec( j );
		end;
	end;
	
	qsort( l, j );
	qsort( i, r );
end;

function find( x, y: longInt ): longInt;
var	p: tNode;
	i, res: longInt;
begin
	p.x := x;
	p.y := y;

	res := 0;
	for i := 20 downto 0 do
		if ( res + (1 shl i) < n ) and ( less( a[res + 1 shl i], p ) ) then
			inc( res, 1 shl i );
	
	inc( res );
	
	if ( a[res].x = x ) and ( a[res].y = y ) and ( a[res].id > 0 ) then
		exit( res )
	else
		exit( -1 );
end;

function check( const p: tNode ): longInt;
var	a, b, c, i: longInt;
begin
	if ( p.y = 0 ) then
		exit( -1 );
	
	b := 0;
	for i := -1 to 1 do
	begin
		a := find( p.x + i, p.y - 1 );
		if ( a > 0 ) then
		begin
			inc( b );
			c := a;
		end;
	end;
	
	if ( b = 1 ) then
		exit( c )
	else
		exit( -1 );
end;

function canAdd( id: longInt ): boolean;
var	i, x: longInt;
begin
	for i := -1 to 1 do
	begin
		x := find( a[id].x + i, a[id].y + 1 );
		if ( x > 0 ) and ( check( a[x] ) = id ) then
			exit( false );
	end;
	
	exit( true );
end;

var	i, ans, x, y, j: longInt;
	f, f1, f2, w: tArr;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( a[i].x, a[i].y );
		
		a[i].id := i;
	end;
	
	qsort( 1, n );
	
	for i := 1 to n do
		w[ a[i].id ] := i;
	
	for i := 1 to n do
	begin
		f[i] := 1;
		
		upd( f1, i, +1 );
		upd( f2, i, +1 );
	end;
	
	for i := 1 to n do
	begin
		x := check( a[i] );
		
		if ( x = -1 ) or ( f[x] = 0 ) then
			continue;
		
		f[x] := 0;
		upd( f1, a[x].id, -1 );
		upd( f2, n + 1 - a[x].id, -1 );
	end;
	
	ans := 0;
	for i := 1 to n do
	begin
		if ( odd(i) ) then
			x := w[ n + 1 - get( f2 ) ]
		else
			x := w[ get( f1 ) ];
		
		ans := ( ans * int64(n) + a[x].id - 1 ) mod md;
		
		f[x] := 0;
		upd( f1, a[x].id, -1 );
		upd( f2, n + 1 - a[x].id, -1 );
		a[x].id := -1;
		
		for j := -1 to 1 do
		begin
			y := find( a[x].x + j, a[x].y + 1 );
			
			if ( y = -1 ) then
				continue;
			
			y := check( a[y] );
			
			if ( y = -1 ) or ( f[y] = 0 ) then
				continue;
			
			f[y] := 0;
			upd( f1, a[y].id, -1 );
			upd( f2, n + 1 - a[y].id, -1 );
		end;
		
		for j := -1 to 1 do
		begin
			y := find( a[x].x + j, a[x].y - 1 );
			if ( y = -1 ) or ( f[y] = 1 ) then
				continue;
			
			if ( canAdd( y ) ) then
			begin
				f[y] := 1;
				upd( f1, a[y].id, +1 );
				upd( f2, n + 1 - a[y].id, +1 );
			end;
		end;
	end;
	
	writeln( ans );
end.