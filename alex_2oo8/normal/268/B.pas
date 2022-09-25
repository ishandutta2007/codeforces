program problem2;

var	n, i: longInt;
	ans: int64;

begin
	readln( n );
	
	ans := 0;
	for i := 1 to n do
		inc( ans, ( i * (n-i+1) - i + 1 ) );
		
	writeln( ans );
end.