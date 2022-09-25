program problem3;

type	tEdge =	record
					v, next: longInt;
				end;

var	first, up: array[ 1..100000 ] of longInt;
	visited: array[ 1..100000 ] of boolean;
	e: array[ 1..200000 ] of tEdge;
	ee: longInt = 0;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

function DFS( v, p: longInt ): boolean;
var	i: longInt;
begin
	visited[v] := true;
	up[v] := -1;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) and ( visited[ e[i].v ] ) then
		begin
			if ( up[v] = -1 ) then
				up[v] := e[i].v
			else
			begin
				writeln( up[v], ' ', v, ' ', e[i].v );
				
				up[v] := -1;
			end;
		end;
	
		i := e[i].next;
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) and ( not visited[ e[i].v ] ) then
		begin
			if ( DFS( e[i].v, v ) ) then
			begin
				if ( up[v] = -1 ) then
					up[v] := e[i].v
				else
				begin
					writeln( up[v], ' ', v, ' ', e[i].v );
					
					up[v] := -1;
				end;
			end;
		end;
		
		i := e[i].next;
	end;
	
	if ( up[v] <> -1 ) then
		writeln( up[v], ' ', v, ' ', p );
	
	exit( up[v] = -1 );
end;

var	n, m, i, u, v: longInt;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );
	
	readln( n, m );
	
	if ( odd(m) ) then
	begin
		writeln( 'No solution' );
		halt;
	end;
	
	for i := 1 to m do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	DFS( 1, 0 );
end.