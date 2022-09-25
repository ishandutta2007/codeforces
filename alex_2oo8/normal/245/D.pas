program problem4;

var n, i, j, k, b: longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		k := 0;
		for j := 1 to n do
		begin
			read( b );
			if ( j <> i ) then
				k := k or b;
		end;
		readln();
		
		write( k, ' ' );
	end;
end.