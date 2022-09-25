program problem3;

var	a: array[ 1..300000 ] of longInt;

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

var	n, i: longInt;
	ans: qWord;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	qsort( 1, n );
	
	ans := 0;
	for i := 1 to n do
		inc( ans, abs( i - a[i] ) );
		
	writeln( ans );
end.