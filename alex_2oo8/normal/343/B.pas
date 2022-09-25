program problem2;

var	n, i, r: longInt;
	s: ansistring;
	a: array[ 0..100000 ] of char;

begin
	readln( s );
	n := length( s );
	
	if ( odd(n) ) then
	begin
		writeln( 'No' );
		halt;
	end;
	
	r := 1;
	a[0] := '.';
	a[1] := s[1];
	for i := 2 to n do
	begin
		if ( s[i] = a[r] ) then
			dec( r )
		else
		begin
			inc( r );
			a[r] := s[i];
		end;
	end;
	
	if ( r = 0 ) then
		writeln( 'Yes' )
	else
		writeln( 'No' );
end.