program problem3;
uses math;

var	a, aa: array[ 1..500000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ aa[ l + random(r - l + 1) ] ];
		while ( i <= j ) do
		begin
			while ( a[ aa[i] ] < med ) do
				inc( i );
			while ( a[ aa[j] ] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := aa[i];
				aa[i] := aa[j];
				aa[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, i, r: longInt;
	b: array[ 1..500000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
		aa[i] := i;
		
	qsort( 1, n );
	
	r := 0;
	for i := 1 to n do
	begin
		b[ aa[i] ] := max( a[ aa[i] ], r + 1 );
		r := b[ aa[i] ];
	end;
	
	for i := 1 to n do
		write( b[i], ' ' );
	writeln();
end.