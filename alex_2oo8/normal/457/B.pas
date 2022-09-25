program problem2;
uses math;

type	tArr =	array[ 1..100000 ] of longInt;

procedure qsort( var a: tArr; l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
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
		
		qsort( a, l, j );
		qsort( a, i, r );
	end;
end;

var	n, m, i: longInt;
	ans, s1, s2, s3: int64;
	a, b: tArr;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to m do
		read( b[i] );
	
	qsort( a, 1, n );
	qsort( b, 1, m );
	
	s1 := 0;
	for i := 1 to n do
		inc( s1, a[i] );
	
	s2 := 0;
	for i := 1 to m do
		inc( s2, b[i] );
	
	ans := s1 + s2;
	
	s3 := 0;
	for i := 1 to n do
	begin
		inc( s3, a[i] );
		
		if ( ans div s2 >= i ) then
			ans := min( ans, i * s2 + s1 - s3 );
	end;
	
	s3 := 0;
	for i := 1 to m do
	begin
		inc( s3, b[i] );
		
		if ( ans div s1 >= i ) then
			ans := min( ans, i * s1 + s2 - s3 );
	end;
	
	writeln( ans );
end.