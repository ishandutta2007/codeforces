program problem3;

function gcd( a, b: int64 ): int64;
var	c: int64;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;
	
	exit( a );
end;

var	c, hr, hb, wr, wb, lcm, ans, best, cur: int64;
	i: longInt;

begin
	readln( c, hr, hb, wr, wb );
	
	lcm := ( wr * wb ) div gcd( wr, wb );
	
	ans := 0;
	if ( c div lcm >= 2 ) then
	begin
		if ( hr * wb > hb * wr ) then
			ans := ( c div lcm - 1 ) * ( lcm div wr ) * hr
		else
			ans := ( c div lcm - 1 ) * ( lcm div wb ) * hb;
		
		c := lcm + ( c mod lcm );
	end;
	
	if ( wr < wb ) then
	begin
		wb := wb xor wr;
		wr := wb xor wr;
		wb := wb xor wr;
		
		hb := hb xor hr;
		hr := hb xor hr;
		hb := hb xor hr;
	end;
	
	best := 0;
	for i := 0 to longInt(c div wr) do
	begin
		cur := hr * i + hb * ( ( c - i * wr ) div wb );
		
		if ( cur > best ) then
			best := cur;
	end;
	
	writeln( ans + best );
end.