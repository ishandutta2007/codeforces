program problem3;

var	fwt: array[ 1..1000000 ] of int64;

procedure fwt_add( x, d: longInt );
begin
	while ( x <= 100000 ) do
	begin
		inc( fwt[x], d );
	
		inc( x, x and -x );
	end;
end;

function fwt_get( x: longInt ): int64;
var	res: int64;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
	
		dec( x, x and -x );
	end;
	
	exit( res );
end;

var	n, q, l, r, i, j, x, y, t: longInt;
	reversed: boolean;

begin
	readln( n, q );
	
	reversed := false;
	l := 1;
	r := n;
	for i := 1 to n do
		fwt_add( i, +1 );
	
	for i := 1 to q do
	begin
		read( t );
		if ( t = 1 ) then
		begin
			readln( x );
			
			if ( reversed ) then
				x := r - l + 1 - x;
			
			if ( x < r - l + 1 - x ) then
			begin
				reversed := false;
				
				inc( l, x );
				for j := 1 to x do
					fwt_add( l + j - 1, fwt_get(l - j) - fwt_get(l - j - 1) );
			end
			else
			begin
				x := r - l + 1 - x;
				reversed := true;
				
				dec( r, x );
				for j := 1 to x do
					fwt_add( r - j + 1, fwt_get(r + j) - fwt_get(r + j - 1) );
			end;
		end
		else
		begin
			readln( x, y );
			
			if ( reversed ) then
			begin
				x := r - l + 1 - x;
				y := r - l + 1 - y;
				
				x := x xor y;
				y := x xor y;
				x := x xor y;
			end;
				
			writeln( fwt_get(l + y - 1) - fwt_get(l + x - 1) );
		end;
	end;
end.