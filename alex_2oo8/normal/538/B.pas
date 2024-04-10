program problem2;
uses math;

var	n, k, x, i: longInt;
	a: array[ 1..10 ] of longInt;

begin
	readln( n );
	k := 0;
	x := 0;
	while ( n > 0 ) do
	begin
		inc( k );
		a[k] := n mod 10;
		n := n div 10;
		x := max( x, a[k] );
	end;
	
	writeln( x );
	while ( k > 0 ) do
	begin
		x := 0;
		for i := k downto 1 do
		begin
			x := 10 * x;
			if ( a[i] > 0 ) then
			begin
				dec( a[i] );
				
				inc( x );
			end;
		end;
		
		write( x, ' ' );
		
		while ( k > 0 ) and ( a[k] = 0 ) do
			dec( k );
	end;
	
	writeln();
end.