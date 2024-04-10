program problem1;

var	n, m, i, ansP, ansQ, a, b, c: longInt;
	x: array[ 1..500 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
		read( x[i] );
	
	ansP := 0;
	ansQ := 1;
	for i := 1 to m do
	begin
		readln( a, b, c );
		
		if ( ( x[a] + x[b] ) * ansQ > ansP * c ) then
		begin
			ansP := x[a] + x[b];
			ansQ := c;
		end;
	end;
	
	writeln( (ansP / ansQ):0:15 );
end.