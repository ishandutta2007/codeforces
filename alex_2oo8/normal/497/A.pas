program problem1;

	
var	i, j, ans: longInt;
	n, m: longInt;
	s: array[ 1..1000 ] of ansistring;
	same: array[ 1..1000 ] of boolean;
	ok: boolean;

begin
	fillchar( same, sizeOf(same), 1 );

	readln( n, m );
	for i := 1 to n do
		readln( s[i] );
	
	ans := 0;
	for i := 1 to m do
	begin
		ok := true;
		for j := 2 to n do
			if ( same[j] ) and ( s[j][i] < s[j - 1][i] ) then
				ok := false;
		
		if ( not ok ) then
			inc( ans )
		else
		begin
			for j := 2 to n do
				same[j] := same[j] and ( s[j][i] = s[j - 1][i] );
		end;
	end;
		
	writeln( ans );
end.