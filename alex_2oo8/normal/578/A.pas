program problem1;
uses math;

function f( p, q: longInt ): extended;
var	k: longInt;
begin
	k := round( p / q ) + 5;
	while ( k mod 2 = 1 ) or ( p < q * int64(k) ) do
		dec( k );
	
	exit( p / k );
end;

var	a, b: longInt;
	ans: extended;

begin
	readln( a, b );
	
	if ( a = b ) then
	begin
		writeln( a );
		
		halt;
	end;
	
	if ( a + b < 2 * b ) then
	begin
		writeln( -1 );
		
		halt;
	end;
	
	ans := f( a + b, b );
	if ( a - b >= 2 * b ) then
		ans := min( ans, f( a - b, b ) );
	
	writeln( ans:0:12 );
end.