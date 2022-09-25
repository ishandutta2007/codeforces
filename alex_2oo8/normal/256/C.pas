program problem3;

var	cnt: array[ 0..900000, 0..10 ] of longInt;

function getSpragueGrundyNumber( n: int64 ): longInt;
var	l, r, k: longInt;
begin
	r := trunc( sqrt(n) ) + 5;
	while ( r > sqrt(n) ) do
		dec( r );
		
	l := trunc( sqrt( sqrt(n) ) ) - 5;
	while ( l < sqrt( sqrt(n) ) ) do
		inc( l );
	
	k := 0;
	while ( r >= l ) and ( r < n ) and ( ( cnt[r][k] - cnt[l-1][k] ) > 0 ) do
		inc( k );
		
	exit( k );
end;

var	n, i, ans: longInt;
	a: int64;

begin
	fillchar( cnt, sizeOf(cnt), 0 );
	for i := 1 to 900000 do
	begin
		cnt[i] := cnt[i-1];
		inc( cnt[i][ getSpragueGrundyNumber(i) ] );
	end;
	
	readln( n );
	
	ans := 0;
	for i := 1 to n do
	begin
		read( a );
		ans := ans xor getSpragueGrundyNumber( a );
	end;
	
	if ( ans <> 0 ) then
		writeln( 'Furlo' )
	else
		writeln( 'Rublo' );
end.