program problem1;

var	n, i: longInt;
	a, b: array[ 1..100000 ] of longInt;

begin
	readln( n );
	
	if ( not odd(n) ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	for i := 1 to (n-1) div 2 do
	begin
		a[i] := 2 * i - 1;
		b[i] := n - i;
	end;
	
	a[ (n-1) div 2 + 1 ] := 0;
	b[ (n-1) div 2 + 1 ] := (n-1) div 2;
	for i := (n-1) div 2 + 2 to n do
	begin
		a[i] := a[i-1] + 2;
		b[i] := b[i-1] - 1;
	end;
	
	for i := 1 to n do
		write( a[i], ' ' );
	writeln();
	
	for i := 1 to n do
		write( b[i], ' ' );
	writeln();
	
	for i := 1 to n do
		write( i - 1, ' ' );
	writeln();
end.