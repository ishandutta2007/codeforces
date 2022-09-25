program problem3;
uses math;

var	n, m, i, dd, hh, d, h, ans, t: longInt;

begin
	readln( n, m );
	readln( dd, hh );
	
	ans := hh + dd - 1;
	for i := 2 to m do
	begin
		readln( d, h );
		
		if ( abs(h - hh) > abs(d - dd) ) then
		begin
			writeln( 'IMPOSSIBLE' );
			
			halt;
		end;
		
		t := abs(d - dd) - abs(h - hh);
		ans := max( ans, max( h, hh ) + t div 2 );
		
		dd := d;
		hh := h;
	end;
	
	writeln( max( ans, hh + n - dd ) );
end.