program problem1;

const	md = 1000000007;

var	a, b: int64;

begin
	readln( a, b );
	
	writeln( ( ( ( ( ( ( a * (a + 1) ) div 2 ) mod md ) * b + a ) mod md ) * ( ( ( b * (b - 1) ) div 2 ) mod md ) ) mod md );
end.