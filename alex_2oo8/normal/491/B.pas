program problem2;
uses math;

var	n, m, i, x, y, xx, yy, ans, dist, minX, minY, maxX, maxY: longInt;

begin
	readln( n, m );
	
	minX := n + m;
	minY := n + m;
	maxX := -minX;
	maxY := -minY;
	
	dist := n + m + 1;
	
	readln( n );
	for i := 1 to n do
	begin
		readln( x, y );
		
		minX := min( minX, x - y );
		maxX := max( maxX, x - y );
		minY := min( minY, x + y );
		maxY := max( maxY, x + y );
	end;
	
	readln( m );
	for i := 1 to m do
	begin
		readln( xx, yy );
		
		x := xx - yy;
		y := xx + yy;
		if ( max( max( abs( minX - x ), abs( maxX - x ) ), max( abs( minY - y ), abs( maxY - y ) ) ) < dist ) then
		begin
			dist := max( max( abs( minX - x ), abs( maxX - x ) ), max( abs( minY - y ), abs( maxY - y ) ) );
			ans := i;
		end;
	end;
	
	writeln( dist );
	writeln( ans );
end.