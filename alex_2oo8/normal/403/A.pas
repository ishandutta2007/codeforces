program problem1;

var	t, n, p, i, j: longInt;
	edge: array[ 1..24, 1..24 ] of boolean;

begin
	readln( t );
	while ( t > 0 ) do
	begin
		fillchar( edge, sizeOf(edge), 0 );
		readln( n, p );
		
		for i := 1 to n do
		begin
			edge[i][ (i mod n) + 1 ] := true;
			edge[ (i mod n) + 1 ][i] := true;
			
			edge[i][ (i + 1) mod n + 1 ] := true;
			edge[ (i + 1) mod n + 1 ][i] := true;
		end;
		
		for i := 1 to n do
			for j := 1 to i - 1 do
				if ( edge[i][j] ) or ( p > 0 ) then
				begin
					if ( not edge[i][j] ) then
						dec( p );
					
					writeln( i, ' ', j );
				end;
		
		dec( t );
	end;	
end.