program problem3;

var	ans: array[ 0..1000000 ] of longInt;

procedure solve( n: longInt );
var	p, q, i: longInt;
begin
	if ( n = 0 ) then
		exit();

	if ( n = 1 ) then
	begin
		ans[1] := 0;
		ans[0] := 1;
		
		exit();
	end;
	
	p := 0;
	while ( ( 1 shl (p+1) ) <= n ) do
		inc( p );
		
	p := 1 shl p;
	q := p - 1;
	while ( p <= n ) do
	begin
		ans[p] := q;
		ans[q] := p;
		
		inc( p );
		dec( q );
	end;
	
	solve( q );
end;

var	n, i: longInt;
	sum: qWord;

begin
	readln( n );
	
	solve( n );
	
	sum := 0;
	for i := 0 to n do
		inc( sum, ( ans[i] xor i ) );
		
	writeln( sum );
	for i := 0 to n do
		write( ans[i], ' ' );
	writeln();
end.