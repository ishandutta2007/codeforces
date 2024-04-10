program problem4;
uses math;

type	tArr =	record
					s, p: longInt;
				end;
		tEdge =	record
					v, u, w: longInt;
				end;
				
var	v: array[ 0..1, 1..100000 ] of tArr;
				
procedure qsort( p, l, r: longInt );
var	i, j, med: longInt;
	t: tArr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := v[p][ l + random(r-l+1) ].s;
		while ( i <= j ) do
		begin
			while ( v[p][i].s > med ) do
				inc( i );
			while ( v[p][j].s < med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := v[p][i];
				v[p][i] := v[p][j];
				v[p][j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( p, l, j );
		qsort( p, i, r );
	end;
end;

var	n, m, i, j, c, s, w: longInt;
	cnt, k: array[ 0..1 ] of longInt;
	ans: array[ 1..100000 ] of tEdge;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n );
	for i := 1 to n do
	begin
		readln( c, s );
		inc( cnt[c] );
		v[c][ cnt[c] ].p := i;
		v[c][ cnt[c] ].s := s;
	end;
	
	qsort( 0, 1, cnt[0] );
	qsort( 1, 1, cnt[1] );
	
	k[0] := 1;
	k[1] := 1;
	
	m := 0;
	i := 1;
	while ( v[i][ k[i] ].s > 0 ) or ( v[1-i][ k[1-i] ].s > 0 ) do
	begin
		if ( v[i][ k[i] ].s = 0 ) then
		begin
			inc( m );
			ans[m].v := v[i][ k[i] ].p;
			ans[m].u := v[1-i][ k[1-i] ].p;
			ans[m].w := 0;
			
			inc( k[i] );
			i := 1 - i;
		end;
	
		while ( v[i][ k[i] ].s > 0 ) do
		begin
			w := min( v[i][ k[i] ].s, v[1-i][ k[1-i] ].s );
			inc( m );
			ans[m].v := v[i][ k[i] ].p;
			ans[m].u := v[1-i][ k[1-i] ].p;
			ans[m].w := w;
			
			dec( v[i][ k[i] ].s, w );
			dec( v[1-i][ k[1-i] ].s, w );
			
			inc( k[1-i] );
		end;
		
		inc( k[i] );
		dec( k[1-i] );
		
		i := 1 - i;
	end;
	inc( k[i] );
	
	for i := 0 to 1 do
		while ( k[i] <= cnt[i] ) do
		begin
			inc( m );
			ans[m].v := v[i][ k[i] ].p;
			ans[m].u := v[1-i][1].p;
			ans[m].w := 0;
			
			inc( k[i] );
		end;
		
	for i := 1 to m do
		writeln( ans[i].v, ' ', ans[i].u, ' ', ans[i].w );
end.