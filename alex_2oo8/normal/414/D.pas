program problem4;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;

var	first, depth: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	ee: longInt = 0;
	
procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure DFS( v, p, d: longInt );
var	i: longInt;
begin
	depth[v] := d;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v, d + 1 );
	
		i := e[i].next;
	end;
end;

var	n, k, p, i, j, u, v, ans, l, r, sum: longInt;
	cnt, a: array[ 1..100000 ] of longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n, k, p );
	
	for i := 1 to n - 1 do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	DFS( 1, 0, 1 );
	
	for i := 1 to n do
		inc( cnt[ depth[i] ] );
	
	v := 0;
	for i := 2 to n do
		for j := 1 to cnt[i] do
		begin
			inc( v );
			a[v] := i;
		end;

	a[n] := a[n - 1];
		
	ans := 0;
	l := n - 1;
	sum := 0;
	for r := n - 1 downto 1 do
	begin
		if ( a[r + 1] > a[r] ) then
			dec( sum, r - l + 1 );
			
		while ( l > 1 ) and ( sum + a[r] - a[l - 1] <= p ) do
		begin
			dec( l );
			inc( sum, a[r] - a[l] );
		end;
		
		ans := max( ans, r - l + 1 );
	end;
	
	writeln( min( ans, k ) );
end.