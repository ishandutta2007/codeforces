program problem5;
uses math;

var	a, b, root: array[ 0..200000 ] of longInt;
	t: array[ 0..8000000 ] of qWord;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ b[ l + random(r - l + 1) ] ];
		while ( i <= j ) do
		begin
			while ( a[ b[i] ] < med ) do
				inc( i );
			
			while ( a[ b[j] ] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := b[i];
				b[i] := b[j];
				b[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function compress( lSon, rSon, mn: longInt ): qWord;
begin
	exit( qWord(200001) * ( qWord(8000000) * qWord(lSon) + qWord(rSon) ) + qWord(mn) );
end;

procedure decompress( mask: qWord; var lSon, rSon, mn: longInt );
begin
	mn := mask mod 200001;
	mask := mask div 200001;
	rSon := mask mod 8000000;
	lSon := mask div 8000000;
end;

function build_tree( prev: longInt ): longInt;
const	tw: longInt = 0;
begin
	inc( tw );
	t[tw] := t[prev];
	
	exit( tw );
end;

function get( v, l, r: longInt ): longInt;
begin
	if ( l = r ) then
		exit( v );
	
	exit( t[v] mod 200001 );
end;

function add( v, l, r, ll, rr: longInt ): longInt;
var	c, delta, lSon, rSon, mn: longInt;
begin
	if ( l = r ) then
		exit( v + 1 );

	v := build_tree( v );
	
	if ( ll <= l ) and ( r <= rr ) then
	begin
		inc( t[v], 1 );
		
		exit( v );
	end;
	
	decompress( t[v], lSon, rSon, mn );
	
	c := ( l + r ) div 2;
		
	delta := mn - min( get( lSon, l, c ), get( rSon, c + 1, r ) );
	if ( ll <= c ) then
		lSon := add( lSon, l, c, ll, rr );
	
	if ( rr > c ) then
		rSon := add( rSon, c + 1, r, ll, rr );
	
	mn := min( get( lSon, l, c ), get( rSon, c + 1, r ) ) + delta;
	
	t[v] := compress( lSon, rSon, mn );
	
	exit( v );
end;

function query( v, l, r, ll, rr: longInt ): longInt;
var	res, c, delta, lSon, rSon, mn: longInt;
begin
	if ( l = r ) then
		exit( v );

	if ( ll <= l ) and ( r <= rr ) then
		exit( t[v] mod 200001 );
	
	decompress( t[v], lSon, rSon, mn );
	
	c := ( l + r ) div 2;
	
	delta := mn - min( get( lSon, l, c ), get( rSon, c + 1, r ) );
	
	res := 100000000;
	if ( ll <= c ) then
		res := min( res, query( lSon, l, c, ll, rr ) );
	
	if ( rr > c ) then
		res := min( res, query( rSon, c + 1, r, ll, rr ) );
	
	exit( delta + res );
end;

var	n, m, q, i, j, l, r, x, y, ans: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
		b[i] := i;
	
	qsort( 1, n );
	
	root[0] := 0;
	for i := 1 to n do
	begin
		r := min( b[i], n - m + 1 );
		l := max( 1, b[i] - m + 1 );
		
		root[i] := add( root[i - 1], 1, n - m + 1, l, r );
	end;
	
	ans := 0;
	readln( q );
	for i := 1 to q do
	begin
		readln( l, r, x );
		
		x := x xor ans;
		
		y := 0;
		for j := 20 downto 0 do
			if ( y + 1 shl j <= n ) and ( a[ b[y + 1 shl j] ] < x ) then
				inc( y, 1 shl j );
		
		ans := query( root[y], 1, n - m + 1, l, r );
		
		writeln( ans );
	end;
end.