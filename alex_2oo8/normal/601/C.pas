program problem3;

var	n, m, i, j, ci, li, sum: longInt;
	x: array[ 1..100 ] of longInt;
	f, g: array[ 0..1, -1000..101000 ] of extended;
	p: extended;

begin
	readln( n, m );
	for i := 1 to n do
		read( x[i] );
	
	if ( m = 1 ) then
	begin
		writeln( '1.0' );
		
		halt;
	end;
	
	f[0][0] := 1.0;
	for i := 0 to m - 1 do
		g[0][i] := 1.0;
	
	for i := 1 to n do
	begin
		ci := i and 1;
		li := ci xor 1;
		
		for j := 0 to i - 1 do
		begin
			f[ci][j] := 0.0;
			g[ci][j] := 0.0;
		end;
		
		for j := i to i * m do
		begin
			f[ci][j] := ( g[li][j - 1] - f[li][j - x[i]] ) / (m - 1);
			g[ci][j] := g[ci][j - 1] + f[ci][j] - f[ci][j - m];
		end;
		
		for j := i * m + 1 to (i + 1) * m do
			g[ci][j] := g[ci][j - 1] - f[ci][j - m];
	end;
	
	sum := 0;
	for i := 1 to n do
		inc( sum, x[i] );
	
	p := 0.0;
	for i := 0 to sum - 1 do
		p := p + f[ci][i];
	
	writeln( (1 + (m - 1) * p):0:15 );
end.