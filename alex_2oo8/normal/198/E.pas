program problem5;

const	maxDistance =	1000000001;

type	tListRec =	record
						id, next: longInt;
					end;
		tTreeRec =	record
						l, r, lSon, rSon, listHead: longInt;
					end;

var	m, p, r, d, realD, sorted: array[ 0..250000 ] of longInt;
	used: array[ 1..250000 ] of boolean;
	s: array[ 0..250000 ] of longInt;
	l: array[ 0..5000000 ] of tListRec;
	t: array[ 1..500000 ] of tTreeRec;
	lw, tw, n, w: longInt;
	
function list_next( prev, id: longInt ): longInt;
begin
	inc( lw );
	l[prev].next := lw;
	l[lw].id := id;
		
	exit( lw );
end;
	
function build_tree( ll, rr: longInt; init: boolean ): longInt;
var	i, j, k: longInt;
begin
	inc( tw );
	i := tw;
	
	t[i].l := ll;
	t[i].r := rr;
	if ( ll <> rr ) then
	begin
		t[i].lSon := build_tree( ll, (ll+rr) div 2, false );
		t[i].rSon := build_tree( (ll+rr) div 2 + 1, rr, false );
	end;
	
	if ( init ) then
	begin
		j := 1;
		
		for i := 1 to tw do
			if ( t[i].l = t[i].r ) and ( j <= n ) and ( d[ sorted[j] ] = t[i].l ) then
			begin
				t[i].listHead := list_next( 0, sorted[j] );
				
				inc( j );
				k := t[i].listHead;
				while ( j <= n ) and ( d[ sorted[j] ] = t[i].l ) do
				begin
					k := list_next( k, sorted[j] );
					inc( j );
				end;
			end;

		for i := tw downTo 1 do
			if ( t[i].l <> t[i].r ) and ( ( t[ t[i].lSon ].listHead <> 0 ) or ( t[ t[i].rSon ].listHead <> 0 ) ) then
			begin

				j := t[ t[i].lSon ].listHead;
				k := t[ t[i].rSon ].listHead;
				
				if ( j > 0 ) and ( ( k = 0 ) or ( m[ l[j].id ] < m[ l[k].id ] ) ) then
				begin
					t[i].listHead := list_next( 0, l[j].id );
					j := l[j].next;
				end
				else
				begin
					t[i].listHead := list_next( 0, l[k].id );
					k := l[k].next;
				end;
				
				ll := t[i].listHead;
				while ( j > 0 ) or ( k > 0 ) do
					if ( j > 0 ) and ( ( k = 0 ) or ( m[ l[j].id ] < m[ l[k].id ] ) ) then
					begin
						ll := list_next( ll, l[j].id );
						j := l[j].next;
					end
					else
					begin
						ll := list_next( ll, l[k].id );
						k := l[k].next;
					end;
			end;
	end;
	
	exit( i );
end;

procedure add( id: longInt );
begin
	if ( used[id] ) then
		exit();
		
	used[id] := true;
	s[w] := id;
	inc( w );
end;

procedure tree_add( s, r, maxM: longInt );
begin
	if ( t[s].r <= r ) then
	begin
		while ( t[s].listHead > 0 ) and ( m[ l[ t[s].listHead ].id ] <= maxM ) do
		begin
			add( l[ t[s].listHead ].id );
			t[s].listHead := l[ t[s].listHead ].next;
		end;
		
		exit();
	end;
	
	tree_add( t[s].lSon, r, maxM );
	if ( t[ t[s].rSon ].l <= r ) then
		tree_add( t[s].rSon, r, maxM );
end;

procedure qsort( l, r: longInt );
var	i, j, tmp, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := sorted[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( d[ sorted[i] ] < d[med] ) or ( ( d[ sorted[i] ] = d[med] ) and ( m[ sorted[i] ] < m[med] ) ) do
				inc( i );
			while ( d[ sorted[j] ] > d[med] ) or ( ( d[ sorted[j] ] = d[med] ) and ( m[ sorted[j] ] > m[med] ) ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp := sorted[i];
				sorted[i] := sorted[j];
				sorted[j] := tmp;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;
	
function getDistance( x, y: int64 ): longInt;
var	res, sq: int64;
begin
	sq := sqr(x) + sqr(y);
	res := trunc( sqrt( sq ) );
	while ( sqr(res) < sq ) do
		inc( res, 1 );
		
	if ( res > maxDistance ) then
		res := maxDistance;
		
	exit( res );
end;

function find( r, x: longInt ): longInt;
var	l, c: longInt;
begin
	l := 1;
	while ( l < r ) do
	begin
		c := (l+r+1) div 2;
		
		if ( realD[c] > x ) then
			r := c - 1
		else
			l := c;
	end;
	
	exit( l );
end;
	
var	xx, yy, x, y, z, i: longInt;

begin
	readln( xx, yy, p[0], r[0], n );
	for i := 1 to n do
	begin
		readln( x, y, m[i], p[i], r[i] );
		d[i] := getDistance( x - xx, y - yy );
		sorted[i] := i;
		used[i] := false;
	end;
	
	qsort( 1, n );
	
	z := 1;
	realD[1] := d[ sorted[1] ];
	for i := 1 to n do
	begin
		if ( d[ sorted[i] ] > realD[z] ) then
		begin
			inc( z );
			realD[z] := d[ sorted[i] ];
		end;
		
		d[ sorted[i] ] := z;
	end;
	
	build_tree( 1, z, true );
	i := 0;
	w := 1;
	s[0] := 0;
	while ( i < w ) do
	begin
		tree_add( 1, find( z, r[ s[i] ] ), p[ s[i] ] );
		
		inc( i );
	end;
	
	writeln( i - 1 );
end.