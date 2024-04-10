program problem2;
uses math;

const days: array[ 1..12 ] of longInt = ( 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 );

function getDay( m, d: longInt ): longInt;
var res, i: longInt;
begin
	res := 370 + d;
	for i := 1 to (m-1) do
		inc( res, days[i] );
		
	exit( res );
end;

var n, m, d, p, t, i, j, k, ans: longInt;
	cnt: array[ 1..1000 ] of longInt;

begin
	assign( input, 'input.txt' );
	reset( input );
	assign( output, 'output.txt' );
	rewrite( output );
	
	fillchar( cnt, sizeOf(cnt), 0 );
	
	readln( n );
	for i := 1 to n do
	begin
		readln( m, d, p, t );
		
		k := getDay( m, d );
		for j := (k-t) to (k-1) do
			inc( cnt[j], p );
	end;
	
	ans := 0;
	for i := 1 to 1000 do
		ans := max( ans, cnt[i] );
		
	writeln( ans );
	
	close( input );
	close( output );
end.