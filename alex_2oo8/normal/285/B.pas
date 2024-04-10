program problem2;

var	n, s, t, pp, ans, i: longInt;
	p: array[ 1..100000 ] of longInt;

begin
	readln( n, s, t );
	for i := 1 to n do
	begin
		read( pp );
		p[pp] := i;
	end;
	
	ans := 0;
	while ( t <> s ) and ( p[t] <> 0 ) do
	begin
		inc( ans );
		pp := p[t];
		p[t] := 0;
		t := pp;
	end;
	
	if ( t <> s ) then
		ans := -1;
		
	writeln( ans );
end.