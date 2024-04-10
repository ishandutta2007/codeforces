program problem1;

var	s: ansistring;
	len, i, cnt, q: longInt;
	has: array[ 'A'..'J' ] of boolean;
	ans: int64;
	c: char;

begin
	readln( s );
	len := length(s);
	
	q := 0;
	ans := 1;
	for i := 1 to len do
		if ( s[i] = '?' ) and ( i = 1 ) then
			ans := ans * 9
		else if ( s[i] = '?' ) then
			inc( q )
		else if ( s[i] in ['A'..'J'] ) then
			has[ s[i] ] := true;
			
	cnt := 0;
	for c := 'A' to 'J' do
		if ( has[c] ) then
			inc( cnt );
			
	if ( s[1] in ['A'..'J'] ) then
		ans := ans * 9
	else if ( cnt > 0 ) then
		ans := ans * 10;
	
	dec( cnt );
	
	for i := 1 to cnt do
		ans := ans * ( 10 - i );
		
	write( ans );
	for i := 1 to q do
		write( 0 );
	writeln();
end.