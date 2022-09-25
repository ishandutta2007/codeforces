program problem2;

var	n, i, r, ll, rr, cc: longInt;
	a, s, ans: array[ 1..100000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	r := 0;
	for i := n downTo 1 do
	begin
		if ( r = 0 ) or ( a[ s[r] ] >= a[i] ) then
			ans[i] := -1
		else
		begin
			ll := 1;
			rr := r;
			while ( ll < rr ) do
			begin
				cc := ( ll + rr ) div 2;
				if ( a[ s[cc] ] >= a[i] ) then
					ll := cc + 1
				else
					rr := cc;
			end;
			
			ans[i] := s[ll] - i - 1;
		end;
		
		if ( r = 0 ) or ( a[i] < a[ s[r] ] ) then
		begin
			inc( r );
			s[r] := i;
		end;
	end;
	
	for i := 1 to n do
		write( ans[i], ' ' );
	writeln();
end.