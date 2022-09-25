program problem1;

var	n, m, i, j, ii, ans: longInt;
	s1, s2: ansistring;
	next: array[ 1..20001, 'a'..'z' ] of longInt;
	c: char;

begin
	readln( s1 );
	readln( s2 );
	
	n := length(s1);
	m := length(s2);
	
	for c := 'a' to 'z' do
		next[2*n+1][c] := -1;
	
	for i := 2 * n downTo 1 do
	begin
		if ( i > n ) then
			ii := i - n
		else
			ii := i;
			
		for c := 'a' to 'z' do
			next[i][c] := next[i+1][c];
			
		next[i][ s1[ii] ] := ii;
	end;
	
	i := 1;
	ans := 0;
	for j := 1 to m do
	begin
		if ( i = 1 ) then
			inc( ans );
	
		ii := next[i][ s2[j] ];

		if ( ii = -1 ) then
		begin
			ans := -1;
			break;
		end;
		
		if ( ii < i ) then
			inc( ans );
			
		i := ( ii mod n ) + 1;
	end;
	
	writeln( ans );
end.