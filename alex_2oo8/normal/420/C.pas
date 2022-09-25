program problem3;
uses math;

var	a: array[ 1..300000 ] of int64;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: int64;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( a[i] < med ) do
				inc( i );
			while ( a[j] > med ) do	
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
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, p, i, j, x, y: longInt;
	cnt, f, g: array[ 0..300000 ] of longInt;
	ans: int64;

begin
	fillchar( f, sizeOf(f), 0 );
	fillchar( g, sizeOf(g), 0 );
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n, p );
	for i := 1 to n do
	begin
		readln( x, y );
		
		inc( g[x] );
		inc( g[y] );
		
		a[i] := int64(1000000) * min(x, y) + max(x, y);
	end;
	
	for i := 1 to n do
		inc( cnt[ g[i] ] );
	
	f[0] := cnt[0];
	for i := 1 to n do
		f[i] := f[i - 1] + cnt[i];
		
	ans := 0;
	for i := 0 to p - 1 do
	begin
		j := min( i, p - 1 - i );
		
		inc( ans, int64( f[j] ) * cnt[i] );
		
		if ( 2 * i < p ) then
			dec( ans, cnt[i] * int64( cnt[i] + 1 ) div 2 );
	end;
	
	qsort( 1, n );
	
	i := 1;
	while ( i <= n ) do
	begin
		j := i;
		while ( j < n ) and ( a[j + 1] = a[i] ) do
			inc( j );
		
		x := a[i] div 1000000;
		y := a[i] mod 1000000;
		
		if ( g[x] + g[y] >= p ) and ( g[x] + g[y] - (j - i + 1) < p ) then
			inc( ans );
		
		i := j + 1;
	end;
	
	writeln( n * int64(n - 1) div 2 - ans );
end.