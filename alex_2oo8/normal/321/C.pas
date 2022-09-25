program problem3;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	e: array[ 1..200000 ] of tEdge;
	ee: longInt;
	first, sz, ans: array[ 0..100000 ] of longInt;
	
procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure initSizes( v, p: longInt );
var	i: longInt;
begin
	sz[v] := 1;

	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
		begin
			initSizes( e[i].v, v );
			
			inc( sz[v], sz[ e[i].v ] );
		end;
		
		i := e[i].next;
	end;
end;

function findCenter( v, p: longInt ): longInt;
var	u, w, i, s: longInt;
begin
	s := sz[v] div 2;

	u := p;
	w := v;
	while ( w > 0 ) do
	begin
		p := u;
		u := w;
		w := 0;
		
		i := first[u];
		while ( i > 0 ) do
		begin
			if ( e[i].v <> p ) and ( sz[ e[i].v ] > s ) then
				w := e[i].v;
				
			i := e[i].next;
		end;
	end;
	
	exit( u );
end;

procedure solve( v, c: longInt );
var	i, j, u: longInt;
begin
	initSizes( v, 0 );
	v := findCenter( v, 0 );
	
	ans[v] := c;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		u := e[i].v;
		if ( e[ first[u] ].v = v ) then
			first[u] := e[ first[u] ].next
		else
		begin
			j := first[u];
			while ( e[ e[j].next ].v <> v ) do
				j := e[j].next;
				
			e[j].next := e[ e[j].next ].next;
		end;
	
		solve( u, c + 1 );
			
		i := e[i].next;
	end;
end;

var	n, i, u, v: longInt;

begin
	readln( n );
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	solve( 1, 0 );
		
	for i := 1 to n do
		write( chr( ord( 'A' ) + ans[i] ), ' ' );
	writeln();
end.