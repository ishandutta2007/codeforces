program problem1;

var	n: longInt;
	s, t: ansistring;
	cnt: array[ 'a'..'z' ] of longInt;
	
function check( k: longInt ): boolean;
var	i: longInt;
	c: char;
begin
	t := '';
	
	for c := 'a' to 'z' do
		for i := 1 to ( ( cnt[c] + k - 1 ) div k ) do
			t := t + c;
			
	exit( length(t) <= n );
end;
	
var	l, r, c, i: longInt;

begin
	readln( s );
	readln( n );
	
	for i := 1 to length(s) do
		inc( cnt[ s[i] ] );
	
	l := 1;
	r := 1000;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( check( c ) ) then
			r := c
		else
			l := c + 1;
	end;
	
	if ( not check( l ) ) then
	begin
		writeln( -1 );
		halt;
	end;
	
	while ( length(t) < n ) do
		t := t + 'a';
	
	writeln( l );
	writeln( t );
end.