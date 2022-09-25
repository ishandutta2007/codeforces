program problem3;

var	n, i, j, k: longInt;
	f, g, h: array[ 1..200 ] of longInt;
	ok: boolean;
	lcm, ans: qWord;

begin
	readln( n );
	for i := 1 to n do
		read( f[i] );
	
	for i := 1 to n do	
		g[i] := f[i];
	
	ans := 1;
	while ( ans < 200 ) do
	begin
		ok := true;
		for i := 1 to n do
			ok := ok and ( g[ g[i] ] = g[i] );
		
		if ( ok ) then
			break;
		
		inc( ans, 1 );
		for i := 1 to n do
			h[i] := f[ g[i] ];
		
		for i := 1 to n do
			g[i] := h[i];
	end;
	
	lcm := 1;
	for i := 1 to n do
	begin
		j := g[i];
		k := 1;
		while ( f[j] <> g[i] ) do
		begin
			j := f[j];
			inc( k );
		end;
		
		j := k;
		while ( lcm mod j > 0 ) or ( k mod j > 0 ) do
			dec( j );
		
		lcm := lcm * ( k div j );
	end;
	
	if ( ans mod lcm > 0 ) then
		inc( ans, lcm - ans mod lcm );
	
	writeln( ans );
end.