program problem4;
uses math;

type	tTreeNode =	record
						l, r, lSon, rSon, max: longInt;
						sum: int64;
					end;

var	t: array[ 1..300000 ] of tTreeNode;
	tw: longInt;
	
function build_tree( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	if ( l < r ) then
	begin
		t[res].lSon := build_tree( l, (l + r) div 2 );
		t[res].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	t[res].sum := 0;
	
	exit( res );
end;

procedure doModulo( v, l, r, x: longInt );
begin
	if ( t[v].max < x ) then
		exit();
	
	if ( t[v].l = t[v].r ) then
	begin
		t[v].sum := t[v].sum mod x;
		t[v].max := t[v].sum;
		exit();
	end;
	
	if ( t[ t[v].lSon ].r >= l ) then
		doModulo( t[v].lSon, l, r, x );
	
	if ( t[ t[v].rSon ].l <= r ) then
		doModulo( t[v].rSon, l, r, x );
	
	t[v].sum := t[ t[v].lSon ].sum + t[ t[v].rSon ].sum;
	t[v].max := max( t[ t[v].lSon ].max, t[ t[v].rSon ].max );
end;

function getSum( v, l, r: longInt ): int64;
var	res: int64;
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
		exit( t[v].sum );

	res := 0;
	if ( t[ t[v].lSon ].r >= l ) then
		inc( res, getSum( t[v].lSon, l, r ) );
	if ( t[ t[v].rSon ].l <= r ) then
		inc( res, getSum( t[v].rSon, l, r ) );
		
	exit( res );
end;

procedure setValue( v, x, y: longInt );
begin
	if ( t[v].l = t[v].r ) then
	begin
		t[v].sum := y;
		t[v].max := y;
		exit();
	end;
	
	if ( x <= t[ t[v].lSon ].r ) then
		setValue( t[v].lSon, x, y )
	else
		setValue( t[v].rSon, x, y );
	
	t[v].sum := t[ t[v].lSon ].sum + t[ t[v].rSon ].sum;
	t[v].max := max( t[ t[v].lSon ].max, t[ t[v].rSon ].max );
end;

var	n, m, i, tt, l, r, x, k: longInt;
	a: array[ 1..100000 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	build_tree( 1, n );
	
	for i := 1 to n do
		setValue( 1, i, a[i] );
	
	for i := 1 to m do
	begin
		read( tt );
		
		if ( tt = 1 ) then
		begin
			readln( l, r );
			
			writeln( getSum( 1, l, r ) );
		end
		else if ( tt = 2 ) then
		begin
			readln( l, r, x );
			
			doModulo( 1, l, r, x );
		end
		else
		begin
			readln( k, x );
			
			setValue( 1, k, x );
		end;
	end;
end.