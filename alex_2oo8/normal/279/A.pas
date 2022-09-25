program problem1;
uses math;

var	xx, yy, x0, y0, x, y, ans, t: longInt;

begin
	readln( xx, yy );
	
	t := 2;
	x := 0;
	y := 0;
	ans := 0;
	while ( true ) do
	begin
		x0 := x;
		y0 := y;
		if ( (t mod 2) = 0 ) then
		begin
			if ( (t mod 4) = 0 ) then
				dec( x, (t div 2) )
			else
				inc( x, (t div 2) );
		end
		else
		begin
			if ( ((t-1) mod 4) = 0 ) then
				dec( y, (t div 2) )
			else
				inc( y, (t div 2) );
		end;
		
		if 	( ( x0 = x ) and ( x = xx ) and ( min( y, y0 ) <= yy ) and ( max( y, y0 ) >= yy ) ) or
			( ( y0 = y ) and ( y = yy ) and ( min( x, x0 ) <= xx ) and ( max( x, x0 ) >= xx ) ) then
				break;
				
		inc( ans );
		inc( t );
	end;
	
	writeln( ans );
end.