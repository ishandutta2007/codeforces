program problem3;
uses math;

type	tPair =	record
				sum, cnt: longInt;
			end;

var	p: array[ 1..200000 ] of tPair;

function less( const a, b: tPair ): boolean;
begin
	if ( a.sum <> b.sum ) then
		exit( a.sum < b.sum );
	
	exit( a.cnt < b.cnt );
end;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tPair;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := p[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( less( p[i], med ) ) do
				inc( i );
			
			while ( less( med, p[j] ) ) do
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

function find( s, m: longInt ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 20 downto 0 do
		if ( res + 1 shl i <= m ) and ( p[res + 1 shl i].sum < s ) then
			inc( res, 1 shl i );
	
	inc( res, 1 );
	if ( res <= m ) and ( p[res].sum = s ) then
		exit( p[res].cnt );
	
	exit( 42 );
end;

var	n, m, qq, q, k, i, j, s, ans: longInt;
	a: array[ 1..5000 ] of longInt;

begin
	readln( n, k );
	for i := 1 to n do
		read( a[i] );
	
	m := 1;
	p[1].sum := 0;
	p[1].cnt := 0;
	for i := 1 to n do
		for j := 1 to k do
		begin
			inc( m );
			p[m].sum := a[i] * j;
			p[m].cnt := j;
		end;
	
	qsort( 1, m );
	
	readln( q );
	for qq := 1 to q do
	begin
		read( s );
		
		ans := k + 1;
		for i := 1 to n do
			for j := 1 to ans - 1 do
				if ( s >= a[i] * j ) then
					ans := min( ans, j + find( s - a[i] * j, m ) );
		
		if ( ans > k ) then
			ans := -1;
		
		writeln( ans );
	end;
end.