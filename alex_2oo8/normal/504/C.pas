program problem3;

var	n: longInt;
	a, cnt: array[ 1..100000 ] of longInt;
	
function check( p: longInt ): boolean;
var	i: longInt;
begin
	fillchar( cnt, sizeOf(cnt), 0 );
	if ( p <= n div 2 ) then
	begin
		for i := 1 to p do
		begin
			inc( cnt[ a[i] ] );
			dec( cnt[ a[n + 1 - i] ] );
		end;
		
		for i := 1 to n do
			if ( cnt[i] <> 0 ) then
				exit( false );
		
		for i := (p + 1) to (n div 2) do
			if ( a[i] <> a[n + 1 - i] ) then
				exit( false );
		
		exit( true );
	end;
	
	for i := 1 to p do
		inc( cnt[ a[i] ] );
	
	for i := (p + 1) to n do
		dec( cnt[ a[i] ] );
	
	for i := 1 to n do
		if ( cnt[i] < 0 ) then
			exit( false );
	
	exit( true );
end;
	
function calc(): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := n;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		if ( check(c) ) then
			r := c
		else
			l := c + 1; 
	end;
	
	exit( n - l + 1 );
end;

var	i, offset, x: longInt;
	ans: int64;

begin
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	i := 0;
	while ( i < n ) and ( a[i + 1] = a[n - i] ) do
		inc( i );
	
	if ( i = n ) then
	begin
		writeln( ( n * int64(n + 1) ) div 2 );
		
		halt;
	end;
	
	offset := i;
	for i := offset + 1 to n do
		a[i - offset] := a[i];
	
	dec( n, 2 * offset );
	
	for i := 1 to n do
		inc( cnt[ a[i] ] );
		
	x := 0;
	for i := 1 to n do
		inc( x, cnt[i] and 1 );
	
	if ( x > 1 ) then
	begin
		writeln( 0 );
		
		halt;
	end;
	
	ans := calc() - 1;
	
	for i := 1 to (n div 2) do
	begin
		a[i] := a[i] xor a[n + 1 - i];
		a[n + 1 - i] := a[i] xor a[n + 1 - i];
		a[i] := a[i] xor a[n + 1 - i];
	end;
	
	inc( ans, calc() );
	
	writeln( ans * (offset + 1) + offset * int64(offset + 1) );
end.