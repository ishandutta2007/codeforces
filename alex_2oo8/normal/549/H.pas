program problem8;
uses math;

var	aa, bb, cc, dd: longInt;
	a, b, c, d, t: int64;
	ans, f: extended;

begin
	readln( aa, bb, cc, dd );
	
	a := aa;
	b := bb;
	c := cc;
	d := dd;
	
	if ( a * d = b * c ) then
	begin
		writeln( '0.0' );
		
		halt;
	end;
	
	if ( a + d < 0 ) then
	begin
		a := -a;
		d := -d;
	end;
	
	if ( b + c < 0 ) then
	begin
		b := -b;
		c := -c;
	end;
	
	if ( a * d < 0 ) and ( b * c < 0 ) then
	begin
		a := abs(a);
		b := abs(b);
		c := abs(c);
		d := abs(d);
	end;
	
	if ( a > d ) then
	begin
		t := a;
		a := d;
		d := t;
	end;
	
	if ( b > c ) then
	begin
		t := b;
		b := c;
		c := t;
	end;
	
	if ( a > b ) then
	begin
		t := a;
		a := b;
		b := t;
		
		t := d;
		d := c;
		c := t;
	end;
	
	if ( a + b + c + d = 0 ) then
	begin
		writeln( ( abs( abs(a) - abs(b) ) / 2 ):0:12 );
		
		halt;
	end;
	
	ans := abs( a * d - b * c ) / ( a + b + c + d );
	if ( a < 0 ) then
	begin
		f := abs( a * d - b * c ) / ( c + d - a - b );
		
		if ( f < ans ) then
			ans := f;
	end;
	
	writeln( ans:0:12 );
end.