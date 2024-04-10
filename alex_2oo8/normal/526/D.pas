program problem4;

var	n, k, i, j, p: longInt;
	s, t: ansistring;
	kmp: array[ 1..1000000 ] of longInt;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );

	readln( n, k );
	readln( s );
	
	t := s;
	t[1] := '0';
	
	kmp[1] := 0;
	for i := 2 to n do
	begin
		j := kmp[i - 1];
		while ( j > 0 ) and ( s[i] <> s[j + 1] ) do
			j := kmp[j];
		
		if ( s[i] = s[j + 1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
		
		t[i] := '0';
		if ( 2 * kmp[i] >= i ) then
		begin
			p := i - kmp[i];
			if ( i mod p = 0 ) then
			begin
				p := i div p;
				if ( (k + 1) * (p div k) >= p ) then
					t[i] := '1';
			end
			else
			begin
				p := ( i div p );
				if ( (k + 1) * (p div k) > p ) then
					t[i] := '1';
			end;
		end;
	end;
	
	if ( k = 1 ) then
		for i := 1 to n do
			t[i] := '1';
	
	writeln( t );
end.