program problem2;
uses math;

var	fwt: array[ 1..100000 ] of longInt;
	n: longInt;

procedure fwt_update( x, v: longInt );
begin
	while ( x <= n ) do
	begin
		fwt[x] := max( fwt[x], v );
		inc( x, x and -x );
	end;
end;

function fwt_read( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		res := max( res, fwt[x] );
		dec( x, x and -x );
	end;
	
	exit( res );
end;

var	i, a: longInt;

begin
	readln( n );
	
	for i := 1 to n do
	begin
		read( a );
		
		fwt_update( a, fwt_read( a ) + 1 );
	end;
	
	writeln( fwt_read( n ) );
end.