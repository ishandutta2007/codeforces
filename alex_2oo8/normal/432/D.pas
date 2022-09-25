program problem4;

var	s: ansistring;
	n, i, j, k: longInt;
	kmp, cnt: array[ 0..100000 ] of longInt;
	equal: array[ 1..100000 ] of boolean;

begin
	fillchar( equal, sizeOf(equal), 0 );
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( s );
	n := length(s);
	
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
			
		inc( cnt[ kmp[i] ] );
	end;
	
	i := kmp[n];
	while ( i > 0 ) do
	begin
		equal[i] := true;
		
		i := kmp[i];
	end;
	
	for i := n downto 1 do
		inc( cnt[ kmp[i] ], cnt[i] );
		
	k := 1;
	for i := 1 to n do
		if ( equal[i] ) then
			inc( k );
	
	writeln( k );
	for i := 1 to n do
		if ( equal[i] ) then
			writeln( i, ' ', cnt[i] + 1 );
	
	writeln( n, ' ', 1 );
end.