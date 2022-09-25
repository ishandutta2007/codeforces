program problem1;

var	n, i, b: longInt;
	s: ansistring;
	ans: array[ 1..100000 ] of longInt;

begin
	readln( s );
	n := length(s);
	
	b := 0;
	for i := 1 to n do
	begin
		if ( s[i] = '(' ) then
			inc( b )
		else
			dec( b );
		
		if ( s[i] = '#' ) then
			ans[i] := 1;
		
		if ( b < 0 ) then
		begin
			writeln( -1 );
			halt;
		end;
	end;
	
	i := n;
	while ( s[i] <> '#' ) do
		dec( i );
	
	ans[i] := b + 1;
	
	b := 0;
	for i := 1 to n do
	begin
		if ( s[i] = '(' ) then
			inc( b )
		else if ( s[i] = ')' ) then
			dec( b )
		else
			dec( b, ans[i] );
		
		if ( b < 0 ) then
		begin
			writeln( -1 );
			halt;
		end;
	end;
	
	for i := 1 to n do
		if ( s[i] = '#' ) then
			writeln( ans[i] );
end.