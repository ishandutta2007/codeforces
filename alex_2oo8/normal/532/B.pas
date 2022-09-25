program problem2;
uses math;

var	n, i: longInt;
	p, a, g, h: array[ 1..200000 ] of int64;
	gg, hh: int64;

begin
	readln( n );
	for i := 1 to n do
		readln( p[i], a[i] );
	
	for i := 1 to n do
	begin
		g[i] := 0;
		h[i] := -1000000000000000;
	end;
	
	for i := n downto 1 do
	begin
		h[i] := max( h[i], g[i] + a[i] );
		
		if ( i = 1 ) then
			break;
		
		gg := g[ p[i] ];
		hh := h[ p[i] ];
		
		g[ p[i] ] := max( gg + g[i], hh + h[i] );
		h[ p[i] ] := max( gg + h[i], hh + g[i] );
	end;
	
	writeln( max( g[1], h[1] ) );
end.