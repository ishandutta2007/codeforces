program problem3;

function pow( a: int64; p, md: longInt ): int64;
var	res: int64;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * a ) mod md;
		
		a := ( a * a ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

var	n, i, x: longInt;
//	used: array[ 1..100000 ] of longInt;

begin
	readln( n );
	
	if ( n < 4 ) then
	begin
		writeln( 'YES' );
		for i := 1 to n do
			writeln( i );
		
		halt;
	end;
	
	if ( n = 4 ) then
	begin
		writeln( 'YES' );
		writeln( 1 );
		writeln( 3 );
		writeln( 2 );
		writeln( 4 );
		
		halt;
	end;
	
	for i := 2 to n - 1 do
		if ( n mod i = 0 ) then
		begin
			writeln( 'NO' );
			
			halt;
		end;
	
	writeln( 'YES' );
	writeln( 1 );
	
	x := 1;
	for i := 2 to n do
	begin
		x := ( pow( i - 1, n - 2, n ) * i ) mod n;
		
		if ( x = 0 ) then
			x := n;
		
//		inc( used[x] );
		
		writeln( x );
	end;
	
//	for i := 2 to n do
//		if ( used[i] <> 1 ) then
//			writeln( 'fail' );
end.