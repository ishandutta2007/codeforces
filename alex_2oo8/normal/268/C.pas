program problem3;
uses math;

var	n, m, i, j, k: longInt;

begin
	readln( n, m );
	
	n := min( n, m );
	
	writeln( n + 1 );
	for i := 0 to n do
		writeln( i, ' ', (n-i) );
end.