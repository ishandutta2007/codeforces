program problem1;
uses math;

var	n, i, k, f, t: longInt;
	ans: int64;

begin
	readln( n, k );
	ans := -trunc( 1.0e+15 );
	for i := 1 to n do
	begin
		readln( f, t );
		ans := max( ans, ( f - max( 0, ( t - k ) ) ) );
	end;
	
	writeln( ans );
end.