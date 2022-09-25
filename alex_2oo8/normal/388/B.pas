program problem2;// fuck compilation error :(

const	LOG =	30;

var	g: array[ 1..1000, 1..1000 ] of char;

procedure addEdge( u, v: longInt );
begin
	g[u][v] := 'Y';
	g[v][u] := 'Y';
end;

var	n, k, i, j: longInt;
	pow: array[ 0..LOG ] of longInt;

begin
	fillchar( g, sizeOf(g), 'N' );

	readln( k );
	
	n := 4;
	addEdge( 1, 3 );
	addEdge( 1, 4 );
	for i := 1 to LOG do
	begin
		addEdge( n + 1, n );
		addEdge( n + 1, n - 1 );

		addEdge( n + 2, n );
		addEdge( n + 2, n - 1 );
		
		inc( n, 2 );
	end;
	
	for i := 0 to LOG do
	begin
		pow[i] := 2 * (i + 2);
		for j := 1 to LOG - i do
		begin
			inc( n );
			addEdge( n, pow[i] );
			pow[i] := n;
		end;
	end;
	
	for i := LOG downto 0 do
		if ( k >= 1 shl i ) then
		begin
			dec( k, 1 shl i );
			addEdge( 2, pow[i] );
		end;
		
	writeln( n );
	for i := 1 to n do
	begin
		for j := 1 to n do
			write( g[i][j] );
		writeln();
	end;
end.