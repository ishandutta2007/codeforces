program problem2;

var	x, y: array[ 1..64 ] of longInt;
	ddd: array[ 1..64, 1..64 ] of extended;

function dd( p, q: longInt ): extended;
begin
	exit( sqrt( sqr( x[p] - x[q] ) + sqr( y[p] - y[q] ) ) );
end;

function f( a, b, c, d: longInt ): extended;
begin
	exit( ddd[a, b] + ddd[b, c] + ddd[c, d] );
end;

var	n, m, k, i, j, a1, a2, a3, a4, p1, p2, p3, p4: longInt;

begin
	readln( n, m );
	
	k := 0;
	for i := 0 to n do
		for j := 0 to m do
			if ( ( i < 4 ) or ( i > n - 4 ) ) and ( ( j < 4 ) or ( j > m - 4 ) ) then
			begin
				inc( k );
				x[k] := i;
				y[k] := j;
			end;
			
	for i := 1 to k do
		for j := 1 to k do
			ddd[i][j] := dd( i, j );
	
	p1 := 1;
	p2 := 2;
	p3 := 3;
	p4 := 4;
	for a1 := 1 to k do
		for a2 := 1 to k do
			if ( a2 <> a1 ) then
				for a3 := 1 to k do
					if ( a3 <> a1 ) and ( a3 <> a2 ) then
						for a4 := 1 to k do
							if ( a4 <> a1 ) and ( a4 <> a2 ) and ( a4 <> a3 ) and ( f(a1, a2, a3, a4) > f(p1, p2, p3, p4) ) then
							begin
								p1 := a1;
								p2 := a2;
								p3 := a3;
								p4 := a4;
							end;
	
	writeln( x[p1], ' ', y[p1] );
	writeln( x[p2], ' ', y[p2] );
	writeln( x[p3], ' ', y[p3] );
	writeln( x[p4], ' ', y[p4] );
end.