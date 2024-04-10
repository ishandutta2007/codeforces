program problemD;
uses math;

var	good: array[ 0..1 shl 20 ] of longInt;
	cnt: array[ 1..20 ] of longInt;
	mask: longInt;
	
procedure add( x, d: longInt );
begin
	if ( cnt[x] = 0 ) then
		inc( mask, 1 shl (x-1) );
		
	inc( cnt[x], d );
	
	if ( cnt[x] = 0 ) then
		dec( mask, 1 shl (x-1) );
end;

function bitCnt( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, x and 1 );
		x := x shr 1;
	end;
	
	exit( res );
end;

function calc( m: longInt ): longInt;
var	i: longInt;
begin
	if ( good[m] = -1 ) then
	begin
		good[m] := 1;
		
		for i := 1 to 20 do
			if ( odd( m shr (i-1) ) ) then
				good[m] := good[m] and calc( m - ( 1 shl (i-1) ) );
	end;
	
	exit( good[m] );
end;

var	n, d, m, i, j, s, p, ans: longInt;
	a: array[ 0..100000 ] of longInt;

begin
	readln( n, m, d );
	for i := 1 to m do
	begin
		read( s );
		for j := 1 to s do
		begin
			read( p );
			
			a[p] := i;
		end;
	end;
	
	a[0] := 1;
	
	for i := 0 to (1 shl m) - 1 do
		good[i] := -1;
		
	mask := 0;
	for i := 0 to d - 1 do
		add( a[i], +1 );
		
	for i := d to n do
	begin
		add( a[i-d], -1 );
		add( a[i]  , +1 );
		
		good[mask] := 0;
	end;
	
	ans := 0;
	for i := 0 to (1 shl m) - 1 do
		if ( calc( i ) = 1 ) then
			ans := max( ans, bitCnt(i) );
			
	writeln( m - ans );
end.