program problem2;

var	n, k, i: longInt;

begin
	readln( n, k );
	writeln( (6 * n - 1) * k );
	
	for i := 1 to n do
		writeln( k * (6 * i - 5), ' ', k * (6 * i - 4), ' ', k * (6 * i - 3), ' ', k * (6 * i - 1) );
end.