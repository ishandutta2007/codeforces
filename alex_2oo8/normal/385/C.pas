program problem3;
uses math;

procedure readInt( var n: longInt );
var	c: char;
begin	
	c := 'x';
	while ( c < '0' ) or ( c > '9' ) do
		read( c );

	n := 0;
	while ( c >= '0' ) and ( c <= '9' ) do
	begin
		n := (10 * n) + ord(c) - ord('0');
		read( c );
	end;
end;

var	n, i, j, x, pCnt, l, r: longInt;
	cnt, lp, primes: array[ 1..10000000 ] of longInt;
	buf: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, buf );

	pCnt := 0;
	for i := 2 to 10000000 do
	begin
		if ( lp[i] = 0 ) then
		begin
			inc( pCnt );
			primes[pCnt] := i;
			lp[i] := i;
		end;
		
		j := 1;
		while ( j <= pCnt ) and ( primes[j] <= lp[i] ) and ( i * primes[j] <= 10000000 ) do
		begin
			lp[ i * primes[j] ] := primes[j];

			inc( j );
		end;
	end;

	readInt( n );
	for i := 1 to n do
	begin
		readInt( x );
		inc( cnt[x] );
	end;
	
	for i := 10000000 downto 2 do
		if ( lp[i] <> i ) then
		begin
			j := i div lp[i];
		
			inc( cnt[j], cnt[i] );
			if ( j mod lp[i] <> 0 ) then
				inc( cnt[ lp[i] ], cnt[i] );
				
			cnt[i] := 0;
		end;
		
	for i := 3 to 10000000 do
		inc( cnt[i], cnt[i - 1] );
		
	readInt( n );
	for i := 1 to n do
	begin
		readInt( l );
		readInt( r );
		
		writeln( cnt[ min(10000000, r) ] - cnt[ min(10000000, l - 1) ] );
	end;
end.