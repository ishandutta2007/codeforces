program problem2;

var	n, m, i, a, last: longInt;
	ans: int64;

begin
	ans := 0;
	last := 1;
	
	readln( n, m );
	for i := 1 to m do
	begin
		read( a );
		
		if ( a < last ) then
			inc( ans, a + n - last )
		else
			inc( ans, a - last );
			
		last := a;
	end;
	
	writeln( ans );
end.