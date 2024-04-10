program problem2;
uses math;

function gcd( a, b: longInt ): longInt;
var	c: longInt;
begin
	while ( b > 0 ) do
	begin
		c := b;
		b := a mod b;
		a := c;
	end;
	
	exit( a );
end;

var	n, m, x, y, a, b, g, x1, y1, x2, y2: longInt;

begin
	readln( n, m, x, y, a, b );
	
	g := gcd( a, b );
	a := a div g;
	b := b div g;
	
	g := min( n div a, m div b );
	a := a * g;
	b := b * g;
	
	x1 := x - ( (a+1) div 2 );
	y1 := y - ( (b+1) div 2 );
	x2 := x1 + a;
	y2 := y1 + b;
	
	if ( x1 < 0 ) then
	begin
		g := -x1;
		
		inc( x1, g );
		inc( x2, g );
	end;
	
	if ( y1 < 0 ) then
	begin
		g := -y1;
		
		inc( y1, g );
		inc( y2, g );
	end;
	
	if ( x2 > n ) then
	begin
		g := x2 - n;
		
		dec( x1, g );
		dec( x2, g );
	end;
	
	if ( y2 > m ) then
	begin
		g := y2 - m;
		
		dec( y1, g );
		dec( y2, g );
	end;
	
	writeln( x1, ' ', y1, ' ', x2, ' ', y2 );
end.