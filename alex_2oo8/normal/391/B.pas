program problem2;
uses math;

var	s: ansistring;
	n, i, j, ans: longInt;
	f: array[ 1..1000 ] of longInt;

begin
	readln( s );
	n := length(s);
	
	for i := 1 to n do
	begin
		f[i] := 1;
		
		for j := 1 to i - 1 do
			if ( s[i] = s[j] ) and ( odd(i - j) ) then
				f[i] := max( f[i], f[j] + 1 );
	end;
	
	ans := 0;
	for i := 1 to n do
		ans := max( ans, f[i] );
	
	writeln( ans );
end.