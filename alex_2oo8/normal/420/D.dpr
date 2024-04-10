program problem4;
uses math;

type	tTreapRec =	record
					lSon, rSon, size, prior, pos, val: longInt;
				end;

var	t: array[ 0..1000000 ] of tTreapRec;
	tw: longInt = 0;

function newNode( p, v: longInt ): longInt;
begin
	inc( tw );
	t[tw].pos := p;
	t[tw].val := v;
	t[tw].size := 1;
	t[tw].prior := random(1000000000);
	t[tw].lSon := 0;
	t[tw].rSon := 0;
	
	newNode := tw;
end;

procedure recalc( v: longInt );
begin
	t[v].size := t[ t[v].lSon ].size + t[ t[v].rSon ].size + 1;
end;

function merge( l, r: longInt ): longInt;
begin
	if ( min(l, r) = 0 ) then
	begin
		merge := l + r;
		exit;
	end;
	
	if ( t[l].prior > t[r].prior ) then
	begin
		t[l].rSon := merge( t[l].rSon, r );
		recalc( l );
		
		merge := l;
	end
	else
	begin
		t[r].lSon := merge( l, t[r].lSon );
		recalc( r );
		
		merge := r;
	end;
end;

procedure split( v, k: longInt; var l, r: longInt );
begin
	if ( v = 0 ) then
	begin
		l := 0;
		r := 0;
		
		exit;
	end;
	
	if ( t[ t[v].lSon ].size >= k ) then
	begin
		split( t[v].lSon, k, l, t[v].lSon );
		recalc( v );
		
		r := v;
	end
	else
	begin
		split( t[v].rSon, k - t[ t[v].lSon ].size - 1, t[v].rSon, r );
		recalc( v );
		
		l := v;
	end;
end;

function remove( var v: longInt; k: longInt ): longInt;
var	a, b, c: longInt;
begin
	split( v, k - 1, a, v );
	split( v, 1, b, c );
	
	v := merge( a, c );
	
	remove := b;
end;

var	n, m, i, root, x, y: longInt;
	a: array[ 1..1000000 ] of longInt;
	used: array[ 1..1000000 ] of boolean;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );

	readln( n, m );
	
	root := 0;
	for i := 1 to n do
		root := merge( root, newNode( i, -1 ) );
	
	for i := 1 to m do
	begin
		readln( x, y );
		
		y := remove( root, y );
		
		if ( t[y].val = -1 ) or ( t[y].val = x ) then
			t[y].val := x
		else
		begin
			writeln( -1 );
			halt;
		end;
		
		root := merge( y, root );
	end;

	fillchar( used, sizeOf(used), false );
	for i := 1 to n do
	begin
		if ( t[i].val > -1 ) and ( used[ t[i].val ] ) then
		begin
			writeln( -1 );
			halt;
		end;
		
		if ( t[i].val > -1 ) then
			used[ t[i].val ] := true;

		a[ t[i].pos ] := t[i].val;
	end;
	
	x := 1;
	for i := 1 to n do
		if ( a[i] = -1 ) then
		begin
			while ( used[x] ) do
				inc( x );
			
			a[i] := x;
			inc( x );
		end;
		
	for i := 1 to n do
		write( a[i], ' ' );
	
	writeln;
end.