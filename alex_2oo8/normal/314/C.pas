program problem3;

const	md =	1000000007;

type	tTreeRec =	record
						l, r, lSon, rSon, sum: longInt;
					end;

var	t: array[ 1..5000000 ] of tTreeRec;
	tw: longInt;
					
function new( l, r: longInt ): longInt;
var	res: longInt;
begin
	inc( tw );
	res := tw;
	
	t[res].l := l;
	t[res].r := r;
	t[res].sum := 0;
	
	if ( l <> r ) then
	begin
		t[res].lSon := new( l, ( l + r ) div 2 );
		t[res].rSon := new( ( l + r ) div 2 + 1, r );
	end;
	
	exit( res );
end;

procedure update( s, x, val: longInt );
begin
	if ( t[s].l = t[s].r ) then
	begin
		t[s].sum := val;
		
		exit();
	end;
	
	if ( t[ t[s].lSon ].r >= x ) then
		update( t[s].lSon, x, val )
	else
		update( t[s].rSon, x, val );
		
	t[s].sum := ( t[ t[s].lSon ].sum + t[ t[s].rSon ].sum ) mod md;
end;

function read_tree( s, r: longInt ): longInt;
var	res: longInt;
begin
	if ( t[s].r <= r ) then
		exit( t[s].sum );
		
	res := read_tree( t[s].lSon, r );
	if ( t[ t[s].rSon ].l <= r ) then
		res := ( res + read_tree( t[s].rSon, r ) ) mod md;
		
	exit( res );
end;

var	n, i, a: longInt;

begin
	new( 0, 1000000 );
	update( 1, 0, 1 );

	readln( n );
	for i := 1 to n do
	begin
		read( a );
		
		update( 1, a, ( int64(a) * read_tree( 1, a ) ) mod md );
	end;
	
	writeln( read_tree( 1, 1000000 ) - 1 );
end.