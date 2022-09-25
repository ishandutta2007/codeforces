program problem4;

const	SZ = 225;

type	tQuery =	record
						u, v, id: longInt;
					end;
		tEdge =	record
					v, next: longInt;
				end;

var	p: array[ 1..500, 1..100000 ] of longInt;
	first, ans, fq, lq, vis: array[ 1..100000 ] of longInt;
	query: array[ 1..100000 ] of tQuery;
	e: array[ 1..200000 ] of tEdge;
	q, ee: longInt;
	
function dsu_get( id, v: longInt ): longInt;
begin
	if ( p[id][v] <> v ) then
		p[id][v] := dsu_get( id, p[id][v] );
	
	exit( p[id][v] );
end;

procedure dsu_merge( id, u, v: longInt );
begin
	p[id][ dsu_get( id, u ) ] := dsu_get( id, v );
end;

procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure dfs( start, v, time: longInt );
var	i, x: longInt;
begin
	if ( vis[v] = time ) then
		exit();
	
	if ( fq[v] > 0 ) then
	begin
		x := fq[v];
		for i := 16 downto 0 do
			if ( x + (1 shl i) <= lq[v] ) and ( query[ x + (1 shl i) ].v <= start ) then
				inc( x, 1 shl i );
		
		if ( query[x].v = start ) then
			inc( ans[ query[x].id ] );
	end;
	
	vis[v] := time;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		dfs( start, e[i].v, time );
	
		i := e[i].next;
	end;
end;

function less( const a, b: tQuery ): boolean;
begin
	if ( a.u = b.u ) then
		exit( a.v < b.v )
	else
		exit( a.u < b.u );
end;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tQuery;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := query[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( less( query[i], med ) ) do
				inc( i );
			while ( less( med, query[j] ) ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := query[i];
				query[i] := query[j];
				query[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, m, i, j, heavyCnt, iter: longInt;
	u, v, c, cnt, heavyId, lastUsed, firstEdge, nextEdge: array[ 1..100000 ] of longInt;

begin
	fillchar( cnt, sizeOf(cnt), 0 );
	fillchar( vis, sizeOf(vis), 0 );
	fillchar( first, sizeOf(first), 0 );
	fillchar( lastUsed, sizeOf(lastUsed), 0 );
	fillchar( firstEdge, sizeOf(firstEdge), 0 );

	readln( n, m );
	for i := 1 to m do
	begin
		readln( u[i], v[i], c[i] );
	
		inc( cnt[ c[i] ] );
	
		nextEdge[i] := firstEdge[ c[i] ];
		firstEdge[ c[i] ] := i;
	end;
	
	readln( q );
	for i := 1 to q do
	begin
		readln( query[i].u, query[i].v );
		query[i].id := i;
	end;
	
	qsort( 1, q );
	
	for i := 1 to q do
	begin
		if ( i = 1 ) or ( query[i - 1].u <> query[i].u ) then
			fq[ query[i].u ] := i;
		
		if ( i = q ) or ( query[i + 1].u <> query[i].u ) then
			lq[ query[i].u ] := i;
	end;
		
	heavyCnt := 0;
	for i := 1 to m do
		if ( cnt[i] > SZ ) then
		begin
			inc( heavyCnt );
			heavyId[i] := heavyCnt;
		end;
	
	for i := 1 to heavyCnt do
		for j := 1 to n do
			p[i][j] := j;
	
	iter := 0;
	for i := 1 to m do
		if ( cnt[ c[i] ] > SZ ) then
			dsu_merge( heavyId[ c[i] ], u[i], v[i] )
		else
		begin
			ee := 0;
			
			j := firstEdge[i];
			while ( j > 0 ) do
			begin
				addEdge( u[j], v[j] );
				addEdge( v[j], u[j] );
			
				j := nextEdge[j];
			end;
			
			j := firstEdge[i];
			while ( j > 0 ) do
			begin
				if ( lastUsed[ u[j] ] <> i ) then
				begin
					inc( iter );
					
					dfs( u[j], u[j], iter );
					
					lastUsed[ u[j] ] := i;
				end;
			
				if ( lastUsed[ v[j] ] <> i ) then
				begin
					inc( iter );
					
					dfs( v[j], v[j], iter );
					
					lastUsed[ v[j] ] := i;
				end;
			
				j := nextEdge[j];
			end;
			
			j := firstEdge[i];
			while ( j > 0 ) do
			begin
				first[ u[j] ] := 0;
				first[ v[j] ] := 0;
			
				j := nextEdge[j];
			end;
		end;
	
	for i := q - 1 downto 1 do
		if ( query[i].u = query[i + 1].u ) and ( query[i].v = query[i + 1].v ) then
			ans[ query[i].id ] := ans[ query[i + 1].id ];
	
	for i := 1 to q do
		for j := 1 to heavyCnt do
			if ( dsu_get( j, query[i].u ) = dsu_get( j, query[i].v ) ) then
				inc( ans[ query[i].id ] );
	
	for i := 1 to q do
		writeln( ans[i] );
end.