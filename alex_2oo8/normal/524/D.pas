program problem4;
uses math;

var	n, m, t, i, mx, l, cnt, online: longInt;
	a, ans, last: array[ 1..100000 ] of longInt;
	s: ansistring;

begin
	readln( n, m, t );
	for i := 1 to n do
	begin
		readln( s );
		
		a[i] := ord( s[8] ) - ord( '0' ) + 10 * ( ord( s[7] ) - ord( '0' ) );
		inc( a[i], 60 * ( ord( s[5] ) - ord( '0' ) + 10 * ( ord( s[4] ) - ord( '0' ) ) ) );
		inc( a[i], 60 * 60 * ( ord( s[2] ) - ord( '0' ) + 10 * ( ord( s[1] ) - ord( '0' ) ) ) );
	end;
	
	ans[1] := 1;
	last[1] := 1;
	mx := 1;
	l := 1;
	cnt := 1;
	online := 1;
	for i := 2 to n do
	begin
		last[i] := 1;
		while ( a[l] <= a[i] - t ) do
		begin
			dec( online, last[l] );
			inc( l );
		end;
		
		if ( online = m ) then
		begin
			ans[i] := ans[i - 1];
			last[i - 1] := 0;
		end
		else
		begin
			inc( cnt );
			inc( online );
			ans[i] := cnt;
		end;
		
		mx := max( mx, online );
	end;
	
	if ( mx < m ) then
	begin
		writeln( 'No solution' );
		
		halt;
	end;
	
	writeln( cnt );
	for i := 1 to n do
		writeln( ans[i] );
end.