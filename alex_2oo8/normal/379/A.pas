program problem1;

var	a, b, c, ans: longInt;

begin
	readln( a, b );
	
	c := 0;
	ans := 0;
	while ( a > 0 ) do
	begin
		inc( ans, a );
		
		inc( c, a );
		a := c div b;
		c := c mod b;
	end;
	
	writeln( ans );
end.