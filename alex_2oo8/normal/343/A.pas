program problem1;

var	a, b, ans: int64;

begin
	readln( a, b );
	
	ans := 0;
	while ( a > 0 ) and ( b > 0 ) do
	begin
		if ( a > b ) then
		begin
			inc( ans, a div b );
			a := a mod b;
		end
		else
		begin
			inc( ans, b div a );
			b := b mod a;
		end;
	end;
	
	writeln( ans );
end.