program problem2;
uses math;

var	sum: array[ 0..100001 ] of longInt;

function check( t, n: longInt; var s: longInt ): boolean;
var	p1, p2, i, l, r, c, p: longInt;
begin
	p1 := 0;
	p2 := 0;
	i := 0;
	while ( i < n ) do
	begin
		l := i + 1;
		r := n + 1;
		while ( l < r ) do
		begin
			c := ( l + r ) div 2;
			p := sum[c] - sum[i];
			if ( p >= t ) or ( c - i - p >= t ) then
				r := c
			else
				l := c + 1;
		end;
		
		if ( l = n ) then
		begin
			s := max( p1, p2 ) + 1;
			
			if ( sum[n] - sum[i] >= t ) then
				exit( p1 >= p2 )
			else
				exit( p2 >= p1 );
		end;
		
		if ( sum[l] - sum[i] >= t ) then
			inc( p1 )
		else
			inc( p2 );
		
		i := l;
	end;
	
	exit( false );
end;

var	n, i, j, a, k: longInt;
	s, t: array[ 1..100000 ] of longInt;

begin
	sum[0] := 0;

	readln( n );
	for i := 1 to n do
	begin
		read( a );
		
		sum[i] := sum[i - 1] + (a and 1);
	end;
	
	k := 0;
	for i := n downto 1 do
		if ( check( i, n, s[k + 1] ) ) then
		begin
			inc( k );
			t[k] := i;
		end;
	
	writeln( k );
	i := 0;
	while ( i < k ) do
	begin
		j := i + 1;
		while ( j < k ) and ( s[j + 1] = s[j] ) do
			inc( j );
		
		while ( j > i ) do
		begin
			writeln( s[j], ' ', t[j] );
			dec( j );
		end;
		
		j := i + 1;
		while ( j < k ) and ( s[j + 1] = s[j] ) do
			inc( j );
		
		i := j;
	end;
end.