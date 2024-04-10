program problem3;

type	tEdge =	record
					v, next, f: longInt;
				end;

var	first, deg: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;

procedure addEdge( u, v: longInt );
const	ee: longInt = 1;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].f := 2;
	e[ee].next := first[u];
	first[u] := ee;
	
	inc( deg[u] );
end;

var	n, i, j, u, v: longInt;
	ok: boolean;

begin
	readln( n );
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	for i := 1 to n do
		if ( deg[i] = 1 ) then
		begin
			v := i;
			u := -1;
			while ( deg[v] <= 2 ) do
			begin
				if ( first[v] = u xor 1 ) then
					u := e[ first[v] ].next
				else
					u := first[v];
				
				e[u xor 1].f := 0;
				
				if ( deg[ e[u].v ] = 1 ) then
					break;
				
				v := e[u].v;
			end;
		end;
	
	for i := 2 to 2 * n - 1 do
		if ( e[i].f = 2 ) then
		begin
			v := e[i].v;
			ok := deg[ e[i].v ] <= 3;
			j := first[v];
			while ( ok ) and ( j > 0 ) do
			begin
				ok := ok and ( ( j = i xor 1 ) or ( e[j].f = 0 ) );
			
				j := e[j].next;
			end;
			
			if ( ok ) then
				e[i].f := 1;
		end;
	
	for i := 1 to n do
	begin
		v := 0;
		j := first[i];
		while ( j > 0 ) do
		begin
			if ( e[j].f = 2 ) then
				inc( v );
		
			j := e[j].next;
		end;
		
		if ( v > 2 ) then
		begin
			writeln( 'No' );
			
			halt;
		end;
	end;
	
	writeln( 'Yes' );
end.