program probelm3;

var	n, i, x, y: longInt;
	cnt: array[ 1..1000000 ] of longInt;
	ans: int64;

begin
	fillchar( cnt, sizeOf(cnt), 0 );
	
	readln( n );
	for i := 1 to n do
	begin
		read( x );
		
		inc( cnt[x] );
	end;
	
	y := 0;
	for i := 1000000 downto 2 do
		if ( odd( cnt[i] ) ) and ( cnt[i] > y ) then
		begin
			inc( cnt[i - 1] );
			y := 1;
		end
		else
			y := 0;
	
	ans := 0;
	y := 0;
	for i := 1000000 downto 1 do
	begin
		x := cnt[i] div 2;
		
		if ( y > 0 ) and ( x > 0 ) then
		begin
			inc( ans, y * int64(i) );
			y := 0;
			dec( x );
		end;
		
		inc( ans, i * int64(i) * (x div 2) );
		
		if ( odd(x) ) then
			y := i;
	end;
	
	writeln( ans );
end.