program problem1;

var	n, i, cnt0, cnt1, cnt2, ans1, ans2: longInt;
	s, t: ansistring;

begin
	readln( n );
	readln( s );
	readln( t );
	
	n := 2 * n;
	
	cnt0 := 0;
	cnt1 := 0;
	cnt2 := 0;
	for i := 1 to n do
		if ( s[i] = '1' ) and ( t[i] = '1' ) then
			inc( cnt0 )
		else if ( s[i] = '1' ) then
			inc( cnt1 )
		else if ( t[i] = '1' ) then
			inc( cnt2 );
			
	ans1 := ( cnt0 + 1 ) div 2;
	ans2 := cnt0 div 2;
	
	if ( odd(cnt0) ) then
	begin
		if ( cnt2 > cnt1 ) then
			inc( ans2, ( (cnt2-cnt1+1) div 2 ) )
		else
			inc( ans1, ( (cnt1-cnt2) div 2 ) );
	end
	else
	begin
		if ( cnt1 > cnt2 ) then
			inc( ans1, ( (cnt1-cnt2+1) div 2 ) )
		else
			inc( ans2, ( (cnt2-cnt1) div 2 ) );
	end;
	
	if ( ans1 > ans2 ) then
		writeln( 'First' )
	else if ( ans2 > ans1 ) then
		writeln( 'Second' )
	else
		writeln( 'Draw' );
end.