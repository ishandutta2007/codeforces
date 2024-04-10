program problem2;
uses math;

var	n, m, k: longInt;
	t: array[ 1..100 ] of string[3];
	a, b: array[ 1..100 ] of longInt;
	
function calc1(): longInt;
var res, i: longInt;
begin
	res := 0;
	i := 1;
	while ( i <= min( m, k ) ) and ( b[i] - a[i] > 0 ) do
	begin
		inc( res, b[i] - a[i] );
		inc( i );
	end;

	exit( res );
end;

function calc2(): longInt;
var	i, p, res: longInt;
begin
	res := 0;
	for i := n downTo k + 1 do
	begin
		p := m;
		while ( p > 0 ) and ( b[p] <= a[i] ) do
			dec( p );

		if ( p = 0 ) then
			exit( 0 );

		b[p] := 0;
	end;

	for i := k downTo 1 do
	begin
		p := m;
		while ( p > 0 ) and ( b[p] < a[i] ) do
			dec( p );

		if ( p = 0 ) then
			exit( 0 );
			
		inc( res, b[p] - a[i] );

		b[p] := 0;
		a[i] := 0;
	end;

	for i := 1 to m do
		inc( res, b[i] );

	for i := 1 to k do
		dec( res, a[i] );

	exit( res );
end;
	
var	i, j, tmp, res: longInt;
	str: string[3];

begin
	readln( n, m );
	for i := 1 to n do
		readln( t[i], a[i] );
		
	for i := 1 to m do
		readln( b[i] );
		
	for i := 1 to m do
		for j := i + 1 to m do
			if ( b[i] < b[j] ) then
			begin
				tmp := b[i];
				b[i] := b[j];
				b[j] := tmp;
			end;
			
	for i := 1 to n do
		for j := i + 1 to n do
			if ( t[i] > t[j] ) or ( ( t[i] = t[j] ) and ( a[i] > a[j] ) ) then
			begin
				tmp := a[i];
				a[i] := a[j];
				a[j] := tmp;
				
				str := t[i];
				t[i] := t[j];
				t[j] := str;
			end;
			
	k := 0;
	while ( k < n ) and ( t[k+1] = 'ATK' ) do
		inc( k );
	
	res := calc1();
	res := max( res, calc2() );
	writeln( res );
end.