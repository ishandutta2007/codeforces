program problem3;

var	n, m: longInt;
	res: extended;

begin
	readln( n, m );
	
	if ( n = 1 ) and ( m = 1 ) then
	begin
		writeln( '1.0' );
		halt;
	end;
	
	res := ( 1.0 + (n - 1) * (m - 1) / (n * m - 1) ) / n;
	
	writeln( res:0:15 );
end.