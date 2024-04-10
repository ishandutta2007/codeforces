program problem4;

type	tEdge =	record
					v, next, row: longInt;
				end;
		tRec =	record
					x, i: longInt;
				end;

var	first, p, t, prev: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	arr: array[ 1..100000 ] of tRec;
	n, m, k: longInt;
	
procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tRec;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := arr[ l + random(r-l+1) ].x;
		while ( i <= j ) do
		begin
			while ( arr[i].x < med ) do
				inc( i );
			while ( arr[j].x > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := arr[i];
				arr[i] := arr[j];
				arr[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;
	
procedure DFS( v, row: longInt );
var	i: longInt;
begin
	if ( t[v] = 1 ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	if ( row > 0 ) and ( prev[ (row-1) * m + v ] > 0 ) then
	begin
		DFS( prev[ (row-1) * m + v ], row );
		prev[ (row-1) * m + v ] := 0;
	end;
	
	if ( t[v] = 2 ) then
		exit();

	t[v] := 1;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		DFS( e[i].v, e[i].row );
		
		i := e[i].next;
	end;
	
	t[v] := 2;

	inc( k );
	p[k] := v;
end;

var	i, j, l, ee: longInt;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( prev, sizeOf(prev), 0 );
	fillchar( t, sizeOf(t), 0 );
	ee := 0;

	readln( n, m );
	for i := 1 to n do
	begin
		for j := 1 to m do
		begin
			arr[j].i := j;
			read( arr[j].x );
		end;
		readln();
		
		qsort( 1, m );
		
		l := 1;
		while ( l <= m ) and ( arr[l].x = -1 ) do
			inc( l );

		for j := (l+1) to m do
		begin
			if ( arr[j-1].x = arr[j].x ) then
				prev[ (i-1) * m + arr[j].i ] := arr[j-1].i;
				
			if ( l > 1 ) and ( arr[l-1].x <> -1 ) and ( arr[l].x = arr[j].x ) then
				dec( l );
			
			while ( arr[l].x < arr[j].x ) do
			begin
				inc( ee );
				e[ee].row := i;
				e[ee].v := arr[l].i;
				e[ee].next := first[ arr[j].i ];
				first[ arr[j].i ] := ee;
				
				inc( l );
			end;
		end;
	end;
	
	k := 0;
	for i := 1 to m do
		if ( t[i] = 0 ) then
			DFS( i, 0 );
			
	for i := 1 to m do
		write( p[i], ' ' );
	writeln();
end.