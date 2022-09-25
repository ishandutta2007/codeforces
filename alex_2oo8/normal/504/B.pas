program problem2;

var	fwt: array[ 1..200000 ] of longInt;

procedure fwt_upd( x, d: longInt );
begin
	while ( x <= 200000 ) do
	begin
		inc( fwt[x], d );
		inc( x, x and -x );
	end;
end;

function fwt_get( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
	
		dec( x, x and -x );
	end;
	
	exit( res );
end;

function fwt_getKth( k: longInt ): longInt;
var	res, i: longInt;
begin
	res := 0;
	for i := 17 downto 0 do
		if ( res + (1 shl i) <= 200000 ) and ( fwt[res + (1 shl i)] < k ) then
		begin
			dec( k, fwt[res + (1 shl i)] );
			inc( res, 1 shl i );
		end;
	
	exit( res + 1 );
end;

var	n, i: longInt;
	a, b, ans: array[ 1..200000 ] of longInt;
	inv: array[ 1..200000 ] of int64;

begin
	fillchar( inv, sizeOf(inv), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
		read( b[i] );
	
	for i := n downto 1 do
	begin
		inc( inv[i], fwt_get( a[i] ) );
		
		fwt_upd( a[i] + 1, +1 );
	end;
	
	fillchar( fwt, sizeOf(fwt), 0 );
	
	for i := n downto 1 do
	begin
		inc( inv[i], fwt_get( b[i] ) );
		
		fwt_upd( b[i] + 1, +1 );
	end;
	
	for i := 0 to n - 2 do
	begin
		inc( inv[n - i - 1], inv[n - i] div (i + 1) );
		inv[n - i] := inv[n - i] mod (i + 1);
	end;
	
	inv[1] := inv[1] mod n;
	
	fillchar( fwt, sizeOf(fwt), 0 );
	
	for i := 1 to n do
		fwt_upd( i, +1 );
	
	for i := 1 to n do
	begin
		ans[i] := fwt_getKth( inv[i] + 1 );
		
		fwt_upd( ans[i], -1 );
	end;
	
	for i := 1 to n do
		write( ans[i] - 1, ' ' );
	writeln();
end.