program problem2;

var	n, x, y, i, j: longInt;
	p, q: array[ -2000..1000 ] of longInt;
	can: array[ 0..1000 ] of boolean;
	
function calc( k: longInt ): longInt;
begin
	if ( k = x ) then
		exit( -2 * n )
	else if ( k = 0 ) then
		exit( 0 );
	
	exit( calc( p[k] ) + 1 );
end;

begin
	readln( n, x );
	for i := 1 to n do
		read( p[i] );
		
	for i := 1 to n do
		q[i] := -100000;
		
	for i := 1 to n do
		q[ p[i] ] := 0;
	
	for i := 1 to n do
		if ( i = x ) then
		begin
			if ( p[i] = 0 ) then
				y := 0
			else
				y := calc( p[i] );
		end
		else if ( q[i] = -100000 ) then
		begin
			if ( p[i] = 0 ) then
				q[i] := 1
			else
				q[i] := calc( p[i] ) + 1;
		end;
			
	can[0] := true;
	for i := 1 to n do
		if ( q[i] > 0 ) then
			for j := n downTo q[i] do
				can[j] := can[j] or can[ j - q[i] ];
			
	for i := 0 to n do
		if ( can[i] ) then
			writeln( i + y + 1 );
end.