program problemC;
uses math;

var	arr: array[ 1..100000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, tmp, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := arr[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( arr[i] > med ) do
				inc( i );
			while ( arr[j] < med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp := arr[i];
				arr[i] := arr[j];
				arr[j] := tmp;
			
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, m, i, q, l, r, c: longInt;
	ans: int64;

begin
	readln( n, m );
	for i := 1 to m do
		readln( q, arr[i] );
		
	qsort( 1, m );
	
	l := 1;
	r := m;
	while ( l < r ) do
	begin
		c := ( l + r + 1 ) div 2;
		if ( c * int64( c div 2 ) + ( c mod 2 ) <= n ) then
			l := c
		else
			r := c - 1;
	end;
	
	ans := 0;
	for i := 1 to min( l, m ) do
		inc( ans, arr[i] );
		
	writeln( ans );
end.