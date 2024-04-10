program problem5;
uses math;

type	tEdge =	record
					v, next: longInt;
				end;
		tSegmentTreeRec =	record
								l, r, lSon, rSon, sum: longInt;
							end;
		tAttack =	record
						time, vertex: longInt;
					end;
		tQuery =	record
						u, v, k, l, r, id: longInt;
					end;

var	first, p, component, id, sz, compSize, head, vertex, firstCompVertex, compTreeRoot, level, val, LCA_first: array[ 0..100000 ] of longInt;
	LCA_array, max2pow: array[ 1..300000 ] of longInt;
	LCA_RMQ: array[ 1..300000, 0..20 ] of longInt;
	e: array[ 1..100000 ] of tEdge;
	t: array[ 1..300000 ] of tSegmentTreeRec;
	attacks: array[ 0..100000 ] of tAttack;
	queries: array[ 1..100000 ] of tQuery;
	k, w, tw, attackCnt, queryCnt, sqrtN, LCAw: longInt;
	
procedure LCA_init( v: longInt );
var	i: longInt;
begin
	inc( LCAw );
	LCA_array[LCAw] := v;
	LCA_first[v] := LCAw;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		LCA_init( e[i].v );
		
		inc( LCAw );
		LCA_array[LCAw] := v;
		
		i := e[i].next;
	end;
end;

function minVertex( u, v: longInt ): longInt;
begin
	if ( level[u] < level[v] ) then
		exit( u )
	else
		exit( v );
end;

procedure LCA_RMQ_init();
var	i, p: longInt;
begin
	for i := LCAw downTo 1 do
	begin
		LCA_RMQ[i][0] := LCA_array[i];
		
		p := 0;
		while ( i + ( 1 shl (p+1) ) - 1 <= LCAw ) do
		begin
			LCA_RMQ[i][p+1] := minVertex( LCA_RMQ[i][p], LCA_RMQ[ i + (1 shl p) ][p] );
			
			inc( p );
		end;
	end;
	
	p := 1;
	for i := 1 to LCAw do
	begin
		if ( (1 shl p) = i ) then
			inc( p );
			
		max2pow[i] := p - 1;
	end;
end;
	
function new( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );

	res := tw;
	t[res].l := l;
	t[res].r := r;
	t[res].sum := r - l + 1;
	if ( l = r ) then
	begin
		t[res].lSon := 0;
		t[res].rSon := 0;
	end
	else
	begin
		t[res].lSon := new( l, (l+r) div 2 );
		t[res].rSon := new( (l+r) div 2 + 1, r );
	end;
	
	exit( res );
end;

function segmentTreeRead( s: longInt; const l, r: longInt; k: longInt; var sum: longInt ): longInt;
var	res, ssum: longInt;
begin
	if ( t[s].l = t[s].r ) then
	begin
		sum := t[s].sum;
		exit( t[s].l );
	end;

	if ( t[s].l >= l ) and ( t[s].r <= r ) then
	begin
		sum := k;
		
		if ( t[s].sum < k ) then
		begin
			sum := t[s].sum;
			res := 1;
		end
		else if ( t[ t[s].lSon ].sum >= k ) then
			res := segmentTreeRead( t[s].lSon, l, r, k, ssum )
		else
			res := segmentTreeRead( t[s].rSon, l, r, k - t[ t[s].lSon ].sum, ssum );

		exit( res );
	end;
	
	res := 1;
	sum := 0;
	if ( t[ t[s].lSon ].r >= l ) then
	begin
		res := segmentTreeRead( t[s].lSon, l, r, k, sum );
		
		dec( k, sum );
		if ( k = 0 ) then
			exit( res );
	end;
	
	if ( t[ t[s].rSon ].l <= r ) then
	begin
		res := segmentTreeRead( t[s].rSon, l, r, k, ssum );
			
		inc( sum, ssum );
	end;

	exit( res );
end;

procedure segmentTreeUpdate( s, x, d: longInt );
begin
	inc( t[s].sum, d );

	while ( t[s].l <> t[s].r ) do
	begin
		if ( t[ t[s].lSon ].r >= x ) then
			s := t[s].lSon
		else
			s := t[s].rSon;
			
		inc( t[s].sum, d );		
	end;
end;

procedure doAttack( v: longInt );
begin
	segmentTreeUpdate( compTreeRoot[ component[v] ], id[v], -1 );
	val[v] := 0;
end;

procedure undoAttack( v: longInt );
begin
	segmentTreeUpdate( compTreeRoot[ component[v] ], id[v], +1 );
	val[v] := 1;
end;

function lca( u, v: longInt ): longInt;
var	l, r, p: longInt;
begin
	l := min( LCA_first[u], LCA_first[v] );
	r := max( LCA_first[u], LCA_first[v] );
	
	p := max2pow[ r - l + 1 ];
	
	exit( minVertex( LCA_RMQ[l][p], LCA_RMQ[ r - (1 shl p) + 1 ][p] ) );
end;

function pathSum( v, u: longInt ): longInt;
var	res, s: longInt;
begin
	res := 0;
	while ( component[u] <> component[v] ) do
	begin
		segmentTreeRead( compTreeRoot[ component[v] ], id[v], compSize[ component[v] ], 1000000, s );
		inc( res, s );

		v := p[ head[ component[v] ] ];		
	end;	
	
	segmentTreeRead( compTreeRoot[ component[v] ], id[v], id[u], 1000000, s );

	exit( res + s );
end;

function find( v, k: longInt ): longInt;
var	cnt, res: longInt;
begin
	while ( k > 0 ) do
	begin
		res := vertex[ firstCompVertex[ component[v] ] + segmentTreeRead( compTreeRoot[ component[v] ], id[v], compSize[ component[v] ], k, cnt ) - 1 ];
		dec( k, cnt );
		v := p[ head[ component[v] ] ];
	end;
	
	exit( res );
end;

function findKthOnPath( u, v, k: longInt ): longInt;
var	lcaV, cntU, cntV: longInt;
begin
	inc( k, val[u] );
	
	lcav := lca( u, v );
	
	cntU := pathSum( u, lcav );
	cntV := pathSum( v, lcav );
	
	if ( cntU + cntV - val[lcav] - val[v] < k ) then
		exit( -1 );
		
	if ( cntU >= k ) then
		exit( find( u, k ) )
	else
		exit( find( v, cntU + cntV - k + 1 - val[lcav] ) );
end;

function calcSubtreeSize( const v: longInt; l: longInt ): longInt;
var	i: longInt;
begin
	val[v] := 1;	
	sz[v] := 1;
	level[v] := l;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		inc( sz[v], calcSubtreeSize( e[i].v, l + 1 ) );
	
		i := e[i].next;
	end;
	
	exit( sz[v] );
end;

procedure heavyLightDecomposition( const v: longInt; heavy: boolean );
var	i: longInt;
	wasHeavy: boolean;
begin
	if ( heavy ) then
	begin
		component[v] := component[ p[v] ];
		inc( compSize[ component[v] ] );
	end
	else
	begin
		inc( k );
		component[v] := k;
		compSize[ component[v] ] := 1;
		head[ component[v] ] := v;
	end;
	id[v] := compSize[ component[v] ];
	
	wasHeavy := false;
	i := first[v];
	while ( i > 0 ) do
	begin
		heavy := 2 * sz[ e[i].v ] >= sz[v];
		heavyLightDecomposition( e[i].v, heavy );
		wasHeavy := wasHeavy or heavy;
		
		i := e[i].next;
	end;
	
	if ( not wasHeavy ) then
	begin
		firstCompVertex[ component[v] ] := w + 1;
		
		i := v;
		while ( i > 0 ) and ( component[i] = component[v] ) do
		begin
			id[i] := compSize[ component[i] ] - id[i] + 1;
			
			inc( w );
			vertex[w] := i;
			
			i := p[i];
		end;
		
		compTreeRoot[ component[v] ] := new( 1, compSize[ component[v] ] );
	end;
end;

function findAttack( time: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := attackCnt;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( attacks[c].time < time ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

function cmp( const a, b: tQuery ): boolean;
begin
	if ( a.l div sqrtN <> b.l div sqrtN ) then
		exit( a.l div sqrtN < b.l div sqrtN )
	else if ( odd( a.l div sqrtN ) ) then
		exit( a.r > b.r )
	else
		exit( a.r < b.r );
end;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	tmp, med: tQuery;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := queries[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( cmp( queries[i], med ) ) do
				inc( i );
			while ( cmp( med, queries[j] ) ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp := queries[i];
				queries[i] := queries[j];
				queries[j] := tmp;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;
	
var	n, m, i, s, l, r: longInt;
	ans: array[ 1..100000 ] of longInt;

begin
	fillchar( first, sizeOf(first), 0 );
	attackCnt := 0;
	queryCnt := 0;
	level[0] := -1;

	readln( n );
	for i := 1 to n do
	begin
		read( p[i] );
		if ( p[i] = 0 ) then
			s := i
		else
		begin
			e[i].v := i;
			e[i].next := first[ p[i] ];
			first[ p[i] ] := i;
		end;
	end;
	
	calcSubtreeSize( s, 0 );
	heavyLightDecomposition( s, false );
	LCA_init( s );
	LCA_RMQ_init();
	
	readln( m );
	for i := 1 to m do
	begin
		read( s );
		if ( s = 1 ) then
		begin
			inc( attackCnt );
			attacks[attackCnt].time := i;
			readln( attacks[attackCnt].vertex );
		end
		else
		begin
			inc( queryCnt );
			queries[queryCnt].id := queryCnt;
			readln( queries[queryCnt].u, queries[queryCnt].v, queries[queryCnt].k, s );
			if ( attackCnt <> 0 ) and ( attacks[attackCnt].time > s ) then
			begin
				queries[queryCnt].l := findAttack( s + 1 );
				queries[queryCnt].r := attackCnt;
			end;
		end;
	end;
	
	sqrtN := trunc( sqrt( attackCnt ) + 1 );
	qsort( 1, queryCnt );

	l := 0;
	r := 0;
	for i := 1 to queryCnt do
	begin
		while ( l > queries[i].l ) do
		begin
			dec( l );
			
			if ( l > 0 ) and ( l <= attackCnt ) then
				doAttack( attacks[l].vertex );
		end;
		
		while ( r < queries[i].r ) do
		begin
			inc( r );
			
			if ( r > 0 ) and ( r <= attackCnt ) then
				doAttack( attacks[r].vertex );
		end;
		
		while ( l < queries[i].l ) do
		begin
			if ( l > 0 ) and ( l <= attackCnt ) then
				undoAttack( attacks[l].vertex );
	
			inc( l );
		end;
		
		while ( r > queries[i].r ) do
		begin
			if ( r > 0 ) and ( r <= attackCnt ) then
				undoAttack( attacks[r].vertex );
	
			dec( r );
		end;
		
		ans[ queries[i].id ] := findKthOnPath( queries[i].u, queries[i].v, queries[i].k );
	end;
	
	for i := 1 to queryCnt do
		writeln( ans[i] );
end.