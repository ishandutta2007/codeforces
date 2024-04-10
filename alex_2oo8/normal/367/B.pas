program problemB;
uses math;

var	arr, cnt: array[ 0..500000 ] of longInt;
	arrN, nonZero: longInt;
	
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
			while ( arr[i] < med ) do
				inc( i );
			while ( arr[j] > med ) do
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

function find( x: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := arrN;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		if ( arr[c] < x ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;
	
procedure add( x, d: longInt );
begin
	if ( cnt[x] = 0 ) then
		inc( nonZero );

	inc( cnt[x], d );
	
	if ( cnt[x] = 0 ) then
		dec( nonZero );
end;

var	n, m, p, w, i, j, ans: longInt;
	x, a, b: array[ 0..500000 ] of longInt;

begin
	readln( n, m, p );
	for i := 1 to n do
		read( x[i] );
	
	for i := 1 to m do
		read( b[i] );
		
	for i := 1 to n do
		arr[i] := x[i];
	
	for i := 1 to m do
		arr[i+n] := b[i];
		
	qsort( 1, n + m );
	
	arrN := 1;
	for i := 2 to n + m do
		if ( arr[i] <> arr[arrN] ) then
		begin
			inc( arrN );
			arr[arrN] := arr[i];
		end;
	
	for i := 1 to n do
		x[i] := find( x[i] );
		
	for i := 1 to m do
		b[i] := find( b[i] );
		
	nonZero := 0;
	for i := 1 to m do
		add( b[i], +1 );
	
	ans := 0;
	for i := 1 to min( n, p ) do
		if ( i + p * int64(m-1) <= n ) then
		begin
			w := (n - i) div p + 1;
		
			for j := 0 to w - 1 do
				a[j+1] := x[ i + j * p ];
				
			for j := 0 to m - 1 do
				add( a[j], -1 );
				
			for j := m to w do
			begin
				add( a[j-m], +1 );
				add( a[j  ], -1 );
				
				if ( nonZero = 0 ) then
				begin
					inc( ans );
					arr[ans] := i + (j - m) * p;
				end;
			end;
			
			for j := w - m + 1 to w do
				add( a[j], +1 );
		end;
		
	qsort( 1, ans );
		
	writeln( ans );
	for i := 1 to ans do
		write( arr[i], ' ' );
	writeln();
end.