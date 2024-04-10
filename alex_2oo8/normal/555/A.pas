program problem1;

var	n, k, i, m, j, a, p, ans: longInt;

begin
	readln( n, k );
	
	ans := 2 * n - k - 1;
	for i := 1 to k do
	begin
		read( m, p );
		if ( p = 1 ) then
			for j := 2 to m do
			begin
				read( a );
				
				if ( a - p = 1 ) then
					dec( ans, 2 )
				else
					break;
				
				p := a;
			end;
		
		readln();
	end;
	
	writeln( ans );
end.