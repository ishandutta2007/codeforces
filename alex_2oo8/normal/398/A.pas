program problem1;
uses math;

const	inf: int64 =	1000000000000;

function f( b, k: longInt ): int64;
var	n, m: longInt;
begin
	n := b div k;
	m := b mod k;
	
	if ( inf div ( int64(n + 1) * (n + 1) ) < m ) or ( inf div ( int64(n) * n ) < k - m ) then
		exit( inf );
	
	exit( m * int64(n + 1) * (n + 1) + (k - m) * int64(n) * n );
end;

procedure writeAns( a, b, k: longInt );
var	n, m, i, j: longInt;
begin
	n := b div k;
	m := b mod k;
	
	for i := 1 to k do
	begin
		for j := 1 to n do
			write( 'x' );
			
		if ( i <= m ) then
			write( 'x' );
		
		if ( i = 1 ) then
		begin
			for j := 1 to a - k + 2 do
				write( 'o' );
		end
		else if ( i < k ) then
			write( 'o' );
	end;
	
	writeln();
end;

var	a, b, ansK, k: longInt;
	ans: int64;

begin
	readln( a, b );
	
	if ( a = 0 ) then
	begin
		writeln( -int64(b) * b );
		for a := 1 to b do
			write( 'x' );
		writeln();
		
		halt;
	end;
	
	if ( b = 0 ) then
	begin
		writeln( int64(a) * a );
		for b := 1 to a do
			write( 'o' );
		writeln();
		
		halt;
	end;
	
	if ( b = 1 ) then
	begin
		writeln( int64(a) * a - 1 );
		for b := 1 to a do
			write( 'o' );
		writeln( 'x' );
		
		halt;
	end;
	
	ansK := 2;
	ans := int64(a) * a - f(b, 2);
	for k := 3 to min(a + 1, b) do
		if ( int64(a - k + 2) * (a - k + 2) + (k - 2) - f(b, k) > ans ) then
		begin
			ans := int64(a - k + 2) * (a - k + 2) + (k - 2) - f(b, k);
			ansK := k;
		end;
		
	writeln( ans );
	writeAns( a, b, ansK );
end.