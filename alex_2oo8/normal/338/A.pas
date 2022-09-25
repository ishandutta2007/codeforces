program problem1;

const md =	1000000009;

function pow( x: int64; p: longInt ): longInt;
var	res: longInt;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * x ) mod md;
			
		x := ( x * x ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

var	n, m, k, d: longInt;
	ans: int64;

begin
	readln( n, m, k );
	
	d := ( n div k ) * ( k - 1 ) + ( n mod k );
	
	if ( d >= m ) then
		writeln( m )
	else
	begin
		ans := ( pow( 2, m - d + 1 ) - 2 + md ) mod md;
		ans := ( ( ans * k ) + m - (m-d) * k ) mod md;
		
		writeln( ans );
	end;
end.