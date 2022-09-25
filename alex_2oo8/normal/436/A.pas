program problem1;
uses math;

var	n, x: longInt;
	t, h, m, used: array[ 1..2000 ] of longInt;
	
function solve( p: longInt ): longInt;
var	res, i, k, xx: longInt;
begin
	fillchar( used, sizeOf(used), 0 );

	res := 0;
	xx := x;
	
	while ( true ) do
	begin
		k := -1;
		for i := 1 to n do
			if ( used[i] = 0 ) and ( t[i] = p ) and ( h[i] <= xx ) and ( (k = -1) or ( m[i] > m[k] ) ) then
				k := i;
		
		if ( k = -1 ) then
			break;
		
		inc( res );
		
		inc( xx, m[k] );
		used[k] := 1;
		p := p xor 1;
	end;
	
	exit( res );
end;
	
var	i: longInt;

begin
	readln( n, x );
	for i := 1 to n do
		readln( t[i], h[i], m[i] );
	
	writeln( max( solve(0), solve(1) ) );
end.