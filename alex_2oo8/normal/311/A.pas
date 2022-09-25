program problem1;

var	n, k, i: longInt;

begin
	readln( n, k );
	
	if ( k >= ( n * (n-1) div 2 ) ) then
	begin
		writeln( 'no solution' );
		halt;
	end;
	
	for i := 1 to n do
		writeln( '0 ', i );
end.