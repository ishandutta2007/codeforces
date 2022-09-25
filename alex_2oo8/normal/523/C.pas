program problem3;
uses math;

var	s, t: ansistring;
	n, m, i, j, l, r: longInt;
	buf: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, buf );

	readln( s );
	readln( t );
	
	m := length(s);
	n := length(t);
	
	l := n + 1;
	r := 0;
	
	i := 1;
	for j := 1 to n do
		if ( s[i] = t[j] ) then
		begin
			inc( i );
			
			if ( i > m ) then
			begin
				l := j;
			
				break;
			end;
		end;
	
	i := m;
	for j := n downto 1 do
		if ( s[i] = t[j] ) then
		begin
			dec( i );
			
			if ( i = 0 ) then
			begin
				r := j - 1;
			
				break;
			end;
		end;
	
	writeln( max( r - l + 1, 0 ) );
end.