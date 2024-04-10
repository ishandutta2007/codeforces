program problem4;

type	tEdge =	record
					v, next: longInt;
				end;
				
var	first, c, l, r, v, qv, qk, qq, qans, cnt, ans: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;
	ee, t: longInt;
	
procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

function isLess( a, b: longInt ): boolean;
var	bucket_a, bucket_b: longInt;
begin
	bucket_a := l[ qv[a] ] div 316;
	bucket_b := l[ qv[b] ] div 316;
	
	if ( bucket_a = bucket_b ) then
		exit( r[ qv[a] ] > r[ qv[b] ] );
		
	exit( bucket_a < bucket_b );
end;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := qq[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( isLess( qq[i], med ) ) do
				inc( i );
			while ( isLess( med, qq[j] ) ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := qq[i];
				qq[i] := qq[j];
				qq[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

procedure DFS( u, p: longInt );
var	i: longInt;
begin
	inc( t );
	v[t] := u;
	l[u] := t;
	
	i := first[u];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, u );
	
		i := e[i].next;
	end;
	
	r[u] := t;
end;

procedure add( v: longInt );
begin
	inc( cnt[ c[v] ] );
	inc( ans[ cnt[ c[v] ] ] );
end;

procedure rem( v: longInt );
begin
	dec( ans[ cnt[ c[v] ] ] );
	dec( cnt[ c[v] ] );
end;

var	n, m, i, a, b: longInt;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( cnt, sizeOf(cnt), 0 );
	fillchar( ans, sizeOf(ans), 0 );
	ee := 0;
	t := 0;
	
	readln( n, m );
	for i := 1 to n do
		read( c[i] );
	
	for i := 2 to n do
	begin
		readln( a, b );
		
		addEdge( a, b );
		addEdge( b, a );
	end;
	
	DFS( 1, 0 );
	
	for i := 1 to m do
	begin
		readln( qv[i], qk[i] );
		qq[i] := i;
	end;
	
	qsort( 1, m );
	
	a := 1;
	b := 0;
	for i := 1 to m do
	begin
		while ( b < r[ qv[ qq[i] ] ] ) do
		begin
			inc( b );
			add( v[b] );
		end;
		
		while ( a > l[ qv[ qq[i] ] ] ) do
		begin
			dec( a );
			add( v[a] );
		end;
		
		while ( b > r[ qv[ qq[i] ] ] ) do
		begin
			dec( b );
			rem( v[b + 1] );
		end;
		
		while ( a < l[ qv[ qq[i] ] ] ) do
		begin
			inc( a );
			rem( v[a - 1] );
		end;
		
		qans[ qq[i] ] := ans[ qk[ qq[i] ] ];
	end;
	
	for i := 1 to m do
		writeln( qans[i] );
end.