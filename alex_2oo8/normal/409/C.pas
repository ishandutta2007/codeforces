program problem3;
uses math;

var	a, b, c, d, e: longInt;

begin
	readln( a, b, c, d, e );
	
	writeln( min( min(a, b), min( c div 2, min( d div 7, e div 4 ) ) ) );
end.