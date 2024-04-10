program problem3;

var	n, k, i, e, o, x, a, b: longInt;

begin
	readln( n, k );
	for i := 1 to n do
	begin
		read( x );
		
		if ( odd(x) ) then
			inc( o )
		else
			inc( e );
	end;
	
	if ( n = k ) then
	begin
		if ( o mod 2 = 1 ) then
			writeln( 'Stannis' )
		else
			writeln( 'Daenerys' );
		
		halt;
	end;
	
	a := (n - k + 1) div 2;
	b := (n - k) div 2;
	
	if ( e <= a ) and ( k mod 2 = 1 ) then
	begin
		writeln( 'Stannis' );
		
		halt;
	end;
	
	if ( ( e <= b ) and ( k mod 2 = 0 ) ) or ( o <= b ) then
	begin
		writeln( 'Daenerys' );
		
		halt;
	end;
	
	if ( a > b ) then
	begin
		writeln( 'Stannis' );
		
		halt;
	end;
	
	writeln( 'Daenerys' );
end.