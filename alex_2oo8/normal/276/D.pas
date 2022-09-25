program problem4;

var	l, r, i: qWord;

begin
	readln( l, r );
	
	if ( l = r ) then
	begin
		writeln( 0 );
		halt;
	end;
	
	i := 1;
	while ( ( i shl 1 ) <= r ) do
		i := i shl 1;
		
	while ( i > 0 ) and ( ( i and r ) = ( i and l ) ) do
		i := i shr 1;
		
	writeln( ( i shl 1 ) - 1 );
end.