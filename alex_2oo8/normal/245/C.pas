program problem3;

var n, i, ans, k, x: longInt;
	a: array[1..1000] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	ans := 0;
	for i := n downTo 1 do
		if ( a[i] > 0 ) then
		begin
			k := i div 2;
			if ( i = 1 ) then
				k := 1;
			
			if ( k < 1 ) or ( (2*k+1) > n ) then
			begin
				writeln( '-1' );
				halt;
			end;
			
			x := a[i];
			dec( a[k], x );
			dec( a[2*k], x );
			dec( a[2*k+1], x );
			inc( ans, x );
		end;
		
	writeln( ans );
end.