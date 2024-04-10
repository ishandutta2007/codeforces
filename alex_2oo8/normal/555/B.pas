program problem2;

type	tArr =	array[ 0..200001 ] of longInt;
		tArrr =	array[ 1..200000 ] of int64;

var	ll, rr, l, r, a: tArrr;
	id, idd, ans, p, used: tArr;

function get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := get( p[v] );
	
	exit( p[v] );
end;

procedure merge( u, v: longInt );
begin
	p[ get(v) ] := get(u);
end;

procedure qsort( var a: tArr; const v: tArrr; l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( v[ a[i] ] < v[med] ) do
				inc( i );
			
			while ( v[ a[j] ] > v[med] ) do
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
		
		qsort( a, v, l, j );
		qsort( a, v, i, r );
	end;
end;
	
var	n, m, i, j, x: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( ll[i], rr[i] );
	
	for i := 1 to m do
		read( a[i] );
	
	for i := 1 to n - 1 do
	begin
		id[i] := i;
	
		l[i] := ll[i + 1] - rr[i];
		r[i] := rr[i + 1] - ll[i];
	end;
	
	for i := 1 to m do
		idd[i] := i;
	
	qsort( id, l, 1, n - 1 );
	qsort( idd, a, 1, m );
	
	for i := 1 to m do
		p[i] := i;
	
	j := m;
	for i := n - 1 downto 1 do
	begin
		x := 0;
		for j := 20 downto 0 do
			if ( x + 1 shl j <= m ) and ( a[ idd[x + 1 shl j] ] <= r[ id[i] ] ) then
				inc( x, 1 shl j );
		
		if ( used[x] = 1 ) then
			x := get( x ) - 1;
		
		if ( x < 1 ) or ( a[ idd[x] ] < l[ id[i] ] ) then
		begin
			writeln( 'No' );
			
			halt;
		end;
		
		ans[ id[i] ] := idd[x];
		
		used[x] := 1;
		if ( used[x - 1] = 1 ) then
			merge( x - 1, x );
		
		if ( used[x + 1] = 1 ) then
			merge( x, x + 1 );
	end;
	
	writeln( 'Yes' );
	for i := 1 to n - 1 do
		write( ans[i], ' ' );
	
	writeln();	
end.