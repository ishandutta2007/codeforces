program problem4;

type tArr = array[0..1] of longInt;

var	e: array[ 0..200000 ] of tArr;

procedure qsort( l, r: longInt );
var i, j: longInt;
	t, med: tArr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := e[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( e[i][0] < med[0] ) or ( ( e[i][0] = med[0] ) and ( e[i][1] < med[1] ) ) do	
				inc( i );
			while ( e[j][0] > med[0] ) or ( ( e[j][0] = med[0] ) and ( e[j][1] > med[1] ) ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := e[i];
				e[i] := e[j];
				e[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var n, m, i, j, u, v, ans: longInt;
	c: array[ 1..100000 ] of longInt;
	k: array[ 1..100000 ] of longInt;

begin
	fillchar( k, sizeOf(k), 0 );

	readln( n, m );
	for i := 1 to n do
		read( c[i] );
	readln();
		
	for i := 1 to m do
	begin
		readln( u, v );
		e[i][0] := c[u];
		e[i][1] := c[v];
		
		e[i+m][0] := c[v];
		e[i+m][1] := c[u];
	end;
	
	qsort( 1, (2*m) );
	
	e[0][1] := 0;
	for i := 1 to (2*m) do
		if ( e[i][0] <> e[i][1] ) and ( ( e[i][1] <> e[i-1][1] ) or ( e[i][0] <> e[i-1][0] ) ) then
			inc( k[ e[i][0] ] );
			
	ans := 1;
	for i := 1 to 100000 do
		if ( k[i] > k[ans] ) then
			ans := i;
			
	if ( k[ans] = 0 ) then
	begin
		ans := c[1];
		for i := 1 to n do
			if ( c[i] < ans ) then
				ans := c[i];
	end;
	
	writeln( ans );
end.