program problem2;

type	tTreeRec =	record
						l, r, lSon, rSon, sum: longInt;
					end;
					
var	t: array[ 1..1000000 ] of tTreeRec;
	tw: longInt = 0;
					
function new( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	t[res].sum := 0;
	
	if ( l = r ) then
	begin
		t[res].lSon := 0;
		t[res].rSon := 0;
	end
	else
	begin
		t[res].lSon := new( l, ( l + r ) div 2 );
		t[res].rSon := new( ( l + r ) div 2 + 1, r );
	end;
	
	exit( res );
end;

procedure t_update( s, p, val: longInt );
begin
	if ( t[s].l = t[s].r ) then
	begin
		t[s].sum := val;
		exit();
	end;
	
	if ( p <= t[ t[s].lSon ].r ) then
		t_update( t[s].lSon, p, val )
	else
		t_update( t[s].rSon, p, val );
		
	t[s].sum := t[ t[s].lSon ].sum + t[ t[s].rSon ].sum;
end;

function t_read( s, l, r: longInt ): int64;
var res: int64;
begin
	if ( l > r ) then
		exit( 0 );

	if ( t[s].l >= l ) and ( t[s].r <= r ) then
		exit( t[s].sum );
		
	res := 0;
	if ( t[ t[s].lSon ].r >= l ) then
		inc( res, t_read( t[s].lSon, l, r ) );
		
	if ( t[ t[s].rSon ].l <= r ) then
		inc( res, t_read( t[s].rSon, l, r ) );
		
	exit( res );
end;

var	n, q, i, p, x, y, tmp: longInt;
	a, b: array[ 1..300000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( a[i] );
		
		b[ a[i] ] := i;
	end;
	
	new( 1, n );
	for i := 2 to n do
		if ( b[i] < b[i-1] ) then
			t_update( 1, i, 1 );
	
	readln( q );
	for i := 1 to q do
	begin
		readln( p, x, y );
		
		if ( p = 1 ) then
			writeln( t_read( 1, x + 1, y ) + 1 )
		else
		begin
			tmp := a[x];
			a[x] := a[y];
			a[y] := tmp;
			
			b[ a[x] ] := x;
			b[ a[y] ] := y;
			
			if ( a[x] > 1 ) then
			begin
				if ( b[ a[x] ] < b[ a[x] - 1 ] ) then
					t_update( 1, a[x], 1 )
				else
					t_update( 1, a[x], 0 );
			end;
			
			if ( a[x] < n ) then
			begin
				if ( b[ a[x] + 1 ] < b[ a[x] ] ) then
					t_update( 1, a[x] + 1, 1 )
				else
					t_update( 1, a[x] + 1, 0 );
			end;
			
			if ( a[y] > 1 ) then
			begin
				if ( b[ a[y] ] < b[ a[y] - 1 ] ) then
					t_update( 1, a[y], 1 )
				else
					t_update( 1, a[y], 0 );
			end;
			
			if ( a[y] < n ) then
			begin
				if ( b[ a[y] + 1 ] < b[ a[y] ] ) then
					t_update( 1, a[y] + 1, 1 )
				else
					t_update( 1, a[y] + 1, 0 );
			end;
		end;
	end;
end.