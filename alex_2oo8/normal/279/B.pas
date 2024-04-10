program problem2;
uses math;

var	n, t, i, j, ans, s: longInt;	
	a: array[ 1..100001 ] of longInt;

begin
	readln( n, t );
	for i := 1 to n do
		read( a[i] );
	a[n+1] := t + 1;
		
	ans := 0;
	if ( a[1] <= t ) then
		ans := 1;
	i := 1;
	j := 1;
	s := a[1];
	while ( i <= n ) do
	begin
		if ( ( s + a[j+1] ) <= t ) then
		begin
			inc( j );
			inc( s, a[j] );
		end
		else
		begin
			dec( s, a[i] );
			inc( i );
		end;
			
		if ( s <= t ) then
			ans := max( ans, (j-i+1) );
	end;
	
	writeln( ans );
end.