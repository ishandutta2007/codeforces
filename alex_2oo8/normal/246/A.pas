program problem1;

var n, i: longInt;

begin
	readln( n );
	if ( n < 3 ) then
		writeln( '-1' )
	else
	begin
		write( '10 9 8' );
		for i := 4 to n do
			write( ' 1' );
		writeln();
	end;
end.