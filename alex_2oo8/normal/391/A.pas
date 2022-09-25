program problem1;

var	s: ansistring;
	n, i, j, ans: longInt;

begin
	readln( s );
	n := length(s);
	
	ans := 0;
	i := 1;
	while ( i <= n ) do
	begin
		j := i;
		while ( j < n ) and ( s[j + 1] = s[i] ) do
			inc( j );
		
		if ( odd(j - i) ) then
			inc( ans );
		
		i := j + 1;
	end;
	
	writeln( ans );
end.