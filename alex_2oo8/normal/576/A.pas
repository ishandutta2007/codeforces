program problem1;

function isPrimePower( x: longInt ): boolean;
var	d: longInt;
begin
	d := 2;
	while ( x mod d > 0 ) do
		inc( d );
	
	while ( x mod d = 0 ) do
		x := x div d;
	
	exit( x = 1 );
end;

var	n, k, i: longInt;

begin
	readln( n );
	
	k := 0;
	for i := 2 to n do
		if ( isPrimePower( i ) ) then
			inc( k );
	
	writeln( k );
	for i := 2 to n do
		if ( isPrimePower( i ) ) then
			write( i, ' ' );
	
	writeln();
end.