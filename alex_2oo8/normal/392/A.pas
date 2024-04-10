program problem1;
uses math;

var	n, i, j, k, ans: longInt;

begin
	readln( n );
	
	if ( n = 0 ) then
	begin
		writeln( 1 );
		halt;
	end;
	
	ans := 1;
	j := 0;
	for i := n - 1 downto 1 do
	begin
		k := j;
		while ( i * int64(i) + (j + 1) * int64(j + 1) <= n * int64(n) ) do
			inc( j );
			
		inc( ans, max(1, j - k) );
	end;
	
	writeln( 4 * ans );
end.