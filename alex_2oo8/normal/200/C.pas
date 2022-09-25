program problem3;

type	tStr =		string[25];
		tGameRec =	record
						t1, t2: tStr;
						g1, g2: longInt;
					end;

var score, g1, g2, cnt: array[ 1..4 ] of longInt;
	name: array[ 1..4 ] of tStr;
	k: longInt;
	
procedure addComand( str: tStr );
var i: longInt;
begin
	for i := 1 to k do
		if ( name[i] = str ) then
			exit();
			
	inc( k );
	name[k] := str;
	g1[k] := 0;
	g2[k] := 0;
	cnt[k] := 0;
	score[k] := 0;
end;

function findComand( str: tStr ): longInt;
var i: longInt;
begin
	i := 1;
	while ( name[i] <> str ) do
		inc( i );
		
	exit( i );
end;

function getPlace( b: longInt ): longInt;
var i, res: longInt;
begin
	res := 1;
	for i := 1 to 4 do
		if ( i <> b ) and ( ( score[i] > score[b] ) or ( ( score[i] = score[b] ) and ( ( ( g1[i] - g2[i] ) > ( g1[b] - g2[b] ) ) or ( ( ( g1[i] - g2[i] ) = ( g1[b] - g2[b] ) ) and ( g1[i] > g1[b] ) or ( ( g1[i] = g1[b] ) and ( name[i] < name[b] ) ) ) ) ) ) then
			inc( res );
			
	exit( res );
end;

var i, j, a, b, ansX, ansY: longInt;
	str: string;
	games: array[ 1..5 ] of tGameRec;
	
begin
	k := 0;
	for i := 1 to 5 do
	begin
		readln( str );
		
		games[i].t1 := copy( str, 1, ( pos( ' ', str ) - 1 ) );
		delete( str, 1, pos( ' ', str ) );
		games[i].t2 := copy( str, 1, ( pos( ' ', str ) - 1 ) );
		delete( str, 1, pos( ' ', str ) );
		val( copy( str, 1, 1 ), games[i].g1 );
		val( copy( str, 3, 1 ), games[i].g2 );
		
		addComand( games[i].t1 );
		addComand( games[i].t2 );
	end;
	
	for i := 1 to 5 do
	begin
		j := findComand( games[i].t1 );
		k := findComand( games[i].t2 );
		
		inc( g1[j], games[i].g1 );
		inc( g2[j], games[i].g2 );
		
		inc( g1[k], games[i].g2 );
		inc( g2[k], games[i].g1 );
		
		inc( cnt[j] );
		inc( cnt[k] );
		
		if ( games[i].g1 > games[i].g2 ) then
			inc( score[j], 3 )
		else if ( games[i].g2 > games[i].g1 ) then
			inc( score[k], 3 )
		else
		begin
			inc( score[j], 1 );
			inc( score[k], 1 );
		end;
	end;
	
	b := findComand( 'BERLAND' );
	a := 1;
	while ( cnt[a] > 2 ) or ( a = b ) do
		inc( a );
		
	inc( score[b], 3 );
		
	ansX := 200;
	ansY := 0;
	for i := 1 to 200 do
		for j := 0 to (i-1) do
		begin
			inc( g1[b], i );
			inc( g2[b], j );
			
			inc( g1[a], j );
			inc( g2[a], i );
			
			if ( getPlace( b ) < 3 ) and ( ( (i-j) < (ansX-ansY) ) or ( ( (i-j) = (ansX-ansY) ) and ( j < ansY ) ) ) then
			begin
				ansX := i;
				ansY := j;
			end;
			
			dec( g1[b], i );
			dec( g2[b], j );
			
			dec( g1[a], j );
			dec( g2[a], i );
		end;
		
	if ( ansX = 200 ) and ( ansY = 0 ) then
		writeln( 'IMPOSSIBLE' )
	else
		writeln( ansX, ':', ansY );
end.