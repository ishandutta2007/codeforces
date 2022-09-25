program problem3;
uses math;

function f( l, r, h: int64 ): int64;
begin
	if ( h <= l ) then
		exit( r - h )
	else if ( h >= r ) then
		exit( h - l )
	else
		exit( r - l + min( h - l, r - h ) );
end;

var	n, m, i, ll, rr: longInt;
	h, p: array[ 1..100000 ] of int64;
	l, r, c: int64;

begin
	readln( n, m );
	for i := 1 to n do
		read( h[i] );
		
	for i := 1 to m do
		read( p[i] );
		
	l := 0;
	r := 20000000000;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
	
		ll := 1;
		for i := 1 to n do
		begin
			rr := ll - 1;
			while ( rr < m ) and ( f( p[ll], p[rr+1], h[i] ) <= c ) do
				inc( rr );
				
			ll := rr + 1;
		end;
		
		if ( ll > m ) then
			r := c
		else
			l := c + 1;
	end;
	
	writeln( l );
end.