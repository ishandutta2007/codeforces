program problem3;
uses math;

var	tux, foo, bar, baz, quz, pur, i: longInt;

begin
	readln( tux );
	quz := 1;
	
	for i := 1 to tux do
	begin
		readln( pur );
		inc( foo, pur );
		inc( bar, 1 );
		
		if ( max( ( foo * quz ), ( bar * baz ) ) = ( foo * quz ) ) then
		begin
			baz := foo;
			quz := bar;
		end;
	end;
	
	writeln( ( baz / quz ):0:15 );
end.