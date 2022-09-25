program problem4;
uses math;

var	vis: array[ 1..100000 ] of boolean;
	cycles: array[ 2..3, 1..100000, 1..3 ] of longInt;
	ansArr: array[ 1..100000, 0..10 ] of longInt;
	cycleCnt: array[ 2..3 ] of longInt;
	ans: longInt;
	a, currCycle: array[ 1..100000 ] of longInt;
	
procedure findCycle( v: longInt );
var	sz, i: longInt;
begin
	vis[v] := true;

	sz := 1;
	currCycle[1] := v;
	v := a[v];
	while ( v <> currCycle[1] ) do
	begin
		vis[v] := true;
	
		inc( sz );
		currCycle[sz] := v;
		
		v := a[v];
	end;
	
	while ( sz >= 5 ) do
	begin
		inc( ans );
		ansArr[ans][0] := 5;
		
		for i := 1 to 5 do
			ansArr[ans][i]   := currCycle[sz-5+i];
			
		ansArr[ans][10] := currCycle[sz-4];
		for i := 1 to 4 do
			ansArr[ans][5+i] := currCycle[sz-4+i];
			
		dec( sz, 4 );
	end;
	
	if ( sz = 4 ) then
	begin
		inc( ans );
		ansArr[ans][0] := 4;
		
		for i := 1 to 4 do
			ansArr[ans][i]   := currCycle[sz-4+i];
			
		ansArr[ans][9] := currCycle[sz-3];
		for i := 1 to 3 do
			ansArr[ans][5+i] := currCycle[sz-3+i];
			
		exit();
	end;
	
	if ( sz < 2 ) then
		exit();
	
	inc( cycleCnt[sz] );
	for i := 1 to sz do
		cycles[sz][ cycleCnt[sz] ][i] := currCycle[i];
end;

var	n, i, j, l, i2, i3: longInt;

begin
	fillchar( vis, sizeOf(vis), 0 );
	fillchar( cycleCnt, sizeOf(cycleCnt), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	ans := 0;
	for i := 1 to n do
		if ( not vis[i] ) and ( a[i] <> i ) then
			findCycle( i );
			
	i2 := 1;
	i3 := 1;
	while ( i2 <= cycleCnt[2] ) or ( i3 <= cycleCnt[3] ) do
	begin
		inc( ans );
		ansArr[ans][0] := 0;
		
		if ( cycleCnt[2] >= i2 ) then
		begin
			inc( ansArr[ans][0], 2 );
			ansArr[ans][1] := cycles[2][i2][1];
			ansArr[ans][2] := cycles[2][i2][2];
			ansArr[ans][6] := cycles[2][i2][2];
			ansArr[ans][7] := cycles[2][i2][1];
			
			inc( i2 );
		end;
		
		l := ansArr[ans][0];
		if ( cycleCnt[3] >= i3 ) then
		begin
			inc( ansArr[ans][0], 3 );
			ansArr[ans][l+1] := cycles[3][i3][1];
			ansArr[ans][l+2] := cycles[3][i3][2];
			ansArr[ans][l+3] := cycles[3][i3][3];
			ansArr[ans][l+6] := cycles[3][i3][2];
			ansArr[ans][l+7] := cycles[3][i3][3];
			ansArr[ans][l+8] := cycles[3][i3][1];
			
			inc( i3 );
		end
		else if ( cycleCnt[2] >= i2 ) then
		begin
			inc( ansArr[ans][0], 2 );
			ansArr[ans][l+1] := cycles[2][i2][1];
			ansArr[ans][l+2] := cycles[2][i2][2];
			ansArr[ans][l+6] := cycles[2][i2][2];
			ansArr[ans][l+7] := cycles[2][i2][1];
			
			inc( i2 );
		end;
		
		l := ansArr[ans][0];
		if ( l = 3 ) and ( cycleCnt[3] >= i3 ) then
		begin
			inc( ansArr[ans][0], 2 );
			ansArr[ans][l+1] := cycles[3][i3][2];
			ansArr[ans][l+2] := cycles[3][i3][3];
			ansArr[ans][l+6] := cycles[3][i3][3];
			ansArr[ans][l+7] := cycles[3][i3][2];
			
			inc( cycleCnt[2] );
			cycles[2][ cycleCnt[2] ][1] := cycles[3][i3][1];
			cycles[2][ cycleCnt[2] ][2] := cycles[3][i3][2];
			
			inc( i3 );
		end;
	end;
	
	writeln( ans );
	for i := 1 to ans do
	begin
		writeln( ansArr[i][0] );
		for j := 1 to ansArr[i][0] do
			write( ansArr[i][j], ' ' );
		writeln();
		
		for j := 1 to ansArr[i][0] do
			write( ansArr[i][5+j], ' ' );
		writeln();
	end;
end.