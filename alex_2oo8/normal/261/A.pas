program problem1;
uses math;

var	a: array[ 1..100000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( a[i] > med ) do
				inc( i );
			while ( a[j] < med ) do
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

var	m, n, i, j, t, q: longInt;
	ans: int64;

begin
	readln( m );
	t := 1000000;
	for i := 1 to m do
	begin
		read( q );
		t := min( q, t );
	end;
		
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	qsort( 1, n );
	
	ans := 0;
	i := 1;
	while ( i <= n ) do
	begin
		for j := i to min( n, (i+t-1) ) do
			inc( ans, a[j] );
			
		inc( i, (t+2) );
	end;
	
	writeln( ans );
end.