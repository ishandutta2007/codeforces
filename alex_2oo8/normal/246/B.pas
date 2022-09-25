program problem2;

var n, i, sum, a: longInt;

begin
	sum := 0;
	
	readln( n );
	for i := 1 to n do
	begin
		read( a );
		inc( sum, a );
	end;
	
	if ( ( abs(sum) mod n ) = 0 ) then
		writeln( n )
	else
		writeln( n - 1 );
end.