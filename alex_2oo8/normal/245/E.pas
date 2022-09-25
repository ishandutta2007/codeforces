program problem5;

var str: ansistring;
	a, b, ans, i: longInt;

begin
	readln( str );
	
	a := 0;
	b := 0;
	ans := 0;
	for i := 1 to length(str) do
		if ( str[i] = '+' ) then
		begin
			inc( a );
			if ( b > 0 ) then
				dec( b )
			else
				inc( ans );
		end
		else
		begin
			inc( b );
			if ( a > 0 ) then
				dec( a )
			else
				inc( ans );
		end;
		
	writeln( ans );
end.