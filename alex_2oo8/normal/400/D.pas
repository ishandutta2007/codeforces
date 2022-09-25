program problem4;
uses math;

const	inf =	1000000000;

type	tEdge =	record
					v, d, next: longInt;
				end;

var	first: array[ 1..100000 ] of longInt;
	visited: array[ 1..100000 ] of boolean;
	e: array[ 1..200000 ] of tEdge;
	ee: longint = 0;
	
procedure addEdge( u, v, d: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].d := d;
	e[ee].next := first[u];
	first[u] := ee
end;

procedure dfs( v: longInt );
var	i: longInt;
begin
	if ( visited[v] ) then
		exit();
	
	visited[v] := true;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].d = 0 ) then
			dfs( e[i].v );
	
		i := e[i].next;
	end;
end;

var	n, m, k, i, j, u, v, x: longInt;
	c, cc, ccc: array[ 0..100000 ] of longInt;
	d: array[ 1..500, 1..500 ] of longInt;

begin
	readln( n, m, k );
	
	for i := 1 to k do
		read( c[i] );
		
	cc[0] := 0;
	for i := 1 to k do
		cc[i] := cc[i - 1] + c[i];
		
	for i := 1 to k do
		for j := cc[i - 1] + 1 to cc[i] do
			ccc[j] := i;
		
	for i := 1 to m do
	begin
		readln( u, v, x );
		
		addEdge( u, v, x );
		addEdge( v, u, x );
	end;
	
	for i := 1 to k do
		for j := 1 to k do
			d[i][j] := inf;
	
	for i := 1 to k do
	begin
		d[i][i] := 0;
	
		fillchar( visited, sizeOf(visited), 0 );
		
		dfs( cc[i] );
		
		for j := cc[i - 1] + 1 to cc[i] do
		begin
			x := first[j];
			while ( x > 0 ) do
			begin
				d[i][ ccc[ e[x].v ] ] := min( d[i][ ccc[ e[x].v ] ], e[x].d );
			
				x := e[x].next;
			end;
		
			if ( not visited[j] ) then
			begin
				writeln( 'No' );
				halt;
			end;
		end;
	end;
	
	for x := 1 to k do
		for i := 1 to k do
			for j := 1 to k do
				d[i][j] := min( d[i][j], d[i][x] + d[x][j] );
				
	writeln( 'Yes' );
	for i := 1 to k do
	begin
		for j := 1 to k do
			if ( d[i][j] = inf ) then
				write( '-1 ' )
			else
				write( d[i][j], ' ' );
		writeln();
	end;
end.