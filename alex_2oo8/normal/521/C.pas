program problem3;

const	md =	1000000007;

var	fact: array[ 0..100000 ] of int64;

function pow( x: int64; p: longInt ): int64;
var	res: int64;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * x ) mod md;
		
		x := ( x * x ) mod md;
	
		p := p div 2;
	end;
	
	exit( res );
end;

function c( n, k: longInt ): int64;
begin
	if ( k > n ) then
		exit( 0 );

	exit( ( fact[n] * pow( ( fact[n - k] * fact[k] ) mod md, md - 2 ) ) mod md );
end;

var	n, k, ans, i, tenPow: longInt;
	f: array[ 0..100000 ] of longInt;
	s: ansistring;

begin
	readln( n, k );
	readln( s );
	
	if ( k = 0 ) then
	begin
		ans := 0;
		for i := 1 to n do
			ans := ( int64(10) * ans + ord( s[i] ) - ord( '0' ) ) mod md;
		
		writeln( ans );
			
		halt;
	end;
	
	if ( k = 1 ) then
	begin
		ans := 0;
		k := 0;
		for i := 1 to n - 1 do
		begin
			k := ( int64(10) * k + ord( s[i] ) - ord( '0' ) ) mod md;
			ans := ( ans + k ) mod md;
		end;
		
		k := 0;
		tenPow := 1;
		for i := n downto 2 do
		begin
			k := ( k + tenPow * int64( ord( s[i] ) - ord( '0' ) ) ) mod md;
			ans := ( ans + k ) mod md;
			
			tenPow := ( tenPow * int64(10) ) mod md;
		end;
		
		writeln( ans );
	
		halt;
	end;
	
	fact[0] := 1;
	for i := 1 to n do
		fact[i] := ( fact[i - 1] * int64(i) ) mod md;
	
	f[0] := c( n - 2, k - 1 );
	tenPow := 1;
	for i := 1 to n do
	begin
		tenPow := ( tenPow * int64(10) ) mod md;
	
		f[i] := ( f[i - 1] + tenPow * c( n - 2 - i, k - 1 ) ) mod md;
	end;
	
	ans := 0;
	for i := 2 to n - 1 do
		ans := ( ans + int64( ord( s[i] ) - ord( '0' ) ) * f[n - 1 - i] ) mod md;
	
	tenPow := 1;
	for i := n downto 2 do
	begin
		ans := ( ans + tenPow * c( i - 1, k ) * ( ord( s[i] ) - ord( '0' ) ) ) mod md;
		
		tenPow := ( tenPow * int64(10) ) mod md;
	end;
	
	tenPow := 1;
	for i := 0 to n - 1 do
	begin
		ans := ( ans + tenPow * c( n - 2 - i, k - 1 ) * ( ord( s[1] ) - ord( '0' ) ) ) mod md;
		
		tenPow := ( tenPow * int64(10) ) mod md;
	end;
	
	writeln( ans );
end.