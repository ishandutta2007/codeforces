program problem1;

var	n, i, a, b, c, ans: longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( a, b );
		
		ans := 0;
		while ( b > 0 ) do
		begin
			inc( ans, ( a div b ) );
			c := b;
			b := a mod b;
			a := c;
		end;
		
		writeln( ans );
	end;
end.