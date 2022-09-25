program problem5;

const	md =	1000000000;

var	n, m, i, j, t, v, x, l, r, ans: longInt;
	a, f: array[ 0..200000 ] of longInt;

begin
	f[0] := 1;
	f[1] := 1;
	for i := 2 to 200000 do
		f[i] := ( f[i-1] + f[i-2] ) mod md;

	readln( n, m );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to m do
	begin
		read( t );
		if ( t = 1 ) then
		begin
			readln( x, v );
			
			a[x] := v;
		end
		else
		begin
			readln( l, r );
			
			ans := 0;
			for j := 0 to r - l do
				ans := ( ans + ( int64( a[l+j] ) * f[j] ) ) mod md;
				
			writeln( ans );
		end;
	end;
end.