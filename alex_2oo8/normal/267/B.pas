program problem2;

type	tEdge =	record
					u, v, nextU, nextV: longInt;
					used: boolean;
					c: char;
				end;

var	first, deg: array[ 0..6 ] of longInt;
	e: array[ 1..100 ] of tEdge;
	ans: array[ 0..100 ] of longInt;
	
function findEdge( v: longInt ): longInt;
var	i, t: longInt;
begin
	while ( e[ first[v] ].used ) do
		if ( e[ first[v] ].u = v ) then
			first[v] := e[ first[v] ].nextU
		else
			first[v] := e[ first[v] ].nextV;

	i := first[v];
	if ( e[i].u <> v ) then
	begin
		t := e[i].u;
		e[i].u := e[i].v;
		e[i].v := t;
		
		t := e[i].nextU;
		e[i].nextU := e[i].nextV;
		e[i].nextV := t;
		
		e[i].c := '+';
	end
	else
		e[i].c := '-';
	
	e[i].used := true;
	dec( deg[ e[i].u ] );
	dec( deg[ e[i].v ] );
	
	exit( i );
end;
	
procedure DFS( v: longInt );
var	i: longInt;
begin
	while ( deg[v] > 0 ) do
	begin
		i := findEdge( v );
		
		DFS( e[i].v );
		
		inc( ans[0] );
		ans[ ans[0] ] := i;
	end;
end;
	
var	n, i, j, k: longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( e[i].u, e[i].v );
		e[i].nextU := first[ e[i].u ];
		first[ e[i].u ] := i;
		e[i].nextV := first[ e[i].v ];
		first[ e[i].v ] := i;
		e[i].used := false;
		
		inc( deg[ e[i].u ] );
		inc( deg[ e[i].v ] );
	end;
	
	i := 0;
	k := 0;
	for j := 0 to 6 do
		if odd( deg[j] ) then
		begin
			i := j;
			inc( k );
		end;
		
	while ( deg[i] = 0 ) do
		inc( i );
		
	if ( k > 2 ) then
	begin
		writeln( 'No solution' );
		halt;
	end;

	DFS( i );
	
	if ( ans[0] = n ) then
	begin
		for i := 1 to n do
			writeln( ans[i], ' ', e[ ans[i] ].c );
	end
	else
		writeln( 'No solution' );
end.