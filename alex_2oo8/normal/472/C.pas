program problem3;

var	n, i, x, l: longInt;
	bufIn: array[ 1..1 shl 16 ] of byte;
	fb, sb, ff, ss: boolean;
	f, s: array[ 1..100000 ] of string;
	st: string;

begin
	setTextBuf( input, bufIn, sizeOf(bufIn) );

	readln( n );
	for i := 1 to n do
	begin
		readln( st );
		
		x := pos( ' ', st );
		
		f[i] := copy( st, 1, x - 1 );
		s[i] := copy( st, x + 1, length(st) - x );
	end;
	
	read( x );
	fb := true;
	sb := true;
	for i := 2 to n do
	begin
		l := x;
		read( x );
		
		ff := ( ( f[x] > f[l] ) and fb ) or ( ( f[x] > s[l] ) and sb );
		ss := ( ( s[x] > f[l] ) and fb ) or ( ( s[x] > s[l] ) and sb );
		
		fb := ff;
		sb := ss;
	end;
	
	if ( fb or sb ) then
		writeln( 'YES' )
	else
		writeln( 'NO' );
end.