program problem1;

const	md =	1000000007;

var	n, i, mx, k, ans: longInt;
	cnt: array[ 'A'..'Z' ] of longInt;
	s: ansistring;
	c: char;

begin
	readln( n );
	readln( s );
	
	for i := 1 to n do
		inc( cnt[ s[i] ] );
	
	mx := 0;
	for c := 'A' to 'Z' do
	begin
		if ( cnt[c] > mx ) then
		begin
			mx := cnt[c];
			k := 1;
		end
		else if ( cnt[c] = mx ) then
			inc( k );
	end;
	
	ans := 1;
	for i := 1 to n do
		ans := ( ans * int64(k) ) mod md;
	
	writeln( ans );
end.