program problem2;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;

var	first, v, plus, minus: array[ 1..100000 ] of int64;
	e: array[ 1..200000 ] of tEdge;
	
procedure DFS( u, par: longInt );
var	i: longInt;
begin
	plus[u] := 0;
	minus[u] := 0;
	
	i := first[u];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) then
		begin
			DFS( e[i].v, u );
			
			plus[u] := max( plus[u], plus[ e[i].v ] );
			minus[u] := max( minus[u], minus[ e[i].v ] );
		end;
		
		i := e[i].next;
	end;
	
	v[u] := v[u] + plus[u] - minus[u];
	if ( v[u] > 0 ) then
		inc( minus[u], abs( v[u] ) )
	else
		inc( plus[u], abs( v[u] ) );
end;

var	n, i, a, b: longInt;

begin
	fillchar( first, sizeOf(first), 0 );

	readln( n );
	for i := 2 to n do
	begin
		readln( a, b );
		
		e[i].v := a;
		e[i].next := first[b];
		first[b] := i;
		
		e[n+i].v := b;
		e[n+i].next := first[a];
		first[a] := n + i;
	end;
	
	for i := 1 to n do
		read( v[i] );
	
	DFS( 1, 0 );
	
	writeln( plus[1] + minus[1] );
end.