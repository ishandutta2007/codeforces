program problem2;
uses math;

var	n, i, j, k, p, s, k1, k2: longInt;
	l, r: array[ 0..51, -50..50, 0..50 ] of int64;
	a: array[ 1..50 ] of longInt;
	ans: extended;
	f: array[ 0..50 ] of extended;

begin
	f[0] := 1.0;
	for i := 1 to 50 do
		f[i] := f[i-1] * i;

	s := 0;
	readln( n );
	for i := 1 to n do
	begin
		read( a[i] );
		inc( s, a[i] );
	end;
	readln( p );
	
	if ( s <= p ) then
	begin
		writeln( n );
		halt;
	end;
	
	l[0][0][0] := 1;
	for i := 1 to n do
		for j := 0 to p do
			for k := 0 to i do
				l[i][j][k] := l[i-1][j][k] + l[i-1][ j - a[i] ][k-1];
				
	r[n+1][0][0] := 1;
	for i := n downTo 1 do
		for j := 0 to p do
			for k := 0 to (n-i+1) do
				r[i][j][k] := r[i+1][j][k] + r[i+1][ j - a[i] ][k-1];
				
	ans := 0.0;
	for i := 1 to n do
	begin
		for s := max( ( p - a[i] + 1 ), 0 ) to p do
			for j := 0 to s do
				for k1 := 0 to (i-1) do
					for k2 := 0 to (n-i) do
					begin
						ans := ans + ( (k1+k2) * l[i-1][j][k1] * f[k1+k2] * f[n-1-k1-k2] * r[i+1][s-j][k2] );
//						writeln( i, ' ', s, ' ', j, ' ', k1, ' ', k2, ' ', ( l[i-1][j][k1] * f[k1] * f[i-1-k1] * r[i+1][s-j][k2] * f[k2] * f[n-i-k2] ):0:0 );
					end;
//		readln();
	end;
	
	ans := ans / f[n];

	writeln( ans:0:15 );
end.