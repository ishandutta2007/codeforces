program problem5;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;

var	e: array[ 1..200000 ] of tEdge;
	first, group, deg, groupSize, fwt_l, fwt_r: array[ 0..100000 ] of longInt;
	fwt: array[ 1..300000 ] of int64;
	n: longInt;
	
procedure DFS( v, par, g: longInt );
var	i: longInt;
begin
	deg[v] := deg[par] + 1;
	group[v] := g;
	inc( groupSize[g] );
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> par ) then
			DFS( e[i].v, v, g );
			
		i := e[i].next;
	end;
end;

procedure fwt_update( x, d, l, r: longInt );
begin
	while ( (l+x-1) <= r ) do
	begin
		inc( fwt[l+x-1], d );
		inc( x, (x and -x) );
	end;
end;

function fwt_read( x, l, r: longInt ): int64;
var res: int64;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[l+x-1] );
		dec( x, (x and -x) );
	end;
	
	exit( res );
end;

var	q, i, j, k, t, v, x, d: longInt;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( fwt, sizeOf(fwt), 0 );

	readln( n, q );
	for i := 2 to n do
	begin
		readln( j, k );
		e[i].v := k;
		e[i].next := first[j];
		first[j] := i;
		
		e[n+i].v := j;
		e[n+i].next := first[k];
		first[k] := n + i;
	end;
	
	fwt_r[0] := n;
	deg[1] := 0;
	i := first[1];
	k := 0;
	while ( i > 0 ) do
	begin
		inc( k );
		groupSize[k] := 0;
		fwt_l[k] := fwt_r[k-1] + 1;
		DFS( e[i].v, 1, k );
		fwt_r[k] := fwt_l[k] + groupSize[k] - 1;
		
		i := e[i].next;
	end;
	
	for i := 1 to q do
	begin
		read( t );
		if ( t = 0 ) then
		begin
			readln( v, x, d );
			
			if ( d >= deg[v] ) then
				fwt_update( ( n - d + deg[v] ), x, 1, n );
				
			if ( v <> 1 ) then
			begin
				if ( d >= deg[v] ) then
					fwt_update( ( d - deg[v] + 1 ), x, fwt_l[ group[v] ], fwt_r[ group[v] ] )
				else
					fwt_update( ( deg[v] - d ), x, fwt_l[ group[v] ], fwt_r[ group[v] ] );

				if ( ( deg[v] + d + 1 ) <= groupSize[ group[v] ] ) then
					fwt_update( ( deg[v] + d + 1 ), -x, fwt_l[ group[v] ], fwt_r[ group[v] ] );
			end;
		end
		else
		begin
			readln( v );
			if ( v = 1 ) then
				writeln( fwt_read( n, 1, n ) )
			else
				writeln( fwt_read( ( n - deg[v] ), 1, n ) + fwt_read( deg[v], fwt_l[ group[v] ], fwt_r[ group[v] ] ) );
		end;
	end;
end.