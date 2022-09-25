program problem2;

var	s: ansistring;
	d: array[ 1..100000 ] of longInt;
	n, i, cnt: longInt;
	ans: int64;

begin
	readln( s );
	n := length(s);
	
	for i := 1 to n do
		d[i] := ord( s[i] ) - ord( '0' );
	
	ans := 1;
	i := 1;
	while ( i < n ) do
	begin
		cnt := 1;
		while ( i < n ) and ( d[i] + d[i+1] = 9 ) do
		begin
			inc( cnt );
			inc( i );
		end;
		
		if ( odd(cnt) ) then
			ans := ans * ( (cnt+1) div 2 );
		
		inc( i );
	end;
	
	writeln( ans );
end.