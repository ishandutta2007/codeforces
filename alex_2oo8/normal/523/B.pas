program problem2;

var	n, t, i, p: longInt;
	a: array[ 0..200000 ] of longInt;
	ans, real, approx: array[ 0..200000 ] of extended;
	sum: int64;
	c: extended;

begin
	readln( n, t, c );
	
	approx[0] := 0.0;
	sum := 0;
	for i := 1 to n do
	begin
		read( a[i] );
		
		inc( sum, a[i] );
		if ( i > t ) then
			dec( sum, a[i - t] );
		
		real[i] := sum / t;
		approx[i] := ( approx[i - 1] + a[i] / t ) / c;
		
		ans[i] := abs( real[i] - approx[i] ) / real[i];
	end;
	
	readln( n );
	for i := 1 to n do
	begin
		read( p );
		
		writeln( real[p]:0:12, ' ', approx[p]:0:12, ' ', ans[p]:0:12 );
	end;
	
	writeln();
end.