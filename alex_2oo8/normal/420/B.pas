program problem2;

var	n, m, i, x, cnt: longInt;
	ok: array[ 1..100000 ] of boolean;
	a: array[ 1..100000 ] of longInt;
	c: char;
	fromStart, tillEnd: boolean;

begin
	readln( n, m );
	
	fillchar( ok, sizeOf(ok), false );
	fromStart := false;
	tillEnd := false;
	cnt := 0;
	for i := 1 to m do
	begin
		readln( c, x );
		
		if ( c = '-' ) then
		begin
			a[i] := -x;
			
			if ( not ok[x] ) then
			begin
				fromStart := true;
				inc( cnt );
			end;
		end
		else
		begin
			a[i] := x;
			
			ok[x] := true;
		end;
	end;
	
	fillchar( ok, sizeOf(ok), false );
	for i := m downto 1 do
		if ( a[i] > 0 ) and ( not ok[ a[i] ] ) then
			tillEnd := true
		else if ( a[i] < 0 ) then
			ok[ -a[i] ] := true;
	
	fillchar( ok, sizeOf(ok), true );
	for i := 1 to m do
		if ( a[i] < 0 ) then
		begin
			dec( cnt );
			ok[ -a[i] ] := ok[ -a[i] ] and ( cnt = 0 ) and ( ( ( i = m ) and ( not tillEnd ) ) or ( ( i < m ) and ( a[i + 1] = -a[i] ) ) );
		end
		else
		begin
			ok[ a[i] ]  := ok[ a[i] ]  and ( cnt = 0 ) and ( ( ( i = 1 ) and ( not fromStart ) ) or ( ( i > 1 ) and ( a[i - 1] = -a[i] ) ) );
			inc( cnt );
		end;

	x := 0;
	for i := 1 to n do
		if ( ok[i] ) then
			inc( x );
	
	writeln( x );
	for i := 1 to n do
		if ( ok[i] ) then
			write( i, ' ' );
	
	writeln();
end.