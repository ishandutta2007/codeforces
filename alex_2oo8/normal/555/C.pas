program problem3;
uses math;

type	tTreeNode =	record
						l, r, lSon, rSon, mx: longInt;
					end;

var	t: array[ 1..10000000 ] of tTreeNode;

function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
begin
	inc( tw );
	t[tw].l := l;
	t[tw].r := r;
	
	exit( tw );
end;

function get( v, x: longInt ): longInt;
begin
	if ( t[v].l = t[v].r ) then
		exit( t[v].mx );
	
	if ( t[v].lSon > 0 ) and ( x <= t[ t[v].lSon ].r ) then
		exit( max( t[v].mx, get( t[v].lSon, x ) ) );
	
	if ( t[v].rSon > 0 ) and ( x >= t[ t[v].rSon ].l ) then
		exit( max( t[v].mx, get( t[v].rSon, x ) ) );
	
	exit( t[v].mx );
end;

procedure update( v, l, r, val: longInt );
var	c: longInt;
begin
	if ( l <= t[v].l ) and ( t[v].r <= r ) then
	begin
		t[v].mx := max( t[v].mx, val );
		
		exit();
	end;
	
	c := ( t[v].l + t[v].r ) div 2;
	
	if ( c >= l ) then
	begin
		if ( t[v].lSon = 0 ) then
			t[v].lSon := build_tree( t[v].l, c );
	
		update( t[v].lSon, l, r, val );
	end;
	
	if ( c + 1 <= r ) then
	begin
		if ( t[v].rSon = 0 ) then
			t[v].rSon := build_tree( c + 1, t[v].r );
	
		update( t[v].rSon, l, r, val );
	end;
end;

var	n, m, i, x, y, ans: longInt;
	c: char;

begin
	readln( n, m );
	
	build_tree( 1, n );
	build_tree( 1, n );
	
	for i := 1 to m do
	begin
		readln( x, y, c, c );
		
		if ( c = 'U' ) then
		begin
			ans := get( 1, x );
			
			update( 2, ans, y, x );
			update( 1, x, x, y );
			
			ans := y - ans;
		end
		else
		begin
			ans := get( 2, y );
			
			update( 1, ans, x, y );
			update( 2, y, y, x );
			
			ans := x - ans;
		end;
		
		writeln( ans );
	end;
end.