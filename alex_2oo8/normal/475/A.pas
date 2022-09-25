program peoblem1;

var	n, i: longInt;
	s: string;

begin
	readln( n );
	
	writeln( '+------------------------+' );
	s := '|O.O.O.#.#.#.#.#.#.#.#.|D|)';
	if ( n = 0 ) then
		s[2] := '#';
	for i := 2 to 11 do
		if ( 3 * i - 1 <= n ) then
			s[2 * i] := 'O'
		else
			s[2 * i] := '#';
		
	writeln( s );
	s := '|O.O.O.#.#.#.#.#.#.#.#.|.|';
	if ( n < 2 ) then
		s[2] := '#';
	for i := 2 to 11 do
		if ( 3 * i <= n ) then
			s[2 * i] := 'O'
		else
			s[2 * i] := '#';
		
	writeln( s );
	if ( n > 2 ) then
		writeln( '|O.......................|' )
	else
		writeln( '|#.......................|' );
		
	s := '|O.O.#.#.#.#.#.#.#.#.#.|.|)';
	if ( n < 4 ) then
		s[2] := '#';
	for i := 2 to 11 do
		if ( 3 * i + 1 <= n ) then
			s[2 * i] := 'O'
		else
			s[2 * i] := '#';
		
	writeln( s );
	writeln( '+------------------------+' );
end.