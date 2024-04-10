program problem6;
uses math;

var	a, ans: array[ 1..200000 ] of int64;
	n, i, j, k, l, r, ll, rr, ai, SMALL: longInt;

begin
	fillchar( ans, sizeOf(ans), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	SMALL := min( n - 1, 500 );
	for i := 1 to SMALL do
		for j := 2 to n do
			if ( a[j] < a[ (j + i - 2) div i ] ) then
				inc( ans[i] );
	
	for i := 1 to SMALL do
	begin
		ai := a[i];
		l := (SMALL + 1) * (i - 1) + 2;
		r := l - 1;
		k := 0;
		for j := SMALL + 1 to n - 1 do
		begin
			ll := j * (i - 1) + 2;
			rr := min( ll + j - 1, n );
			if ( ll > n ) then
				break;
			
			while ( r < rr ) do
			begin
				inc( r );
				if ( a[r] < ai ) then
					inc( k );
			end;
			
			while ( l < ll ) do
			begin
				if ( a[l] < ai ) then
					dec( k );
				
				inc( l );
			end;
			
			inc( ans[j], k );
		end;
	end;
	
	for i := 1 to n - 1 do
		write( ans[i], ' ' );
	
	writeln();
end.