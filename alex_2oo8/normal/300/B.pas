program problem2;

var	n, m, i, j, k, a, b: longInt;
	g: array[ 1..100, 0..100 ] of longInt;
	p: array[ 1..100 ] of longInt;
	
function find( x: longInt ): longInt;
begin
	while ( g[x][0] = 0 ) do
		x := p[x];
		
	exit( x );
end;

begin
	readln( n, m );
	
	for i := 1 to n do
	begin
		g[i][0] := 1;
		g[i][1] := i;
	end;
	
	for i := 1 to m do
	begin
		readln( a, b );
		
		a := find( a );
		b := find( b );

		if ( a <> b ) then
		begin
			for j := 1 to g[b][0] do
				g[a][ g[a][0] + j ] := g[b][j];
				
			inc( g[a][0], g[b][0] );
			g[b][0] := 0;
			p[b] := a;
		end;
	end;
	
	for i := 1 to n do
		if ( g[i][0] = 2 ) then
			for j := 1 to n do
				if ( g[j][0] = 1 ) then
				begin
					g[i][0] := 3;
					g[i][3] := g[j][1];
					g[j][0] := 0;
					
					break;
				end;
				
	for i := 1 to n do
		if ( g[i][0] = 1 ) then
			for j := (i+1) to n do
				if ( g[j][0] = 1 ) then
					for k := (j+1) to n do
						if ( g[k][0] = 1 ) and ( g[i][0] = 1 ) then
						begin
							g[i][0] := 3;
							g[i][2] := g[j][1];
							g[i][3] := g[k][1];
							
							g[j][0] := 0;
							g[k][0] := 0;
							
							break;
						end;
				
	for i := 1 to n do
		if ( g[i][0] <> 3 ) and ( g[i][0] <> 0 ) then
		begin
			writeln( -1 );
			halt;
		end;
		
	for i := 1 to n do
		if ( g[i][0] = 3 ) then
			writeln( g[i][1], ' ', g[i][2], ' ', g[i][3] );
end.