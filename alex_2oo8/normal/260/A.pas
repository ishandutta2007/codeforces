program problem1;

var	a, b, n, i: longInt;
	ans: ansistring;

begin
	readln( a, b, n );
	
	for i := 0 to 9 do
		if ( ( ( ( 10 * a ) + i ) mod b ) = 0 ) then
			break;
			
	if ( ( ( ( 10 * a ) + i ) mod b ) = 0 ) then
	begin
		str( a, ans );
		ans := ans + chr( ord('0') + i );
		for i := 2 to n do
			ans := ans + '0';
	end
	else
		ans := '-1';
		
	writeln( ans );
end.