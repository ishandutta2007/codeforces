program problem5;
uses math, dos;

type	tEdge =	record
					v, next: longInt;
				end;
		tTree =	record
					n, timer: longInt;
					first, size, depth, inTime, vertex: array[ 1..200000 ] of longInt;
					LCA_RMQ: array[ 1..200000, 0..20 ] of longInt;
					s, sumDown, sumUp: array[ 1..100000 ] of int64;
					e: array[ 1..200000 ] of tEdge;
					insideDistanceSum, maxS: int64;
				end;
				
var	max2pow: array[ 1..200000 ] of longInt;

procedure qsort( var t: tTree; l, r: longInt );
var	i, j, tmp: longInt;
	med: int64;
begin
	if ( l < r ) then
	begin
		with t do
		begin
			i := l;
			j := r;
			med := s[ vertex[ l + random(r - l + 1) ] ];
			while ( i <= j ) do
			begin
				while ( s[ vertex[i] ] > med ) do
					inc( i );
				while ( s[ vertex[j] ] < med ) do
					dec( j );
				
				if ( i <= j ) then
				begin
					tmp := vertex[i];
					vertex[i] := vertex[j];
					vertex[j] := tmp;
					
					inc( i );
					dec( j );
				end;
			end;
			
			qsort( t, l, j );
			qsort( t, i, r );
		end;
	end;
end;
				
procedure readEdges( var t: tTree );
var	i, ee, u, v: longInt;
begin
	with t do
	begin
		fillchar( first, sizeOf(first), 0 );
		
		ee := 0;
		for i := 2 to n do
		begin
			readln( u, v );
			
			inc( ee );
			e[ee].v := v;
			e[ee].next := first[u];
			first[u] := ee;
			
			inc( ee );
			e[ee].v := u;
			e[ee].next := first[v];
			first[v] := ee;
		end;
	end;
end;

procedure DFS( var t: tTree; v, p: longInt );
var	i: longInt;
begin
	with t do
	begin
		size[v] := 1;
		sumDown[v] := 0;
		
		i := first[v];
		while ( i > 0 ) do
		begin
			if ( e[i].v <> p ) then
			begin
				DFS( t, e[i].v, v );
				
				inc( size[v], size[ e[i].v ] );
				inc( sumDown[v], sumDown[ e[i].v ] + size[ e[i].v ] );
			end;
		
			i := e[i].next;
		end;
	end;
end;

procedure DFS2( var t: tTree; v, p: longInt );
var	i: longInt;
begin
	with t do
	begin
		inc( timer );
		vertex[timer] := v;
		inTime[v] := timer;
	
		if ( p = 0 ) then
		begin
			sumUp[v] := 0;
			depth[v] := 0;
		end
		else
		begin
			sumUp[v] := n - size[v] + sumUp[p] + sumDown[p] - sumDown[v] - size[v];
			depth[v] := depth[p] + 1;
		end;
			
		i := first[v];
		while ( i > 0 ) do
		begin
			if ( e[i].v <> p ) then
			begin
				DFS2( t, e[i].v, v );
				
				inc( timer );
				vertex[timer] := v;
			end;
		
			i := e[i].next;
		end;
	end;
end;

function minVertex( const t: tTree; u, v: longInt ): longInt;
begin
	if ( t.depth[u] < t.depth[v] ) then
		exit( u )
	else
		exit( v );
end;

procedure initLCA( var t: tTree );
var	i, j: longInt;
begin
	with t do
	begin
		max2pow[1] := 0;
		for i := 2 to timer do
		begin
			max2pow[i] := max2pow[i - 1];
			if ( i = 2 shl max2pow[i] ) then
				inc( max2pow[i] );
		end;
		
		for i := 1 to timer do
			LCA_RMQ[i][0] := vertex[i];
		
		for j := 0 to 19 do
			for i := 1 to timer - (2 shl j) + 1 do
				LCA_RMQ[i][j + 1] := minVertex( t, LCA_RMQ[i][j], LCA_RMQ[ i + (1 shl j) ][j] );
	end;
end;

function LCA( const t: tTree; u, v: longInt ): longInt;
var	p, l, r: longInt;
begin
	with t do
	begin
		l := min( inTime[u], inTime[v] );
		r := max( inTime[u], inTime[v] );

		p := max2pow[r - l + 1];
		
		p := minVertex( t, LCA_RMQ[l][p], LCA_RMQ[ r - (1 shl p) + 1 ][p] );
	end;
	
	exit( p );
end;

function distance( const t: tTree; u, v: longInt ): longInt;
var	w: longInt;
begin
	w := LCA( t, u, v );
	
	exit( t.depth[u] + t.depth[v] - 2 * t.depth[w] );
end;

procedure preprocess( var t: tTree );
var	i: longInt;
begin
	t.timer := 0;

	DFS( t, 1, 0 );
	DFS2( t, 1, 0 );
	
	initLCA( t );
	
	with t do
	begin
		insideDistanceSum := 0;
		maxS := 0;
		
		for i := 1 to n do
		begin
			s[i] := sumDown[i] + sumUp[i];
			
			inc( insideDistanceSum, s[i] );
			maxS := max( maxS, s[i] );
		end;
		
		insideDistanceSum := insideDistanceSum div 2;
	end;
end;

function solveOne( const t: tTree; nn: longInt ): int64;
begin
	exit( t.maxS * nn + t.insideDistanceSum );
end;

function solveTwo( var t: tTree; n1, n2: longInt ): int64;
var	i, j: longInt;
	res, nn, endTime: int64;
begin
	endTime := getMsCount() + 850;

	if ( n1 < n2 ) then
	begin
		i := n1;
		n1 := n2;
		n2 := i;
	end;
	
	nn := n1 * int64(n2);

	with t do
	begin
		res := 0;
		
		for i := 1 to n do
			vertex[i] := i;
		
		qsort( t, 1, n );
		
		i := 1;
		while ( i <= n ) and ( getMsCount() < endTime ) do
		begin
			for j := 1 to n do
				res := max( res, nn * distance(t, vertex[i], vertex[j]) + s[ vertex[i] ] * n1 + s[ vertex[j] ] * n2 );
			
			inc( i );
		end;
	end;
	
	exit( res + t.insideDistanceSum + t.n * int64(n1 + n2) + 2 * nn );
end;

var	t1, t2, t3: tTree;
	ans: int64;

begin
	readln( t1.n, t2.n, t3.n );

	readEdges( t1 );
	readEdges( t2 );
	readEdges( t3 );
	
	preprocess( t1 );
	preprocess( t2 );
	preprocess( t3 );
	
	ans := 0;
	
	ans := max( ans, solveTwo( t1, t2.n, t3.n ) + solveOne( t2, t1.n + t3.n ) + solveOne( t3, t1.n + t2.n ) );
	ans := max( ans, solveTwo( t2, t1.n, t3.n ) + solveOne( t1, t2.n + t3.n ) + solveOne( t3, t1.n + t2.n ) );
	ans := max( ans, solveTwo( t3, t2.n, t1.n ) + solveOne( t2, t1.n + t3.n ) + solveOne( t1, t3.n + t2.n ) );
	
	writeln( ans );
end.