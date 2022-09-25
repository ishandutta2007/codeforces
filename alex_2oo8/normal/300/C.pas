program problem3;

const	md =	1000000007;

function pow( a, p: longInt ): longInt;
var	res: longInt;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( qWord(res) * a ) mod md;
			
		a := ( qWord(a) * a ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

function check( x, a, b: longInt ): boolean;
var	s: string[10];
	i: longInt;
begin
	str( x, s );
	
	for i := 1 to length(s) do
		if ( ord( s[i] ) - ord( '0' ) <> a ) and ( ord( s[i] ) - ord( '0' ) <> b ) then
			exit( false );
			
	exit( true );
end;

var	n, i, a, b, ans: longInt;
	c: array[ 0..1000000 ] of longInt;

begin
	readln( a, b, n );
	
	c[0] := 1;
	for i := 1 to n do
		c[i] := ( ( ( c[i-1] * qWord(n-i+1) ) mod md ) * pow( i, md - 2 ) ) mod md;
		
	ans := 0;
	for i := 0 to n do
		if ( check( i * a + (n-i) * b, a, b ) ) then
			ans := ( ans + c[i] ) mod md;
			
	writeln( ans );
end.