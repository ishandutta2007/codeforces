program problem4;
uses math;

type	tTreeNode =	record
						lSon, rSon: longInt;
						minVal: int64;
					end;

var	t: array[ 1..2000000 ] of tTreeNode;

function build_tree( sz: longInt ): longInt;
const	tw: longInt = 0;
var	i: longInt;
begin
	inc( tw );
	i := tw;
	
	if ( sz > 1 ) then
	begin
		t[i].lSon := build_tree( sz div 2 );
		t[i].rSon := build_tree( ( sz + 1 ) div 2 );
	end;
	
	exit( i );
end;

function update( v, s, m: longInt ): int64;
var	res: int64;
begin
	if ( t[v].lSon = 0 ) then
	begin
		t[v].minVal := max( t[v].minVal, s ) + m;
		
		exit( t[v].minVal );
	end;
	
	if ( t[ t[v].lSon ].minVal = t[v].minVal ) then
		res := update( t[v].lSon, s, m )
	else
		res := update( t[v].rSon, s, m );
	
	t[v].minVal := min( t[ t[v].lSon ].minVal, t[ t[v].rSon ].minVal );
	
	exit( res );
end;

var	n, k, i, s, m: longInt;

begin
	readln( n, k );
	
	build_tree( k );
	
	for i := 1 to n do
	begin
		readln( s, m );
		
		writeln( update( 1, s, m ) );
	end;
end.