program problem1;

var	n, m, i, j, ans: longInt;
	s: array[ 1..50 ] of ansistring;
	have: array[ #0..#255 ] of boolean;

begin
	readln( n, m );
	for i := 1 to n do
		readln( s[i] );
	
	ans := 0;
	for i := 1 to n - 1 do
		for j := 1 to m - 1 do
		begin
			fillchar( have, sizeOf(have), 0 );
			
			have[ s[i][j] ] := true;
			have[ s[i + 1][j] ] := true;
			have[ s[i][j + 1] ] := true;
			have[ s[i + 1][j + 1] ] := true;
			
			if ( have['f'] and have['a'] and have['c'] and have['e'] ) then
				inc( ans );
		end;
	
	writeln( ans );
end.