program problem3;

const	md =	1000000007;

type	tEdge =	record
					v, c, next: longInt;
				end;

var	first, col: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;

procedure addEdge( u, v, c: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].c := c;
	e[ee].next := first[u];
	first[u] := ee;
end;

function dfs( v, c: longInt ): boolean;
var	i: longInt;
begin
	if ( col[v] <> 0 ) then
		exit( col[v] = c );
	
	col[v] := c;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( not dfs( e[i].v, c xor e[i].c ) ) then
			exit( false );
	
		i := e[i].next;
	end;
	
	exit( true );
end;

var	n, m, i, u, v, c, ans: longInt;

begin
	readln( n, m );
	for i := 1 to m do
	begin
		readln( u, v, c );
		
		if ( c = 1 ) then
			c := 0
		else
			c := 3;
		
		addEdge( u, v, c );
		addEdge( v, u, c );
	end;
	
	ans := 1;
	for i := 1 to n do
		if ( col[i] = 0 ) then
		begin
			ans := ( int64(2) * ans ) mod md;
			if ( not dfs( i, 1 ) ) then
				ans := 0;
		end;
	
	ans := ( ans * int64(1000000008 div 2) ) mod md;
	
	writeln( ans );
end.