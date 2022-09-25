program problem3;

type	tArr =	array[ 0..200005 ] of longInt;

procedure qsort( var a: tArr; l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
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
		
		qsort( a, l, j );
		qsort( a, i, r );
	end;
end;

var	n, q, i, l, r: longInt;
	p, a, b: tArr;
	ans: int64;

begin
	fillchar( p, sizeOf(p), 0 );

	readln( n, q );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to q do
	begin
		readln( l, r );
		
		inc( p[l] );
		dec( p[r+1] );
	end;
	
	b[0] := 0;
	for i := 1 to n do
		b[i] := b[i-1] + p[i];
	
	qsort( a, 1, n );
	qsort( b, 1, n );
	
	ans := 0;
	for i := 1 to n do
		inc( ans, ( int64( a[i] ) * b[i] ) );
		
	writeln( ans );
end.