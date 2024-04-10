program problem1;

var	n, i, j: longInt;
	l, r: int64;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( l, r );
		
		if ( l = r ) then
		begin
			writeln( l );
			
			continue;
		end;
		
		j := 0;
		while ( (l shr j) <> (r shr j) ) do
			inc( j );
		
		if ( r and ( (int64(1) shl j) - 1 ) = (int64(1) shl j) - 1 ) then
			writeln( r )
		else
			writeln( ( (r shr j) shl j ) xor ( (int64(1) shl (j - 1)) - 1 ) );
	end;
end.