program problem5;

type	tTreeRec =	record
						l, r, lSon, rSon, left, right: longInt;
						sum: int64;
					end;
					
var	t: array[ 1..5000000 ] of tTreeRec;
	tw: longInt = 0;
	
function build_tree( l, r: longInt ): longInt;
var	v: longInt;
begin
	inc( tw );
	v := tw;
	
	t[v].l := l;
	t[v].r := r;
	t[v].left := 0;
	t[v].right := 0;
	t[v].sum := 0;
	if ( l < r ) then
	begin
		t[v].lSon := build_tree( l, (l + r) div 2 );
		t[v].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	exit( v );
end;

procedure update( v, x, val: longInt );
begin
	if ( t[v].l = t[v].r ) then
	begin
		t[v].left := val;
		t[v].right := val;
		t[v].sum := val;
		
		exit();
	end;
	
	if ( x <= t[ t[v].lSon ].r ) then
		update( t[v].lSon, x, val )
	else
		update( t[v].rSon, x, val );
		
	t[v].sum := t[ t[v].lSon ].sum + t[ t[v].rSon ].sum + int64( t[ t[v].lSon ].right ) * t[ t[v].rSon ].left;
	
	t[v].left := t[ t[v].lSon ].left;
	if ( t[ t[v].lSon ].left = t[ t[v].lSon ].r - t[ t[v].lSon ].l + 1 ) then
		inc( t[v].left, t[ t[v].rSon ].left );
	
	t[v].right := t[ t[v].rSon ].right;
	if ( t[ t[v].rSon ].right = t[ t[v].rSon ].r - t[ t[v].rSon ].l + 1 ) then
		inc( t[v].right, t[ t[v].lSon ].right );
end;

var	n, m, i, p, x: longInt;
	r: array[ 0..20 ] of longInt;
	ans: int64;

begin
	readln( n, m );
	
	for i := 0 to 20 do
		r[i] := build_tree( 1, n );
	
	for p := 1 to n do
	begin
		read( x );
		
		for i := 0 to 20 do
			update( r[i], p, (x shr i) and 1 );
	end;
	
	while ( m > 0 ) do
	begin
		readln( p, x );
		
		ans := 0;
		for i := 0 to 20 do
		begin
			update( r[i], p, (x shr i) and 1 );
			
			inc( ans, t[ r[i] ].sum shl i );
		end;
		
		writeln( ans );
	
		dec( m );
	end;
end.