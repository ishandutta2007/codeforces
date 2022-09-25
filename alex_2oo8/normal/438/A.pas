program problem1;
uses math;

var	n, m, i, a, b: longInt;
	v: array[ 1..100000 ] of longInt;
	ans: int64;

begin
	readln( n, m );
	for i := 1 to n do	
		read( v[i] );
	
	ans := 0;
	for i := 1 to m do
	begin
		readln( a, b );
		
		inc( ans, min( v[a], v[b] ) );
	end;
	
	writeln( ans );
end.