program problem1;

var	n, k, i: longInt;
	d: array[ 1..200000 ] of int64;
	a: array[ 1..200000 ] of longInt;
	delta, cnt: int64;

begin
	readln( n, k );
	for i := 1 to n do
		read( a[i] );
	
	d[1] := 0;
	for i := 2 to n do
		d[i] := d[i-1] + ( int64(i-2) * a[i-1] );
		
	delta := 0;
	cnt := 0;
	for i := 2 to n do
	begin
		d[i] := d[i] - delta - ( (i-cnt-1) * int64(n-i) * a[i] );
		
		inc( delta, cnt * a[i] );
		if ( d[i] < k ) then
		begin
			writeln( i );
			
			inc( delta, int64(i-1-cnt) * a[i] );
			inc( cnt, 1 );
		end;
	end;
end.