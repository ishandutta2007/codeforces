program problem4;

type	tEdge =	record
					v, next: longInt;
				end;

var	ans, ans2: qWord;
	e: array[ 1..200000 ] of tEdge;
	first, sz: array[ 1..100000 ] of longInt;
	sz2: array[ 1..100000 ] of qWord;
	n: longInt;
	
procedure DFS0( v, p: longInt );
var	i: longInt;
begin
	sz[v] := 1;
	sz2[v] := 0;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
		begin
			DFS0( e[i].v, v );
			inc( sz[v], sz[ e[i].v ] );
			inc( sz2[v], ( qWord( sz[ e[i].v ] - 1 ) * sz[ e[i].v ] ) div 2 );
		end;
		
		i := e[i].next;
	end;
end;
	
procedure DFS( v, p: longInt; cnt1, cnt2: qWord );
var	i, u: longInt;
	cnt: qWord;
begin
	cnt := ( qWord( sz[v] - 1 ) * sz[v] ) div 2 - sz2[v];
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
		begin
			u := e[i].v;
			DFS( u, v, cnt1 + ( qWord( sz[v] - sz[u] ) * ( n - sz[v] ) ) + ( ( qWord( sz[v] - sz[u] - 1 ) * ( sz[v] - sz[u] ) ) div 2 ) - sz2[v] + ( ( qWord( sz[u] - 1 ) * sz[u] ) div 2 ), cnt2 + sz2[v] - ( ( qWord( sz[u] - 1 ) * sz[u] ) div 2 ) );
		end;
			
		i := e[i].next;
	end;
	
//writeln( 'v=', v, ' cnt1=', cnt1, ' cnt2=', cnt2, ' cnt=', cnt );
	
	inc( ans, ( cnt * cnt1 ) );
	inc( ans2, ( cnt * cnt2 ) );
end;

var	i, u, v: longInt;
	cnt2, cnt1: qWord;

begin
	readln( n );
	for i := 2 to n do
	begin
		readln( u, v );
		e[i].v := v;
		e[i].next := first[u];
		first[u] := i;
		
		e[n+i].v := u;
		e[n+i].next := first[v];
		first[v] := n + i;
	end;
	
	DFS0( 1, 0 );
	
	ans := 0;
	ans2 := 0;
	
	cnt2 := 0;
	i := first[1];
	while ( i > 0 ) do
	begin
		inc( cnt2, ( qWord( sz[ e[i].v ] - 1 ) * sz[ e[i].v ] ) div 2 );
		
		i := e[i].next;
	end;
	
	cnt1 := ( n * qWord(n-1) ) div 2 - cnt2;
	
	i := first[1];
	while ( i > 0 ) do
	begin
		DFS( e[i].v, 1, cnt1 - ( sz[ e[i].v ] * qWord( n - sz[ e[i].v ] ) ), cnt2 - ( ( qWord( sz[ e[i].v ] - 1 ) * sz[ e[i].v ] ) div 2 ) );
	
		i := e[i].next;
	end;

	inc( ans, ( ans2 div 2 ) );
	
	writeln( 2 * ans );
end.