program proiblem2;
uses math;

var	a: array[ 1..100000 ] of longInt;
	ans: int64;
	n: longInt;
	
function solve( v: longInt ): int64;
var	l, r: int64;
begin
	if ( v >= 1 shl n ) then
		exit( 0 );
	
	l := solve( 2 * v ) + a[2 * v];
	r := solve( 2 * v + 1 ) + a[2 * v + 1];
	
	inc( ans, abs(r - l) );
	
	exit( max( l, r ) );
end;

var	i: longInt;

begin
	readln( n );
	for i := 2 to (2 shl n) - 1 do
		read( a[i] );
	
	ans := 0;
	solve( 1 );
	
	writeln( ans );
end.