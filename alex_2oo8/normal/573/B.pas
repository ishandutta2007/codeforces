program problem2;
uses math;

var	n, ans, bs, i: longInt;
	h, l, r: array[ 0..100001 ] of longInt;
	ok: boolean;

begin
	readln( n );
	for i := 1 to n do
		read( h[i] );
	
	ans := 0;
	for bs := 20 downto 0 do
	begin
		inc( ans, 1 shl bs );
		
		l[0] := -ans;
		for i := 1 to n do
			l[i] := min( l[i - 1] + 1, h[i] - ans );
		
		r[n + 1] := -ans;
		for i := n downto 1 do
			r[i] := min( r[i + 1] + 1, h[i] - ans );
		
		ok := false;
		for i := 1 to n do
			if ( min( l[i], r[i] ) > 0 ) then
				ok := true;
			
		if ( not ok ) then
			dec( ans, 1 shl bs );
	end;
	
	writeln( ans + 1 );
end.