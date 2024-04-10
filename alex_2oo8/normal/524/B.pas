program problem1;
uses math;

var	n, i, j, ans, sum, hh: longInt;
	h, w: array[ 1..1000 ] of longInt;
	ok: boolean;

begin
	readln( n );
	for i := 1 to n do
		readln( h[i], w[i] );
	
	ans := 1000000000;
	for hh := 1 to 1000 do
	begin
		sum := 0;
		ok := true;
		for j := 1 to n do
			if ( max( h[j], w[j] ) <= hh ) then
				inc( sum, min( h[j], w[j] ) )
			else if ( min( h[j], w[j] ) > hh ) then
				ok := false
			else
				inc( sum, max( h[j], w[j] ) );
		
		if ( ok ) then
			ans := min( ans, sum * hh );
	end;
	
	writeln( ans );
end.