program problem1;

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

function gcd( a, b: int64 ): int64;
var c: int64;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;

	exit( a );
end;

var	n, i: longInt;
	ansP, ansQ, sum: int64;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	qsort( 1, n );
	
	ansP := 0;
	sum := 0;
	for i := 1 to n do
	begin
		inc( ansP, 2 * ( int64(i-1) * a[i] - sum ) + a[i] );
		inc( sum, a[i] );
	end;
	
	ansQ := n div gcd( ansP, n );
	ansP := ansP div gcd( ansP, n );
	
	writeln( ansP, ' ', ansQ );
end.