program problem1;

var	n, i, a, b, c, x1, x2, y1, y2, ans: longInt;
	s1, s2: int64;

begin
	readln( x1, y1, x2, y2, n );
	
	ans := 0;
	for i := 1 to n do
	begin
		readln( a, b, c );
		
		s1 := int64(a) * x1 + int64(b) * y1 + c;
		s2 := int64(a) * x2 + int64(b) * y2 + c;
		if ( s1 < 0 ) xor ( s2 < 0 ) then
			inc( ans );
	end;
	
	writeln( ans );
end.