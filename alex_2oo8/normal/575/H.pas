program problem8;

const	md =	1000000007;

var	inv, fact, fact_inv: array[ 0..3000001 ] of int64;

function c( n, k: longInt ): longInt;
begin
	if ( k > n ) then
		exit( 0 );

	exit( ( fact[n] * ( ( fact_inv[k] * fact_inv[n - k] ) mod md ) ) mod md );
end;

var n, i: longInt;
	ans, sum: int64;

begin
	inv[1] := 1;
	for i := 2 to 3000001 do
		inv[i] := md - ( ( inv[md mod i] * ( md div i ) ) mod md );

	fact[0] := 1;
	fact_inv[0] := 1;
	for i := 1 to 3000001 do
	begin
		fact[i] := ( fact[i - 1] * i ) mod md;
		fact_inv[i] := ( fact_inv[i - 1] * inv[i] ) mod md;
	end;

	readln( n );
	
	sum := 1;
	ans := 1;
	for i := 1 to 2 * n do
	begin
		sum := ( 2 * sum ) mod md;
		if ( i > n ) then
		begin
			dec( sum, 2 * c( i - 1, n ) );
			while ( sum < 0 ) do
				inc( sum, md );
		end;
		
		inc( ans, sum );
		if ( ans >= md ) then
			dec( ans, md );
	end;
	
	writeln( ans );
end.