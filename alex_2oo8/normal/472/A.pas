program problem1;

var	n, i, j: longInt;
	p: array[ 1..1000000 ] of boolean;

begin
	readln( n );
	
	for i := 1 to n do
		p[i] := true;
	
	for i := 2 to n do
		for j := 2 to n div i do
			p[i * j] := false;
	
	i := 1;
	while ( p[i] or p[n - i] ) do
		inc( i );
	
	writeln( i, ' ', n - i );
end.