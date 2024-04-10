program problem2;

var	n, r, c, i, j, k, p, len, ans, firstWord: longInt;
	s: ansistring;
	first: array[ 1..1000001 ] of longInt;
	next: array[ 1..1000000, 0..20 ] of longInt;
	buf: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, buf );

	readln( n, r, c );
	readln( s );
	s := s + ' ';
	
	len := length(s);
	p := 0;
	k := 1;
	for i := 1 to len do
		if ( s[i] = ' ' ) then
		begin
			first[k] := p + 1;
			p := i;
			inc( k );			
		end;
		
	first[n+1] := len + 1;
	for i := 0 to 20 do
		next[n+1][i] := n + 1;
		
	inc( c );
	
	j := n + 1;
	for i := n downTo 1 do
	begin
		while ( first[j] - first[i] > c ) do
			dec( j );
			
		next[i][0] := j;
		for k := 1 to 20 do
			next[i][k] := next[ next[i][k-1] ][k-1];
	end;
	
	ans := 0;
	firstWord := n + 1;
	for i := 1 to n do
	begin
		p := r;
		j := i;
		for k := 20 downTo 0 do
			if ( ( 1 shl k ) <= p ) then
			begin
				j := next[j][k];
				dec( p, ( 1 shl k ) );
			end;
			
		if ( (j-i+1) > ans ) then
		begin
			ans := j - i + 1;
			firstWord := i;
		end;
	end;

	k := firstWord;
	for i := 1 to r do
	begin
		if ( k > n ) then
			break;

		for j := first[k] to first[ next[k][0] ] - 2 do
			write( s[j] );
		writeln();
		
		k := next[k][0];
	end;
end.