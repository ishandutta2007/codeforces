program problem2;

type	tArr =	array[1..2] of longInt;

var	a: array[ 1..200000 ] of tArr;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tArr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( a[i][1] < med[1] ) or ( ( a[i][1] = med[1] ) and ( a[i][2] < med[2] ) ) do
				inc( i );
			while ( a[j][1] > med[1] ) or ( ( a[j][1] = med[1] ) and ( a[j][2] > med[2] ) ) do
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

var	n, i, j, k: longInt;
	ans, curr, m, cnt: int64;
	f: array[ 0..200000 ] of int64;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( a[i][1] );
		a[i][2] := i;
	end;
	
	for i := 1 to n do
	begin
		read( a[n+i][1] );
		a[n+i][2] := i;
	end;
	
	readln( m );
	
	n := 2 * n;
	
	qsort( 1, n );
	
	f[0] := 1;
	for i := 1 to n do
		f[i] := ( f[i-1] * i ) mod m;
	
	ans := 1;
	i := 1;
	while ( i <= n ) do
	begin
		j := i;
		k := 0;
		while ( j < n ) and ( a[i][1] = a[j+1][1] ) do
		begin
			inc( j );
			if ( a[j][2] = a[j-1][2] ) then
				inc( k );
		end;
		
		cnt := j - i + 1;
		curr := 1;
		while ( k > 0 ) do
		begin
			curr := ( curr * ( ( ( cnt * (cnt-1) ) div 2 ) mod m ) ) mod m;
			dec( k );
			dec( cnt, 2 );
		end;
		curr := ( curr * f[cnt] ) mod m;
		
		ans := ( ans * curr ) mod m;
		i := j + 1;
	end;
	
	writeln( ans );
end.