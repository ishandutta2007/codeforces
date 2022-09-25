program problemG;
uses math;

type	tTreapRec =	record
						y, c, lSon, rSon, max, sz: longInt;
					end;

var	t: array[ 1..100000 ] of tTreapRec;
	q: array[ 1..100000 ] of longInt;
	w: longInt;

function new( c: longInt ): longInt;
begin
	inc( w );
	t[w].c := c;
	t[w].y := random( 1000000000 );
	t[w].max := c;
	t[w].sz := 1;
	
	exit( w );
end;

procedure calcMax( s: longInt );
begin
	t[s].max := max( t[s].c, max( t[ t[s].lSon ].max, t[ t[s].rSon ].max ) );
end;

procedure calcSz( s: longInt );
begin
	t[s].sz := 1 + t[ t[s].lSon ].sz + t[ t[s].rSon ].sz;
end;

function merge( l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( min( l, r ) = 0 ) then
		exit( l + r );
		
	if ( t[l].y > t[r].y ) then
	begin
		t[l].rSon := merge( t[l].rSon, r );
		res := l;
	end
	else
	begin
		t[r].lSon := merge( l, t[r].lSon );
		res := r;
	end;
	
	calcMax( res );
	calcSz( res );
	exit( res );
end;

procedure split( s, k: longInt; var lt, rt: longInt );
begin
	lt := s;
	rt := s;
	if ( s = 0 ) then
		exit();
		
	if ( t[ t[s].lSon ].sz < k ) then
	begin
		split( t[s].rSon, k - 1 - t[ t[s].lSon ].sz, t[s].rSon, rt );
		lt := s;
	end
	else
	begin
		split( t[s].lSon, k, lt, t[s].lSon );
		rt := s;
	end;
	
	calcMax( s );
	calcSz( s );
end;

procedure add( var s: longInt; k, c: longInt );
var	l, r: longInt;
begin
	split( s, k - 1, l, r );
	s := merge( merge( l, new( c ) ), r );
end;

function find( s, c: longInt ): longInt; // find first greater than c
begin
	if ( t[ t[s].lSon ].max > c ) then
		exit( find( t[s].lSon, c ) )
	else if ( t[s].c > c ) then
		exit( t[ t[s].lSon ].sz + 1 )
	else
		exit( t[ t[s].lSon ].sz + 1 + find( t[s].rSon, c ) );
end;

procedure writeAns( s: longInt );
begin
	if ( s = 0 ) then
		exit();
		
	writeAns( t[s].rSon );
	write( q[ t[s].c ], ' ' );
	writeAns( t[s].lSon );
end;

var	s, n, i, k, a, c, maxA: longInt;

begin
	randSeed := 42;
	
	maxA := 0;
	s := 0;
	readln( n );
	for i := 1 to n do
	begin
		readln( a, c );
		if ( maxA > a ) then
			k := min( find( s, a ), c + 1 )
		else
		begin
			k := min( c + 1, i );
			maxA := a;
		end;
			
		add( s, k, a );
		q[a] := i;
	end;
	
	writeAns( s );
	writeln();
end.