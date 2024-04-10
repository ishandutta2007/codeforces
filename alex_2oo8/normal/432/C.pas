program problem3;

var	a, w, p, q: array[ 1..500000 ] of longInt;
	ans: longInt = 0;

procedure swap( x, y: longInt );
var	tmp: longInt;
begin
	tmp := a[x];
	a[x] := a[y];
	a[y] := tmp;
	
	w[ a[x] ] := x;
	w[ a[y] ] := y;
	
	inc( ans );
	q[ans] := x;
	p[ans] := y;
end;

var	n, i, j: longInt;
	last: array[ 0..100000 ] of longInt;
	isPrime: array[ 1..100000 ] of boolean;

begin
	fillchar( isPrime, sizeOf(isPrime), true );
	
	for i := 2 to 100000 do
		if ( isPrime[i] ) then
		begin
			for j := 2 to 100000 div i do
				isPrime[i * j] := false;
				
			last[i] := i;
		end
		else
			last[i] := last[i - 1];
			
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
		w[ a[i] ] := i;
		
	for i := 1 to n do
		while ( w[i] <> i ) do
			swap( w[i], w[i] - last[ w[i] - i + 1 ] + 1 );
	
	writeln( ans );
	for i := 1 to ans do
		writeln( p[i], ' ', q[i] );
end.