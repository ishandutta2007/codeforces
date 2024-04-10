program problem1;

var	s: ansistring;

function check( b: longInt ): boolean;
var	i, j: longInt;
	ok: boolean;
begin
	for i := 1 to b do
	begin
		ok := true;
		
		for j := 1 to 12 div b do
			ok := ok and ( s[ (j - 1) * b + i ] = 'X' );
			
		if ( ok ) then
			exit( true );
	end;
	
	exit( false );
end;

var	t, ans, i: longInt;
	a: array[ 1..12 ] of longInt;

begin
	readln( t );
	
	while ( t > 0 ) do
	begin
		readln( s );
		
		ans := 0;
		for i := 1 to 12 do
			if ( 12 mod i = 0 ) and ( check( 12 div i ) ) then
			begin
				inc( ans );
				a[ans] := i;
			end;
			
		write( ans );
		for i := 1 to ans do
			write( ' ', a[i], 'x', 12 div a[i] );
		writeln();
	
		dec( t );
	end;
end.