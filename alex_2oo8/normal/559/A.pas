program problem1;

var	a, b, c, d, e, f: longInt;

begin
	readln( a, b, c, d, e, f );
	
	writeln( sqr(a + b + c) - sqr(a) - sqr(c) - sqr(e) );
end.