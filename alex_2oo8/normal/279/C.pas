program problem3;

var	n, m, i, j, ll, rr: longInt;
	a, l, r: array[ 1..100000 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
		
	r[n] := n;
	for i := (n-1) downTo 1 do
		if ( a[i] <= a[i+1] ) then
			r[i] := r[i+1]
		else
			r[i] := i;
			
	l[1] := 1;
	for i := 2 to n do
		if ( a[i] <= a[i-1] ) then
			l[i] := l[i-1]
		else
			l[i] := i;
			
	for i := 1 to m do
	begin
		readln( ll, rr );
		if ( r[ll] >= l[rr] ) then
			writeln( 'Yes' )
		else
			writeln( 'No' );
	end;
end.