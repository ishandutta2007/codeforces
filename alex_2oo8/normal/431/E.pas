program problem5;
uses math;

type	tTreapRec =	record
						lSon, rSon, sz, val, id, prior: longInt;
						sum: int64;
					end;

var	a: array[ 1..100000 ] of longInt;
	t: array[ 0..500000 ] of tTreapRec;
	tw: longInt = 0;
	
function newNode( id: longInt ): longInt;
begin
	inc( tw );
	t[tw].lSon := 0;
	t[tw].rSon := 0;
	t[tw].sz := 1;
	t[tw].val := a[id];
	t[tw].sum := a[id];
	t[tw].id := id;
	t[tw].prior := random(1000000000);
	
	exit( tw );
end;

function isLess( v1: int64; i1: longInt; v2: int64; i2: longInt ): boolean;
begin
	if ( v1 <> v2 ) then
		exit( v1 < v2 )
	else
		exit( i1 < i2 );
end;

procedure recalc( v: longInt );
begin
	t[v].sz :=  t[ t[v].lSon ].sz  + t[ t[v].rSon ].sz  + 1;
	t[v].sum := t[ t[v].lSon ].sum + t[ t[v].rSon ].sum + t[v].val;
end;

procedure split( root: longInt; val: int64; id: longInt; var l, r: longInt );
begin
	if ( root = 0 ) then
	begin
		l := 0;
		r := 0;
		
		exit();
	end;

	if ( isLess( t[root].val, t[root].id, val, id ) ) then
	begin
		split( t[root].rSon, val, id, t[root].rSon, r );
		
		l := root;
	end
	else
	begin
		split( t[root].lSon, val, id, l, t[root].lSon );
		
		r := root;
	end;
	
	recalc( root );
end;

function merge( l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( min(l, r) = 0 ) then
		exit( l + r );
		
	if ( t[l].prior < t[r].prior ) then
	begin
		res := l;
		t[l].rSon := merge( t[l].rSon, r );
	end
	else
	begin
		res := r;
		t[r].lSon := merge( l, t[r].lSon );
	end;
	
	recalc( res );
	
	exit( res );
end;

function insert( root, v: longInt ): longInt;
var	l, r: longInt;
begin
	split( root, t[v].val, t[v].id, l, r );
	
	exit( merge( merge( l, v ), r ) );
end;

function remove( root, p: longInt ): longInt;
var	l, r: longInt;
begin
	split( root, a[p], p, l, r );
	split( r   , a[p], p + 1, p, r );
	
	exit( merge(l, r) );
end;

procedure get( var root: longInt; p: int64; var cnt: longInt; var sum: int64 );
var	l, r: longInt;
begin
	split( root, p, 1000000000, l, r );
	
	cnt := t[l].sz;
	sum := t[l].sum;
	
	root := merge(l, r);
end;

function check( var root: longInt; p, v: int64 ): boolean;
var	cnt: longInt;
	sum: int64;
begin
	get( root, p, cnt, sum );

	exit( cnt >= (v + sum + p - 1) div p );
end;

var	n, q, i, p, x, root, tt, cnt: longInt;
	v, l, r, c, sum: int64;

begin
	readln( n, q );
	
	root := 0;
	for i := 1 to n do
	begin
		read( a[i] );
		
		root := insert( root, newNode(i) );
	end;
	
	for i := 1 to q do
	begin
		read( tt );
		if ( tt = 1 ) then
		begin
			readln( p, x );
			
			root := remove( root, p );
			
			a[p] := x;
			
			root := insert( root, newNode(p) );
		end
		else
		begin
			readln( v );
			
			l := 1;
			r := v + 1000000000;
			while ( l < r ) do
			begin
				c := ( l + r ) div 2;
				
				if ( check(root, c, v) ) then
					r := c
				else
					l := c + 1;
			end;

			get( root, l - 1, cnt, sum );
			
			writeln( ( (sum + v) / cnt ):0:15 );
		end;
	end;
end.