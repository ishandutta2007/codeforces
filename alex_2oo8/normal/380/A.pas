program problemA;
uses math;

var	n, m, c, i, j: longInt;
	prefixSum: array[ 0..100000 ] of int64;
	t, x, l, ans: array[ 1..100000 ] of longInt;
	p: int64;

begin
	readln( m );
	prefixSum[0] := 0;
	for i := 1 to m do
	begin
		read( t[i] );
		if ( t[i] = 1 ) then
		begin
			readln( x[i] );
			prefixSum[i] := prefixSum[i - 1] + 1;
		end
		else
		begin
			readln( l[i], c );
			
			prefixSum[i] := prefixSum[i - 1] + int64(c) * l[i];
		end;
	end;
	
	j := 1;
	for i := 1 to min( 100000, prefixSum[m] ) do
	begin
		if ( prefixSum[j] < i ) then
			inc( j );
			
		if ( t[j] = 1 ) then
			ans[i] := x[j]
		else
			ans[i] := ans[ (i - prefixSum[j - 1] - 1) mod l[j] + 1 ];
	end;

	j := 1;
	readln( n );
	for i := 1 to n do
	begin
		read( p );
		while ( prefixSum[j] < p ) do
			inc( j );
			
		if ( t[j] = 1 ) then
			write( x[j] )
		else
			write( ans[ (p - prefixSum[j - 1] - 1) mod l[j] + 1 ] );
		write( ' ' );
	end;
	writeln();
end.