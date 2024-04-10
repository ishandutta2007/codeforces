program problem1;

var	n, i, x: longInt;
	a, b, c: array[ 0..1000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( x );
		
		if ( x = 0 ) then
		begin
			inc( c[0] );
			c[ c[0] ] := x;
		end
		else if ( x < 0 ) then
		begin
			inc( a[0] );
			a[ a[0] ] := x;
		end
		else 
		begin
			inc( b[0] );
			b[ b[0] ] := x;
		end;
	end;
	
	if ( not odd( a[0] ) ) then
	begin
		inc( c[0] );
		c[ c[0] ] := a[ a[0] ];
		dec( a[0] );
	end;
	
	if ( b[0] = 0 ) then
	begin
		b[0] := 2;
		b[1] := a[ a[0] ];
		b[2] := a[ a[0] - 1 ];
		dec( a[0], 2 );
	end;
	
	write( a[0] );
	for i := 1 to a[0] do
		write( ' ', a[i] );
	writeln();
	
	write( b[0] );
	for i := 1 to b[0] do
		write( ' ', b[i] );
	writeln();
	
	write( c[0] );
	for i := 1 to c[0] do
		write( ' ', c[i] );
	writeln();	
end.