program problem2;

const	md =	1000000007;

var	rev: array[ 1..10 ] of longInt;

function pow( a, p: longInt ): longInt;
var	res: longInt;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * int64(a) ) mod md;
			
		a := ( a * int64(a) ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

function c( n, k: longInt ): longInt;
var	i: longInt;
	res: int64;
begin
	res := 1;
	for i := 1 to k do
		res := ( ( ( res * (n-i+1) ) mod md ) * rev[i] ) mod md;
		
	exit( res );
end;

var	i, j, k, l, ans, j1, k1, l1: longInt;
	cnt: array[ 0..10 ] of longInt;
	dp: array[ 1..10, 0..6, 0..10, -1..10 ] of int64;
	pow8: array[ 0..10 ] of longInt;
	m: ansistring;

begin
	fillchar( cnt, sizeOf(cnt), 0 );
	fillchar( dp, sizeOf(dp), 0 );
	
	for i := 1 to 10 do
		rev[i] := pow( i, ( md - 2 ) );
			
	pow8[0] := 1;
	for i := 1 to 9 do
		pow8[i] := pow8[i-1] * 8;

	readln( m );
	
	l := 0;
	for i := 1 to length( m ) do
	begin
		for j := 0 to ( ord( m[i] ) - ord( '0' ) - 1 ) do
			for k := 0 to ( length(m) - i ) do
				if ( j = 4 ) or ( j = 7 ) then
					inc( cnt[l+k+1], ( c( ( length(m) - i ), k ) * ( 1 shl k ) * pow8[ length(m) - i - k ] ) )
				else
					inc( cnt[l+k], ( c( ( length(m) - i ), k ) * ( 1 shl k ) * pow8[ length(m) - i - k ] ) );
					
		if ( m[i] = '4' ) or ( m[i] = '7' ) then
			inc( l );
	end;
	inc( cnt[l] );
	dec( cnt[0] );
{
	for i := 0 to 10 do
		writeln( i, ': ', cnt[i] );
}
	for i := 1 to 10 do
	begin
		dp[i][0][0][-1] := cnt[i];
		for j := 0 to 6 do
			for k := 0 to (i-1) do
				for l := 0 to 10 do
					for j1 := 0 to j do
						if ( k >= ( j1 * l ) ) then
							dp[i][j][k][l] := ( dp[i][j][k][l] + ( dp[i][j-j1][ k - (j1*l) ][l-1] * c( cnt[l], j1 ) ) ) mod md;
	end;
	
	ans := 0;
	for i := 1 to 10 do
		for k := 0 to (i-1) do
			ans := ( ans + dp[i][6][k][10] ) mod md;
			
	ans := ( ans * int64(720) ) mod md;
			
	writeln( ans );
end.