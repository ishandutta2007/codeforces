program problem2;

var	b, d, i, j, k, lenA, lenC, cycleStarts, pos, ans, cycleLen, cycleCnt: longInt;
	a, c: string[111];
	next, dist: array[ 1..111 ] of longInt;

begin
	fillchar( next, sizeOf(next), 0 );
	fillchar( dist, sizeOf(dist), 0 );

	readln( b, d );
	readln( a ); lenA := length(a);
	readln( c ); lenC := length(c);
	
	i := 1;
	while ( next[i] = 0 ) do
	begin
		j := 1;
		k := i;
		while ( j <= lenC ) do
		begin
			if ( a[k] = c[j] ) then
				inc( j );
				
			inc( dist[i] );
			inc( k );
			if ( k > lenA ) then
				k := 1;
				
			if ( dist[i] > 100000 ) then
			begin
				writeln( 0 );
				halt;
			end;
		end;
		
		next[i] := k;
		i := k;
	end;
	
	cycleStarts := i;
	
	ans := 0;
	pos := 1;
	i := 1;
	while ( i <> cycleStarts ) do
	begin
		if ( pos + dist[i] > lenA * b + 1 ) then
		begin
			writeln( ans div d );
			halt;
		end;
		
		inc( ans );
		inc( pos, dist[i] );
		i := next[i];
	end;
	
	cycleLen := dist[cycleStarts];
	cycleCnt := 1;
	i := next[cycleStarts];
	while ( i <> cycleStarts ) do
	begin
		inc( cycleLen, dist[i] );
		inc( cycleCnt, 1 );
		
		i := next[i];
	end;
	
	k := ( lenA * b + 1 - pos ) div cycleLen;
	
	inc( ans, k * cycleCnt );
	inc( pos, k * cycleLen );
	i := cycleStarts;
	while ( pos + dist[i] <= lenA * b + 1 ) do
	begin
		inc( ans );
		inc( pos, dist[i] );
		i := next[i];
	end;
	
	writeln( ans div d );
end.