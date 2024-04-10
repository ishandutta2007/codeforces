{$R-,S-,Q-,I-,U-}
program problem4;
uses math;

type	tTreeRec =	record
						l, r, lSon, rSon, maxFull, maxEmpty: longInt;
					end;
		tEdge =	record
					v, next: longInt;
				end;
				
var	first, index, lastChild: array[ 1..500000 ] of longInt;
	e: array[ 1..1000000 ] of tEdge;
	ee, x, tw: longInt;
	t: array[ 1..1000000 ] of tTreeRec;
	
function build_tree( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	if ( l < r ) then
	begin
		t[res].lSon := build_tree( l, ( l + r ) div 2 );
		t[res].rSon := build_tree( ( l + r ) div 2 + 1, r );
	end;
	
	exit( res );
end;

procedure addFull( s, l, r, val: longInt );
begin
	if ( t[s].l >= l ) and ( t[s].r <= r ) then
	begin
		t[s].maxFull := val;
		exit();
	end;
	
	if ( t[ t[s].lSon ].r >= l ) then
		addFull( t[s].lSon, l, r, val );
		
	if ( t[ t[s].rSon ].l <= r ) then
		addFull( t[s].rSon, l, r, val );
end;

procedure addEmpty( s, x, val: longInt );
begin
	t[s].maxEmpty := val;
	while ( t[s].l <> t[s].r ) do
	begin
		if ( t[ t[s].lSon ].r >= x ) then
			s := t[s].lSon
		else
			s := t[s].rSon;
			
		t[s].maxEmpty := val;
	end;
end;

function getFull( s, x: longInt ): longInt;
var	res: longInt;
begin
	res := t[s].maxFull;
	while ( t[s].l <> t[s].r ) do
	begin
		if ( t[ t[s].lSon ].r >= x ) then
			s := t[s].lSon
		else
			s := t[s].rSon;
			
		res := max( res, t[s].maxFull );
	end;
	
	exit( res );
end;

function getEmpty( s, l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( t[s].l >= l ) and ( t[s].r <= r ) then
		exit( t[s].maxEmpty );
		
	res := 0;
	if ( t[ t[s].lSon ].r >= l ) then
		res := max( res, getEmpty( t[s].lSon, l, r ) );
		
	if ( t[ t[s].rSon ].l <= r ) then
		res := max( res, getEmpty( t[s].rSon, l, r ) );
		
	exit( res );
end;
	
procedure addEdge( u, v: longInt );
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure DFS( v, p: longInt );
var	i: longInt;
begin
	inc( x );
	index[v] := x;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			DFS( e[i].v, v );
			
		i := e[i].next;
	end;
	
	lastChild[v] := x;
end;

var	n, q, i, u, v: longInt;

begin
	readln( n );
	for i := 1 to n - 1 do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	DFS( 1, 0 );
	
	build_tree( 1, n );
	
	readln( q );
	for i := 1 to q do
	begin
		readln( u, v );
		
		if ( u = 1 ) then
			addFull( 1, index[v], lastChild[v], i )
		else if ( u = 2 ) then
			addEmpty( 1, index[v], i )
		else
		begin
			u := getFull( 1, index[v] );
			v := getEmpty( 1, index[v], lastChild[v] );
			
			if ( u > v ) then
				writeln( 1 )
			else
				writeln( 0 );
		end;
	end;
end.