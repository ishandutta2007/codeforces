program problem1;

var	n, k, i, x, ans: longInt;

begin
	readln( n, k );
	
	ans := 0;
	for i := 1 to n do
	begin
		read( x );
		
		if ( x + k <= 5 ) then
			inc( ans );
	end;
	
	writeln( ans div 3 );
end.