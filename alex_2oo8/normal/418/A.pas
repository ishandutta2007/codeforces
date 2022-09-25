program problem1;

var	n, k, i, j: longInt;

begin
	readln( n, k );
	
	if ( k > (n - 1) div 2 ) then
		writeln( -1 )
	else
	begin
		writeln( n * k );
		for i := 1 to n do
			for j := 1 to k do
				writeln( i, ' ', (i + j - 1) mod n + 1 );
	end;
end.