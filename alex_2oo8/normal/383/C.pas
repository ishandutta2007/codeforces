program problem3;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	first, index, lastChild, a, depth, fwt: array[ 1..200000 ] of longInt;
	e: array[ 1..400000 ] of tEdge;
	ee, x: longInt;

function fwt_read( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
		dec( x, x and -x  );
	end;
	
	exit( res );
end;

procedure fwt_update( x, d: longInt );
begin
	while ( x <= 200000 ) do
	begin
		inc( fwt[x], d );
		inc( x, x and -x );
	end;
end;

procedure fwt_add( l, r, d: longInt );
begin
	fwt_update( l, d );
	fwt_update( r + 1, -d );
end;

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
	inc( x );
	index[v] := x;
	depth[v] := d;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v, d + 1 );
			
		i := e[i].next;
	end;
	
	lastChild[v] := x;
end;

var	n, q, i, u, v, xx, y: longInt;

begin
	readln( n, q );
	for i := 1 to n do
		read( a[i] );

	for i := 1 to n - 1 do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	DFS( 1, 0, 0 );
	
	for i := 1 to q do
	begin
		read( y );
		
		if ( y = 1 ) then
		begin
			readln( v, xx );
			
			if ( odd( depth[v] ) ) then
				fwt_add( index[v], lastChild[v], xx )
			else
				fwt_add( index[v], lastChild[v], -xx );
		end
		else
		begin
			readln( v );
			
			if ( odd( depth[v] ) ) then
				writeln( a[v] + fwt_read( index[v] ) )
			else
				writeln( a[v] - fwt_read( index[v] ) );
		end;
	end;
end.