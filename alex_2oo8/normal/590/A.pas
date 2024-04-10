program problem1;
uses math;

var	n, i, j, k, ans: longInt;
	a: array[ 1..1000000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	ans := 0;
	
	i := 2;
	while ( i < n ) do
	begin
		j := i - 1;
		while ( j < n ) and ( a[j] <> a[j + 1] ) do
			inc( j );
		
		ans := max( ans, (j - i + 1) div 2 );
		
		for k := i to (j + i) div 2 - 1 do
			a[k] := a[i - 1];
		
		for k := (j + i) div 2 to j do
			a[k] := a[j];
		
		i := j + 2;
	end;
	
	writeln( ans );
	for i := 1 to n do
		write( a[i], ' ' );
	
	writeln();
end.