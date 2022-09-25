program problem3;

var	groups: array[ 0..20, 1..50, 0..50 ] of longInt;
	lastSeen, currCnt, groupId: array[ #0..#255 ] of longInt;
	f: array[ 0..1 shl 20 ] of extended;
	g: array[ 0..1 shl 20 ] of longInt;
	s: array[ 1..50 ] of string;
	m: longInt;
	
function calc( depth, groupCnt, mask, newSymbol: longInt ): extended;
const	iter: longInt = 0;

var	i, j, newGroupCnt: longInt;
	x: extended;
	c: char;
begin
	if ( g[mask] <> -1 ) then
		exit( f[mask] );

	if ( depth > 0 ) then
	begin
		newGroupCnt := 0;
		g[mask] := 0;
		
		for i := 1 to groupCnt do
		begin
			inc( iter );
			
			for j := 1 to groups[depth - 1][i][0] do
			begin
				c := s[ groups[depth - 1][i][j] ][newSymbol];
				if ( lastSeen[c]  < iter ) then
				begin
					lastSeen[c] := iter;
					currCnt[c] := 1;
					
					continue;
				end;
				
				inc( currCnt[c] );
				if ( currCnt[c] = 2 ) then
				begin
					inc( newGroupCnt );
					groupId[c] := newGroupCnt;
					groups[depth][newGroupCnt][0] := 0;
				end;
			end;
			
			for j := 1 to groups[depth - 1][i][0] do
			begin
				c := s[ groups[depth - 1][i][j] ][newSymbol];
				if ( currCnt[c] = 1 ) then				
					continue;
				
				inc( groups[depth][ groupId[c] ][0] );
				groups[depth][ groupId[c] ][ groups[depth][ groupId[c] ][0] ] := groups[depth - 1][i][j];
				
				inc( g[mask] );
			end;
		end;
	end
	else
		g[mask] := groups[0][1][0];
	
	f[mask] := 0.0;
	if ( newGroupCnt > 0 ) then
		for i := 1 to m do
			if ( not odd( mask shr (i - 1) ) ) then
			begin
				x := calc( depth + 1, newGroupCnt, mask or ( 1 shl (i - 1) ), i );
				f[mask] := f[mask] + ( x + (depth + 1) * ( g[mask] - g[ mask or ( 1 shl (i - 1) ) ] ) ) / (m - depth);
			end;
			
	exit( f[mask] );
end;

var	n, i: longInt;
	c: char;

begin
	readln( n );
	for i := 1 to n do
		readln( s[i] );
	
	m := length( s[1] );

	if ( n = 1 ) then
	begin
		writeln( 0 );
		
		halt;
	end;
	
	groups[0][1][0] := n;
	for i := 1 to n do
		groups[0][1][i] := i;
		
	for i := 0 to (1 shl m) - 1 do
		g[i] := -1;
		
	for c := #0 to #255 do
		lastSeen[c] := -1;
	
	writeln( ( calc( 0, 1, 0, -1 ) / n ):0:15 );
end.