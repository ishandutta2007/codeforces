program problem1;
uses math;

var	x, y, m, ans: int64;

begin
	ans := 0;
	
	readln( x, y, m );
	
	if ( max( x, y ) >= m ) then
	begin
		writeln( 0 );
		halt;
	end;
	
	if ( max( x, y ) <= 0 ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	if ( x < 0 ) then
	begin
		ans := -x div y;
		
		inc( x, y * ans );
	end;
	
	if ( y < 0 ) then
	begin
		ans := -y div x;
		
		inc( y, x * ans );
	end;

	while ( max( x, y ) < m ) do
	begin
		inc( ans );
		
		if ( x < y ) then
			x := x + y
		else
			y := x + y;
	end;
	
	writeln( ans );
end.