program problem3;
uses math;

type	tTreapNode =	record
							l, r, c, lSon, rSon, prior: longInt;
						end;
		tTreeNode =	record
						l, r, lSon, rSon: longInt;
						debt, sum: int64;
					end;

var	n: longInt;
	treap: array[ 1..1000000 ] of tTreapNode;
	t: array[ 1..1000000 ] of tTreeNode;
	trw, tw, treap_root: longInt;
	
function build_tree( l, r: longInt ): longInt;
var	i: longInt;
begin
	inc( tw );
	i := tw;
	
	t[i].l := l;
	t[i].r := r;
	t[i].debt := 0;
	t[i].sum := 0;
	if ( l < r ) then
	begin
		t[i].lSon := build_tree( l, (l + r) div 2 );
		t[i].rSon := build_tree( (l + r) div 2 + 1, r );
	end;
	
	exit( i );
end;

procedure process_debts( v: longInt );
begin
	inc( t[ t[v].lSon ].sum , t[v].debt * ( t[ t[v].lSon ].r - t[ t[v].lSon ].l + 1 ) );
	inc( t[ t[v].lSon ].debt, t[v].debt );
	
	inc( t[ t[v].rSon ].sum , t[v].debt * ( t[ t[v].rSon ].r - t[ t[v].rSon ].l + 1 ) );
	inc( t[ t[v].rSon ].debt, t[v].debt );
	
	t[v].debt := 0;
end;

procedure tree_add( v, l, r, x: longInt );
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
	begin
		inc( t[v].sum, x * int64( t[v].r - t[v].l + 1 ) );
		inc( t[v].debt, x );
		
		exit();
	end;
	
	process_debts( v );
	
	if ( t[ t[v].lSon ].r >= l ) then
		tree_add( t[v].lSon, l, r, x );
	
	if ( t[ t[v].rSon ].l <= r ) then
		tree_add( t[v].rSon, l, r, x );
	
	t[v].sum := t[ t[v].lSon ].sum + t[ t[v].rSon ].sum;
end;

function getSum( v, l, r: longInt ): int64;
var	res: int64;
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
		exit( t[v].sum );
	
	process_debts( v );
	
	res := 0;
	if ( t[ t[v].lSon ].r >= l ) then
		inc( res, getSum( t[v].lSon, l, r ) );

	if ( t[ t[v].rSon ].l <= r ) then
		inc( res, getSum( t[v].rSon, l, r ) );
		
	exit( res );
end;

function newNode( l, r, c: longInt ): longInt;
begin
	inc( trw );
	treap[trw].l := l;
	treap[trw].r := r;
	treap[trw].c := c;
	treap[trw].prior := random(1000000000);
	treap[trw].lSon := 0;
	treap[trw].rSon := 0;
	
	exit( trw );
end;

function merge( l, r: longInt ): longInt;
begin
	if ( min(l, r) = 0 ) then
		exit( l + r );
	
	if ( treap[l].prior > treap[r].prior ) then
	begin
		treap[l].rSon := merge( treap[l].rSon, r );
		
		exit( l );
	end
	else
	begin
		treap[r].lSon := merge( l, treap[r].lSon );
		
		exit( r );
	end;
end;

procedure split( v, x: longInt; var l, r: longInt );
begin
	if ( v = 0 ) then
	begin
		l := 0;
		r := 0;
		
		exit();
	end;
	
	if ( treap[v].r < x ) then
	begin
		l := v;
		split( treap[v].rSon, x, treap[v].rSon, r );
	end
	else if ( treap[v].l >= x ) then
	begin
		r := v;
		split( treap[v].lSon, x, l, treap[v].lSon );
	end
	else
	begin
		l := merge( treap[v].lSon, newNode( treap[v].l, x - 1, treap[v].c ) );
		r := merge( newNode( x, treap[v].r, treap[v].c ), treap[v].rSon );
	end;
end;

procedure dfs( v, x: longInt );
begin
	if ( v = 0 ) then
		exit();
	
	tree_add( 1, treap[v].l, treap[v].r, abs( treap[v].c - x ) );
	
	dfs( treap[v].lSon, x );
	dfs( treap[v].rSon, x );
end;

procedure color( l, r, x: longInt );
var	ll, rr, cc: longInt;
begin
	split( treap_root, l, ll, rr );
	split( rr, r + 1, cc, rr );
	
	dfs( cc, x );
	
	treap_root := merge( ll, merge( newNode( l, r, x ), rr ) );
end;

var	m, i, l, r, x: longInt;

begin
	readln( n, m );
	
	build_tree( 1, n );
	
	treap_root := 0;
	for i := 1 to n do
		treap_root := merge( treap_root, newNode( i, i, i ) );
	
	for i := 1 to m do
	begin
		read( x );
		if ( x = 1 ) then
		begin
			readln( l, r, x );
			
			color( l, r, x );
		end
		else
		begin
			readln( l, r );
			
			writeln( getSum( 1, l, r ) );
		end;
	end;
end.