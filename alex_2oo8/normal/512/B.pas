program problem2;

var	a: array[ 1..1000000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
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

function find( x, n: longInt ): longInt;
var	i, res: longInt;
begin
	res := 1;
	for i := 20 downto 0 do
		if ( res + (1 shl i) <= n ) and ( a[res + 1 shl i] <= x ) then
			inc( res, 1 shl i );
	
	exit( res );
end;

function gcd( a, b: longInt ): longInt;
var	c: longInt;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;
	
	exit( a );
end;

procedure upd( var x: longInt; y: longInt );
begin
	if ( y < x ) then
		x := y;
end;

var	n, i, j, k: longInt;
	l, c: array[ 1..300 ] of longInt;
	dp: array[ 1..1000000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( l[i] );
	
	for i := 1 to n do
		read( c[i] );
	
	k := 32000;
	for i := 1 to k do
		a[i] := i;
	
	for i := 1 to n do
		for j := 1 to 32000 do
			if ( l[i] mod j = 0 ) then
			begin
				inc( k );
				a[k] := l[i] div j;
			end;
	
	qsort( 1, k );
	
	j := 1;
	for i := 2 to k do
		if ( a[i] <> a[j] ) then
		begin
			inc( j );
			a[j] := a[i];
		end;
	
	k := j;
	for i := 1 to k do
		dp[i] := 1000000000;
	
	for i := 1 to n do
		upd( dp[ find( l[i], k ) ], c[i] );
	
	for i := k downto 1 do
		if ( dp[i] < 1000000000 ) then
			for j := 1 to n do
				upd( dp[ find( gcd( a[i], l[j] ), k ) ], dp[i] + c[j] );
	
	if ( dp[1] = 1000000000 ) then
		writeln( -1 )
	else
		writeln( dp[1] );
end.