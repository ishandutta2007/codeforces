program problem2;
uses math;

type	tTreeNode =	record
						l, r, lSon, rSon, minDp, minA, maxA: longInt;
					end;

var	a: array[ 1..100000 ] of longInt;
	t: array[ 1..1000000 ] of tTreeNode;
	
function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
var	i: longInt;
begin
	inc( tw );
	i := tw;
	
	t[i].l := l;
	t[i].r := r;
	t[i].minDp := 1000000;
	if ( l < r ) then
	begin
		t[i].lSon := build_tree( l, (l + r) div 2 );
		t[i].rSon := build_tree( (l + r) div 2 + 1, r );
		
		t[i].minA := min( t[ t[i].lSon ].minA, t[ t[i].rSon ].minA );
		t[i].maxA := max( t[ t[i].lSon ].maxA, t[ t[i].rSon ].maxA );
	end
	else
	begin
		t[i].minA := a[l];
		t[i].maxA := a[l];
	end;
	
	exit( i );
end;

procedure setDP( v, x, val: longInt );
begin
	t[v].minDp := min( t[v].minDp, val );
	if ( t[v].l = t[v].r ) then
		exit();
	
	if ( x <= t[ t[v].lSon ].r ) then
		setDp( t[v].lSon, x, val )
	else
		setDp( t[v].rSon, x, val );
end;

function getMin( v, l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
		exit( t[v].minDp );
	
	res := 1000000;
	if ( t[ t[v].lSon ].r >= l ) then
		res := min( res, getMin( t[v].lSon, l, r ) );
	
	if ( t[ t[v].rSon ].l <= r ) then
		res := min( res, getMin( t[v].rSon, l, r ) );
	
	exit( res );
end;

function findL( v, r, s: longInt; var mn, mx: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].l = t[v].r ) then
	begin
		if ( max( mx, t[v].maxA ) - min( mn, t[v].minA ) <= s ) then
		begin
			mx := max( mx, t[v].maxA );
			mn := min( mn, t[v].minA );
			
			exit( t[v].l );
		end
		else
			exit( t[v].l + 1 );
	end;
	
	if ( t[v].r <= r ) then
	begin
		if ( max( mx, t[ t[v].rSon ].maxA ) - min( mn, t[ t[v].rSon ].minA ) <= s ) then
		begin
			mx := max( mx, t[ t[v].rSon ].maxA );
			mn := min( mn, t[ t[v].rSon ].minA );
			
			exit( findL( t[v].lSon, r, s, mn, mx ) );
		end
		else
			exit( findL( t[v].rSon, r, s, mn, mx ) );
	end;
	
	if ( t[ t[v].lSon ].r >= r ) then
		exit( findL( t[v].lSon, r, s, mn, mx ) );
	
	res := findL( t[v].rSon, r, s, mn, mx );
	if ( res = t[ t[v].rSon ].l ) then
		exit( findL( t[v].lSon, r, s, mn, mx ) )
	else
		exit( res );
end;

var	n, s, len, i, ans, l, qq, qqq: longInt;

begin
	readln( n, s, len );
	for i := 1 to n do
		read( a[i] );
	
	build_tree( 1, n );
	
	for i := 1 to n do
	begin
		qq := 1000000000;
		qqq := -1000000000;
		l := findL( 1, i, s, qq, qqq );
		
//		writeln( 'findL(', i, ') = ', l );
		
		if ( i - l + 1 < len ) then
			ans := n + 1
		else if ( l = 1 ) then
			ans := 1
		else
			ans := getMin( 1, l - 1, i - len ) + 1;
		
//		writeln( 'dp(', i, ') = ', ans );
		
		setDp( 1, i, ans );
	end;
	
	if ( ans > n ) then
		ans := -1;
	
	writeln( ans );
end.