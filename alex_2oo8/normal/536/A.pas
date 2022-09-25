program problem1;
uses math;

var	a, b: longInt;

function check( l, r, m: longInt ): int64;
var	sum: int64;
begin
	sum := a * int64(r - l + 1) + b * ( ( r * int64(r - 1) - (l - 1) * int64(l - 2) ) div 2 );
	exit( max( (sum + m - 1) div m, a + b * int64(r - 1) ) );
end;

var	n, l, t, m, r, i, j: longInt;

begin
	readln( a, b, n );
	for j := 1 to n do
	begin
		readln( l, t, m );
		
		if ( a + int64(l - 1) * b > t ) then
		begin
			writeln( -1 );
			
			continue;
		end;
		
		r := l;
		for i := 20 downto 0 do
			if ( check( l, r + (1 shl i), m ) <= t ) then
				inc( r, 1 shl i );
		
		writeln( r );
	end;
end.