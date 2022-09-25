program problem2;

const	md =	1000000007;

var	n, m, i, j, l, ans: longInt;
	a, kmp, ok: array[ 1..1000000 ] of longInt;
	s: ansistring;
	bufIn: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );

	readln( n, m );
	readln( s );
	for i := 1 to m do
		read( a[i] );
	
	if ( m = 0 ) then
	begin
		// Go fuck yourself stupid asshole
		
		ans := 1;
		for i := 1 to n do
			ans := ( ans * int64(26) ) mod md;
		
		writeln( ans );
		
		halt;
	end;
	
	l := length(s);
	kmp[1] := 0;
	for i := 2 to l do
	begin
		j := kmp[i - 1];
		while ( j > 0 ) and ( s[i] <> s[j + 1] ) do
			j := kmp[j];
		
		if ( s[i] = s[j + 1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
	end;
	
	j := kmp[i];
	while ( j > 0 ) do
	begin
		ok[j] := 1;
		j := kmp[j];
	end;
	
	ans := 1;
	for i := 1 to a[1] - 1 do
		ans := ( ans * int64(26) ) mod md;
	
	for i := a[m] + l to n do
		ans := ( ans * int64(26) ) mod md;
	
	for i := 2 to m do
	begin
		if ( a[i] = a[i - 1] + l ) then
			continue;
		
		if ( a[i] < a[i - 1] + l ) then
			ans := ans * ok[ a[i - 1] + l - a[i] ]
		else
			for j := a[i - 1] + l to a[i] - 1 do
				ans := ( ans * int64(26) ) mod md;
	end;
	
	writeln( ans );
end.