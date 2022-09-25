program problem2;
uses math;

var	n, i, j: longInt;
	p: array[ 1..100 ] of extended;
	ans, cur, q: extended;

begin
	readln( n );
	for i := 1 to n do
		read( p[i] );
	
	for i := 1 to n do
		for j := i + 1 to n do
			if ( p[j] > p[i] ) then
			begin
				cur := p[i];
				p[i] := p[j];
				p[j] := cur;
			end;

	ans := p[1];
	cur := 0.0;
	q := 1.0;
	for i := 1 to n do
	begin		
		cur := cur * ( 1 - p[i] ) + p[i] * q;
		q := q * ( 1 - p[i] );
		
		ans := max( ans, cur );
	end;
	
	writeln( ans:0:15 );
end.