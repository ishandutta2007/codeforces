program problem4;

type tArr =	array[ 0..1 ] of longInt;

var a: array[ 0..100000 ] of tArr;

procedure qsort( l, r: longInt );
var i, j: longInt;
	t, med: tArr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( a[i][0] < med[0] ) or ( ( a[i][0] = med[0] ) and ( a[i][1] < med[1] ) ) do
				inc( i );
			while ( a[j][0] > med[0] ) or ( ( a[j][0] = med[0] ) and ( a[j][1] > med[1] ) ) do
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

function gcd( a, b: longInt ): longInt;
var c: longInt;
begin
	while ( b <> 0 ) do
	begin
		c := a mod b;
		a := b;
		b := c;
	end;
	
	exit( a );
end;

var n, m, i, b, k, ans, d: longInt;

begin
	readln( n );
	
	m := 0;
	for i := 1 to n do
	begin
		readln( k, b );
		if ( k <> 0 ) then
		begin
			inc( m );
			
			d := gcd( b, k );
			
			a[m][0] := - ( b div d );
			a[m][1] := ( k div d );
		end;
	end;
	
	qsort( 1, m );
	
	a[0][0] := 0;
	a[0][1] := 0;
	
	ans := 0;
	for i := 1 to m do
		if ( a[i][0] <> a[i-1][0] ) or ( a[i][1] <> a[i-1][1] ) then
			inc( ans );
			
	writeln( ans );
end.