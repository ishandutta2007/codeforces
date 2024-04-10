program problem3;

var	x1, y1, x2, y2: longInt;

begin
	readln( x1, y1, x2, y2 );
	
	while ( true ) do
	begin
		if ( x2 - y2 < x1 - y1 ) and ( x1 > 0 ) and ( ( x1 <> x2 + 1 ) or ( y1 <> y2 ) ) then
			dec( x1 )
		else if ( y1 > 0 ) and ( ( y1 <> y2 + 1 ) or ( x1 <> x2 ) ) then
			dec( y1 )
		else if ( x1 > 0 ) and ( ( x1 <> x2 + 1 ) or ( y1 <> y2 ) ) then
			dec( x1 );
		
		if ( x1 + y1 = 0 ) then
		begin
			writeln( 'Polycarp' );
			
			halt;
		end;
		
		if ( x2 > 0 ) and ( y2 > 0 ) and ( ( x2 <> x1 + 1 ) or ( y2 <> y1 + 1 ) ) then
		begin
			dec( x2 );
			dec( y2 );
		end
		else if ( x2 > 0 ) and ( ( x2 <> x1 + 1 ) or ( y2 <> y1 ) ) then
			dec( x2 )
		else if ( y2 > 0 ) and ( ( y2 <> y1 + 1 ) or ( x2 <> x1 ) ) then
			dec( y2 );
		
		if ( x2 + y2 = 0 ) then
		begin
			writeln( 'Vasiliy' );
			
			halt;
		end;
	end;
end.