program problem1;

var	c: char;
	cnt: array[ '1'..'3' ] of longInt;

begin
	while ( not EOLn() ) do
	begin
		read( c );
		if ( c <> '+' ) then
			inc( cnt[c] );
	end;
	
	c := '1';
	while ( cnt[c] = 0 ) do
		inc( c );
		
	write( c );
	dec( cnt[c] );
	
	while ( c <= '3' ) do
	begin
		if ( cnt[c] = 0 ) then
		begin
			inc( c );
			continue;
		end;
		
		write( '+', c );
		dec( cnt[c] );
	end;
	
	writeln();
end.