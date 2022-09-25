program problem4;

type	tTreeNode =	record
						l, r, lSon, rSon: longInt;
						dp: array[ 0..59 ] of longInt;
					end;

var	t: array[ 1..300000 ] of tTreeNode;
	a: array[ 1..100000 ] of longInt;
	
procedure mergeAnswer( var res: tTreeNode; const l, r: tTreeNode );
var	i: longInt;
begin
	res.l := l.l;
	res.r := r.r;
	for i := 0 to 59 do
		res.dp[i] := l.dp[i] + r.dp[ ( i + l.dp[i] ) mod 60 ];
end;

function build_tree( l, r: longInt ): longInt;
const	tw: longInt = 0;
var	x, i: longInt;
begin
	inc( tw );
	x := tw;
	
	t[x].l := l;
	t[x].r := r;
	if ( l < r ) then
	begin
		t[x].lSon := build_tree( l, (l + r) div 2 );
		t[x].rSon := build_tree( (l + r) div 2 + 1, r );
		
		mergeAnswer( t[x], t[ t[x].lSon ], t[ t[x].rSon ] );
	end
	else
	begin
		for i := 0 to 59 do
			if ( i mod a[l] = 0 ) then
				t[x].dp[i] := 2
			else
				t[x].dp[i] := 1;
	end;
	
	exit( x );
end;

procedure update( v, x, c: longInt );
begin
	if ( t[v].l = t[v].r ) then
	begin
		for x := 0 to 59 do
			if ( x mod c = 0 ) then
				t[v].dp[x] := 2
			else
				t[v].dp[x] := 1;
		
		exit();
	end;
	
	if ( t[ t[v].lSon ].r >= x ) then
		update( t[v].lSon, x, c )
	else
		update( t[v].rSon, x, c );
	
	mergeAnswer( t[v], t[ t[v].lSon ], t[ t[v].rSon ] );
end;

function query( v, l, r: longInt ): tTreeNode;
var	res, resL, resR: tTreeNode;
begin
	if ( t[v].l = l ) and ( t[v].r = r ) then
		exit( t[v] );
	
	if ( t[ t[v].lSon ].r < l ) then
		exit( query( t[v].rSon, l, r ) )
	else if ( t[ t[v].rSon ].l > r ) then
		exit( query( t[v].lSon, l, r ) );
		
	resL := query( t[v].lSon, l, t[ t[v].lSon ].r );
	resR := query( t[v].rSon, t[ t[v].rSon ].l, r );
	
	mergeAnswer( res, resL, resR );
	
	exit( res );
end;

var	n, i, x, y: longInt;
	c: char;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	build_tree( 1, n );
	
	readln( n );
	for i := 1 to n do
	begin
		readln( c, x, y );
		
		if ( c = 'A' ) then
			writeln( query( 1, x, y - 1 ).dp[0] )
		else
			update( 1, x, y );
	end;
end.