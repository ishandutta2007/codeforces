program problem4;
uses math;

var	n, i, len, ans, cur, x, y, z: longInt;
	a, s: array[ 1..100000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );

	s[1] := a[1];
	for i := 2 to n do
		s[i] := s[i - 1] + a[i];
	
	ans := a[2] * a[2] + 1;
	for len := 1 to n - 1 do
	begin
		cur := len * len;
		x := ans - cur;
		
		if ( x < 0 ) then
			break;
			
		x := round( sqrt(x) ) + 5;
		while ( x * x + cur > ans ) do
			dec( x );
		
		y := x + 1;
		for i := len + 1 to n do
		begin
			z := abs( s[i] - s[i - len] );
			
			if ( z < y ) then
				y := z;
		end;
		
		if ( y <= x ) then
			ans := y * y + cur;
	end;
	
	writeln( ans );
end.