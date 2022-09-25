program problem5;
uses math;

type	tQuery =	record
				id, lx, rx, ly, ry: longInt;
			end;
	tTreeNode =	record
					l, r, lSon, rSon, mx: longInt;
				end;

var	n, m, k, q: longInt;
	x, y, ans, first, next: array[ 1..200000 ] of longInt;
	p: array[ 1..200000 ] of tQuery;
	t: array[ 1..1000000 ] of tTreeNode;
	tw: longInt;
	
function build_tree( l, r: longInt ): longInt;
var	i: longInt;
begin
	inc( tw );
	i := tw;
	
	t[i].l := l;
	t[i].r := r;
	t[i].mx := 1000000;
	if ( l < r ) then
	begin
		t[i].lSon := build_tree( l, (l + r) div 2 );
		t[i].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	exit( i );
end;

procedure update( v, x, val: longInt );
begin
	if ( t[v].l = t[v].r ) then
	begin
		t[v].mx := val;
		
		exit();
	end;
	
	if ( x <= t[ t[v].lSon ].r ) then
		update( t[v].lSon, x, val )
	else
		update( t[v].rSon, x, val );
	
	t[v].mx := max( t[ t[v].lSon ].mx, t[ t[v].rSon ].mx );
end;

function get( v, l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
		exit( t[v].mx );
	
	res := 0;
	if ( t[ t[v].lSon ].r >= l ) then
		res := max( res, get( t[v].lSon, l, r ) );
	if ( t[ t[v].rSon ].l <= r ) then
		res := max( res, get( t[v].rSon, l, r ) );
	
	exit( res );
end;

procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tQuery;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := p[ l + random(r - l + 1) ].ly;
		while ( i <= j ) do
		begin
			while ( p[i].ly > med ) do
				inc( i );
			while ( p[j].ly < med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := p[i];
				p[i] := p[j];
				p[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;
	
procedure solve();
var	i, j, f: longInt;
begin
	tw := 0;
	for i := 1 to m do
		first[i] := 0;
	
	for i := 1 to k do
	begin
		next[i] := first[ y[i] ];
		first[ y[i] ] := i;
	end;
	
	build_tree( 1, n );
	
	qsort( 1, q );
	
	f := m + 1;
	for i := 1 to q do
	begin
		while ( f > p[i].ly ) do
		begin
			dec( f );
			
			j := first[f];
			while ( j > 0 ) do
			begin
				update( 1, x[j], f );
			
				j := next[j];
			end;
		end;
		
		if ( get( 1, p[i].lx, p[i].rx ) <= p[i].ry ) then
			ans[ p[i].id ] := 1;
	end;
end;
	
var	i: longInt;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );

	readln( n, m, k, q );
	for i := 1 to k do
		readln( x[i], y[i] );
	
	for i := 1 to q do
	begin
		readln( p[i].lx, p[i].ly, p[i].rx, p[i].ry );
		p[i].id := i;
		ans[i] := 0;
	end;
	
	solve();
	
	n := n xor m;
	m := n xor m;
	n := n xor m;
	
	for i := 1 to k do
	begin
		x[i] := x[i] xor y[i];
		y[i] := x[i] xor y[i];
		x[i] := x[i] xor y[i];
	end;
	
	for i := 1 to q do
	begin
		p[i].lx := p[i].lx xor p[i].ly;
		p[i].ly := p[i].lx xor p[i].ly;
		p[i].lx := p[i].lx xor p[i].ly;
		
		p[i].rx := p[i].rx xor p[i].ry;
		p[i].ry := p[i].rx xor p[i].ry;
		p[i].rx := p[i].rx xor p[i].ry;
	end;
	
	solve();
	
	for i := 1 to q do
		if ( ans[i] = 1 ) then
			writeln( 'YES' )
		else
			writeln( 'NO' );
end.