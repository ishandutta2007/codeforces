program problem1;

var	n, i, j, k, t, x, d, b: longInt;
	sum: int64;
	a: array[ 1..300000 ] of longInt;

begin
	k := 1;
	sum := 0;
	a[1] := 0;
	readln( n );
	for i := 1 to n do
	begin
		read( t );
		if ( t = 1 ) then
		begin
			readln( b, d );
			inc( a[b], d );
			inc( sum, ( b * d ) );
		end
		else if ( t = 2 ) then
		begin
			readln( x );
			inc( k );
			dec( a[k-1], x );
			a[k] := x;
			inc( sum, x );
		end
		else
		begin
			inc( a[k-1], a[k] );
			dec( sum, a[k] );
			dec( k );
		end;
		
		writeln( ( sum / k ):0:15 );
	end;
end.