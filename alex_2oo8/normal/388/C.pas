program problem3;

var	n, m, i, j, k, center, a, s1, s2: longInt;
	c: array[ 1..100 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( k );
		center := (k + 1) div 2;
		
		for j := 1 to k do
		begin
			read( a );
			
			if ( odd(k) ) and ( j = center ) then
			begin
				inc( m );
				c[m] := a;
			end
			else if ( j <= center ) then
				inc( s1, a )
			else
				inc( s2, a );
		end;
	end;
	
	for i := 1 to m do
		for j := i + 1 to m do
			if ( c[j] > c[i] ) then
			begin
				a := c[i];
				c[i] := c[j];
				c[j] := a;
			end;
			
	for i := 1 to m do
		if ( odd(i) ) then
			inc( s1, c[i] )
		else
			inc( s2, c[i] );
			
	writeln( s1, ' ', s2 );
end.