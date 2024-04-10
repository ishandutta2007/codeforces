program problem3;

var	n, i, x, ans, sum: longInt;
	cnt: array[ 0..4 ] of longInt;

begin
	readln( n );
	
	sum := 0;
	for i := 1 to n do
	begin
		read( x );
		
		inc( cnt[x] );
		inc( sum, x );
	end;
	
	if ( sum < 3 ) or ( sum = 5 ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	ans := 0;
	while ( cnt[1] > 0 ) and ( cnt[2] > 0 ) do
	begin
		inc( ans );
		
		dec( cnt[1] );
		dec( cnt[2] );
		inc( cnt[3] );
	end;
	
	while ( cnt[1] > 2 ) do
	begin
		inc( ans, 2 );
	
		dec( cnt[1], 3 );
		inc( cnt[3], 1 );
	end;
	
	if ( cnt[1] = 2 ) then
	begin
		inc( ans, 2 );
	
		if ( cnt[4] > 0 ) then
		begin
			dec( cnt[4], 1 );
			dec( cnt[1], 2 );
			inc( cnt[3], 1 );
		end
		else
		begin
			dec( cnt[3], 2 );
			dec( cnt[1], 2 );
			inc( cnt[4], 2 );
		end;
	end
	else if ( cnt[1] = 1 ) then
	begin
		if ( cnt[3] > 0 ) then
		begin
			inc( ans, 1 );
			
			dec( cnt[3], 1 );
			dec( cnt[1], 1 );
			inc( cnt[4], 1 );
		end
		else
		begin
			inc( ans, 2 );
			
			dec( cnt[4], 2 );
			dec( cnt[1], 1 );
			inc( cnt[3], 3 );
		end;
	end;
	
	while ( cnt[2] > 2 ) do
	begin
		inc( ans, 2 );
		
		dec( cnt[2], 3 );
		inc( cnt[3], 2 );
	end;
	
	if ( cnt[2] = 2 ) then
	begin
		inc( ans, 2 );
		
		dec( cnt[2], 2 );
		inc( cnt[4], 1 );
	end
	else if ( cnt[2] = 1 ) then
	begin
		if ( cnt[4] > 0 ) then
		begin
			inc( ans, 1 );
			
			dec( cnt[4], 1 );
			dec( cnt[2], 1 );
			inc( cnt[3], 2 );
		end
		else
		begin
			inc( ans, 2 );
			
			dec( cnt[2], 1 );
			dec( cnt[3], 2 );
			inc( cnt[4], 2 );
		end;
	end;
	
	writeln( ans );
end.