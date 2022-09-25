program problem7;
uses math;

type	tTreeNode =	record
						l, r, lSon, rSon, debt, maxVal: longInt;
					end;

var	t: array[ 1..400000 ] of tTreeNode;

function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
var	i: longInt;
begin
	inc( tw );
	i := tw;
	
	t[i].l := l;
	t[i].r := r;
	t[i].maxVal := 0;
	t[i].debt := 0;
	if ( l < r ) then
	begin
		t[i].lSon := build_tree( l, (l + r) div 2 );
		t[i].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	exit( i );
end;

procedure push( v: longInt );
begin
	inc( t[ t[v].lSon ].debt, t[v].debt );
	inc( t[ t[v].lSon ].maxVal, t[v].debt );
	inc( t[ t[v].rSon ].debt, t[v].debt );
	inc( t[ t[v].rSon ].maxVal, t[v].debt );
	
	t[v].debt := 0;
end;

procedure add( v, l, r, d: longInt );
begin
	if ( l <= t[v].l ) and ( t[v].r <= r ) then
	begin
		inc( t[v].debt, d );
		inc( t[v].maxVal, d );
		
		exit();
	end;
	
	push( v );
	
	if ( l <= t[ t[v].lSon ].r ) then
		add( t[v].lSon, l, r, d );
	
	if ( r >= t[ t[v].rSon ].l ) then
		add( t[v].rSon, l, r, d );
	
	t[v].maxVal := max( t[ t[v].lSon ].maxVal, t[ t[v].rSon ].maxVal );
end;

function getMax( v: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].l = t[v].r ) then
	begin
		res := t[v].maxVal;
		
		t[v].maxVal := -1000000;
		
		exit( res );
	end;
	
	push( v );
	
	if ( t[ t[v].rSon ].maxVal = t[v].maxVal ) then
		res := getMax( t[v].rSon )
	else
		res := getMax( t[v].lSon );
	
	t[v].maxVal := max( t[ t[v].lSon ].maxVal, t[ t[v].rSon ].maxVal );
	
	exit( res );
end;

var	n, i: longInt;
	a, ans: array[ 1..200000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	build_tree( 1, n );
	
	for i := 1 to n do
		add( 1, i, i, a[i] - n + i );
	
	for i := n downto 1 do
		ans[i] := getMax( 1 ) + n - i;
	
	for i := 2 to n do
		if ( ans[i] < ans[i - 1] ) then
		begin
			writeln( ':(' );
			
			halt;
		end;
	
	for i := 1 to n do
		write( ans[i], ' ' );
	writeln();
end.