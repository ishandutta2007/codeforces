program problem1;

var	n, i, cnt: longInt;
	a: array[ 1..200000 ] of longInt;
	ans: int64;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	cnt := 0;
	ans := 0;
	for i := n downto 1 do
		if ( a[i] = 1 ) then
			inc( ans, cnt )
		else
			inc( cnt );
			
	writeln( ans );
end.