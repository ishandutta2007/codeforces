program problem5;

var	n, l, r, i, f, ans: longInt;
	s, t: ansistring;

begin
	readln( n );
	readln( s );
	readln( t );
	
	l := 1;
	while ( s[l] = t[l] ) do
		inc( l );
	
	r := n;
	while ( s[r] = t[r] ) do
		dec( r );
	
	ans := 0;
	f := 1;
	for i := l to r - 1 do
		if ( s[i] <> t[i + 1] ) then
			f := 0;
	
	inc( ans, f );
	f := 1;
	for i := l to r - 1 do
		if ( t[i] <> s[i + 1] ) then
			f := 0;
	
	inc( ans, f );
	
	writeln( ans );
end.