program problem3;

type	tRec =	record
					l, r, id: longInt;
				end;
		tArr =	array[ 1..100000 ] of tRec;
		tTreeRec =	record
						l, r, lSon, rSon, cnt, first: longInt;
					end;
					
var	k, next: array[ -1..100000 ] of longInt;
	t: array[ 0..10000000 ] of tTreeRec;
	
function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
begin
	inc( tw );
	t[tw].l := l;
	t[tw].r := r;
	t[tw].lSon := 0;
	t[tw].rSon := 0;
	t[tw].cnt := 0;
	t[tw].first := -1;
	
	exit( tw );
end;

procedure tree_add( v, x, id: longInt );
var	c: longInt;
begin
	inc( t[v].cnt );
	if ( t[v].l = t[v].r ) then
	begin
		next[id] := t[v].first;
		t[v].first := id;
	
		exit();
	end;
	
	c := ( t[v].l + t[v].r ) div 2;
	if ( x <= c ) then
	begin
		if ( t[v].lSon = 0 ) then
			t[v].lSon := build_tree( t[v].l, c );
		
		tree_add( t[v].lSon, x, id );
	end
	else
	begin
		if ( t[v].rSon = 0 ) then
			t[v].rSon := build_tree( c + 1, t[v].r );
		
		tree_add( t[v].rSon, x, id );
	end;
end;

function tree_get( v, x: longInt ): longInt;
var	res: longInt;
begin
	if ( v = 0 ) or ( t[v].cnt = 0 ) then
		exit( -1 );
	
	if ( t[v].l = t[v].r ) then
	begin
		while ( k[ t[v].first ] = 0 ) do
		begin
			t[v].first := next[ t[v].first ];
			
			dec( t[v].cnt );
		end;
		
		dec( k[ t[v].first ] );
		
		exit( t[v].first );
	end;
	
	res := -1;
	if ( t[v].lSon > 0 ) and ( t[ t[v].lSon ].r >= x ) then
		res := tree_get( t[v].lSon, x );
	
	if ( res = -1 ) then
		res := tree_get( t[v].rSon, x );
	
	t[v].cnt := t[ t[v].lSon ].cnt + t[ t[v].rSon ].cnt;
	
	exit( res );
end;

procedure qsort( var a: tArr; l, r: longInt );
var	i, j, med: longInt;
	t: tRec;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ].l;
		while ( i <= j ) do
		begin
			while ( a[i].l < med ) do
				inc( i );
			
			while ( a[j].l > med ) do
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
		
		qsort( a, l, j );
		qsort( a, i, r );
	end;
end;

var	n, m, i, j: longInt;
	a, b: tArr;
	ans: array[ 1..100000 ] of longInt;

begin
	k[-1] := 10000000;

	readln( n );
	for i := 1 to n do
	begin
		readln( a[i].l, a[i].r );
		a[i].id := i;
	end;
	
	readln( m );
	for i := 1 to m do
	begin
		readln( b[i].l, b[i].r, k[i] );
		b[i].id := i;
	end;
	
	qsort( a, 1, n );
	qsort( b, 1, m );
	
	build_tree( 1, 1000000000 );
	
	i := 1;
	j := 1;
	while ( i <= n ) do
	begin
		if ( j <= m ) and ( b[j].l <= a[i].l ) then
		begin
			tree_add( 1, b[j].r, b[j].id );
			inc( j );
		end
		else
		begin
			ans[ a[i].id ] := tree_get( 1, a[i].r );
			inc( i );
		end;
	end;
	
	for i := 1 to n do
		if ( ans[i] = -1 ) then
		begin
			writeln( 'NO' );
			halt;
		end;
		
	writeln( 'YES' );
	for i := 1 to n do
		write( ans[i], ' ' );
	writeln();
end.