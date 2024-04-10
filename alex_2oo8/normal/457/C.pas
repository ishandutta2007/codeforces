program problem3;
uses math;

type	tArr =	array[ 1..100000 ] of longInt;
		tNode =	record
					l, r, lSon, rSon, cnt, sum: longInt;
				end;

var	first, next: tArr;
	t: array[ 1..100000 ] of tNode;
	tw: longInt = 0;

procedure add( x, y: longInt );
begin
	next[y] := first[x];
	first[x] := y;
end;

function build_tree( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	t[res].cnt := 0;
	t[res].sum := 0;
	if ( l < r ) then
	begin
		t[res].lSon := build_tree( l, (l + r) div 2 );
		t[res].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	exit( res );
end;

procedure tree_add( v, x, d: longInt );
begin
	inc( t[v].cnt, d );
	inc( t[v].sum, d * x );
	
	if ( t[v].l = t[v].r ) then
		exit();
	
	if ( x <= t[ t[v].lSon ].r ) then
		tree_add( t[v].lSon, x, d )
	else
		tree_add( t[v].rSon, x, d );
end;

function tree_get( v, k: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].cnt <= k ) then
		exit( t[v].sum );
	
	if ( t[v].l = t[v].r ) then
		exit( t[v].l * k );
	
	res := tree_get( t[v].lSon, k );
	if ( t[ t[v].lSon ].cnt < k ) then
		inc( res, tree_get( t[v].rSon, k - t[ t[v].lSon ].cnt ) );
	
	exit( res );
end;

procedure qsort( var a: tArr; const f, s: tArr; l, r: longInt );
var	i, j, t, med_f, med_s: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med_s := a[ l + random(r - l + 1) ];
		med_f := f[med_s];
		med_s := s[med_s];
		while ( i <= j ) do
		begin
			while ( f[ a[i] ] < med_f ) or ( ( f[ a[i] ] = med_f ) and ( s[ a[i] ] > med_s ) ) do
				inc( i );
			while ( f[ a[j] ] > med_f ) or ( ( f[ a[j] ] = med_f ) and ( s[ a[j] ] < med_s ) ) do
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
		
		qsort( a, f, s, l, j );
		qsort( a, f, s, i, r );
	end;
end;

var	n, i, j, have, willHave, need, ans, curr: longInt;
	a, b, c: tArr;

begin
	readln( n );
	for i := 1 to n do
		readln( a[i], b[i] );
	
	for i := 1 to n do
		c[i] := i;
	
	qsort( c, a, b, 1, n );
	
	i := 1;
	while ( i <= n ) and ( a[ c[i] ] = 0 ) do
		inc( i );
		
	have := i - 1;
	
	while ( i <= n ) do
	begin
		j := i;
		while ( j <= n ) and ( a[ c[j] ] = a[ c[i] ] ) do
		begin
			add( j - i + 1, j );
		
			inc( j );
		end;
		
		i := j;
	end;
	
	build_tree( 0, 10000 );
	for i := 1 to n do
		if ( a[i] <> 0 ) then
			tree_add( 1, b[i], +1 );
	
	need := 0;
	curr := 0;
	ans := 1000000000;
	for willHave := n downto 1 do
	begin
		i := first[willHave];
		while ( i > 0 ) do
		begin
			tree_add( 1, b[ c[i] ], -1 );
			inc( need );
			inc( curr, b[ c[i] ] );
		
			i := next[i];
		end;
		
		if ( have + need > willHave ) then
			break;
		
		ans := min( ans, curr + tree_get( 1, willHave - have - need ) );
	end;
	
	writeln( ans );
end.