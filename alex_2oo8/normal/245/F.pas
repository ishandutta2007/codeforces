program problem7;
const oneDay = 60 * 60 * 24;

var months: array[1..12] of longInt = ( 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 );

function time( str: ansistring ): qWord;
var month, day, h, m, s, i: longInt;
	res: qWord;
begin
	val( copy( str, 6, 2 ), month );
	val( copy( str, 9, 2 ), day );
	val( copy( str, 12, 2 ), h );
	val( copy( str, 15, 2 ), m );
	val( copy( str, 18, 2 ), s );
	
	res := oneDay * (day-1);
	for i := 1 to ( month - 1 ) do
		inc( res, ( oneDay * months[i] ) );
		
	res := res + ( ( ( ( 60 * h ) + m ) * 60 ) + s );
	
	time := res;
end;

var n, m, i, j: longInt;
	t: array[1..1000000] of qWord;
	str: ansistring;

begin
	readln( n, m );
	
	i := 0;
	j := 1;
	while ( not EOF() ) do
	begin
		inc( i );
		readln( str );
		str := copy( str, 1, 19 );
		
		t[i] := time( str );
		
		while ( (t[i]-t[j]) >= n ) do
			inc( j );
			
		if ( (i-j+1) = m ) then
		begin
			writeln( str );
			halt;
		end;
	end;
	
	writeln( '-1' );
end.