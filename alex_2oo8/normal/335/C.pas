program problem3;

type	tField =	array[ 0..101, 1..2 ] of longInt;

var	g: array[ 1..100, 0..2, 0..2 ] of longInt;

function calculate( len, up, down: longInt ): longInt; forward;

function getSpragueGrundy( const f: tField; const r: longInt ): longInt;
var	res, i, j, up, down, len: longInt;
begin
	res := 0;
	
	i := 1;
	while ( i <= r ) do
	begin
		while ( i <= r ) and ( f[i][1] = 1 ) and ( f[i][2] = 1 ) do
			inc( i );

		if ( i > r ) then
			break;
			
		if ( f[i][1] = 0 ) and ( f[i][2] = 0 ) then
			up := 0
		else if ( f[i][1] = 1 ) then
			up := 1
		else
			up := 2;
			
		j := i + 1;
		while ( j <= r ) and ( ( f[j][1] = 0 ) or ( f[j][2] = 0 ) ) do
			inc( j );
			
		len := j - i;
		
		if ( f[j-1][1] = 0 ) and ( f[j-1][2] = 0 ) then
			down := 0
		else if ( f[j-1][1] = 1 ) then
			down := 1
		else
			down := 2;
			
		i := j;
		
		res := res xor calculate( len, up, down );
	end;
	
	exit( res );
end;

function calculate( len, up, down: longInt ): longInt;
var	f: tField;
	used: array[ 0..1000 ] of boolean;
	i, j: longInt;
begin
	if ( g[len][up][down] <> -1 ) then
		exit( g[len][up][down] );

	fillchar( f, sizeOf(f), 0 );
	fillchar( used, sizeOf(used), 0 );
	
	for i := 1 to len do
		for j := 1 to 2 do
		begin
			if ( up <> 0 ) then
				f[1][up] := 1;
				
			if ( down <> 0 ) then
				f[len][down] := 1;
				
			if ( f[i][j] = 1 ) then
				continue;
				
			f[i  ][j  ] := 1;
			f[i-1][3-j] := 1;
			f[i  ][3-j] := 1;
			f[i+1][3-j] := 1;
			
			used[ getSpragueGrundy( f, len ) ] := true;
			
			f[i  ][j  ] := 0;
			f[i-1][3-j] := 0;
			f[i  ][3-j] := 0;
			f[i+1][3-j] := 0;
		end;

	i := 0;
	while ( used[i] ) do
		inc( i );
		
	g[len][up][down] := i;
	
	exit( i );
end;

var	r, n, i, x, y: longInt;
	f: tField;

begin
	fillDWord( g, sizeOf(g) div sizeOf(g[1][0][0]), longWord(-1) );

	readln( r, n );
	for i := 1 to n do
	begin
		readln( x, y );
		
		f[x  ][  y] := 1;
		f[x-1][3-y] := 1;
		f[x  ][3-y] := 1;
		f[x+1][3-y] := 1;
	end;
	
	if ( getSpragueGrundy( f, r ) = 0 ) then
		writeln( 'LOSE' )
	else
		writeln( 'WIN' );
end.