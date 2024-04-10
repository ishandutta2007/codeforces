program problem2;
uses math;

const	MAXV =	1000000;

var	n, i, j, x, ans: longInt;
	have: array[ 0..2 * MAXV ] of boolean;
	last: array[ 0..2 * MAXV ] of longInt;

begin
	fillchar( have, sizeOf(have), 0 );
	
	readln( n );
	for i := 1 to n do
	begin
		read( x );
		
		have[x] := true;
	end;
	
	last[0] := -1;
	for i := 1 to 2 * MAXV do
		if ( have[i] ) then
			last[i] := i
		else
			last[i] := last[i - 1];
	
	ans := 0;
	for i := 1 to MAXV do
		if ( have[i] ) then
			for j := 1 to MAXV div i do
				if ( last[ i * (j + 1) - 1 ] >= i * j ) then
					ans := max( ans, last[ i * (j + 1) - 1 ] - (i * j) );
	
	writeln( ans );
end.