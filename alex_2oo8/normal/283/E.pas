program problem5;
uses math;

type	tEvent =	record
						l, r, next: longInt;
					end;
		tTreeRec =	record
						l, r, lSon, rSon: longInt;
						cnt: array[ 0..1 ] of longInt;
						hasDebt: boolean;
					end;

var	s: array[ 0..100001 ] of longInt;
	t: array[ 1..200000 ] of tTreeRec;
	tw: longInt;

procedure qsort( l, r: longInt );
var	i, j, tmp, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := s[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( s[i] < med ) do
				inc( i );
			while ( s[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp := s[i];
				s[i] := s[j];
				s[j] := tmp;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function find( x, l, r: longInt ): longInt;
var	c: longInt;
begin
	while ( l < r ) do
	begin
		c := (l+r) div 2;
		
		if ( s[c] < x ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

function build_tree( l, r: longInt ): longInt;
var	i: longInt;
begin
	inc( tw );
	
	i := tw;
	t[i].l := l;
	t[i].r := r;
	t[i].cnt[0] := r - l + 1;
	t[i].cnt[1] := 0;
	if ( l <> r ) then
	begin
		t[i].lSon := build_tree( l, (l+r) div 2 );
		t[i].rSon := build_tree( (l+r) div 2 + 1, r );
	end;
	
	exit( i );
end;

procedure doChange( s: longInt );
begin
	t[s].hasDebt := not t[s].hasDebt;
	t[s].cnt[0] := t[s].cnt[1];
	t[s].cnt[1] := t[s].r - t[s].l + 1 - t[s].cnt[0];
end;

procedure change( s, l, r: longInt );
begin
	if ( t[s].l >= l ) and ( t[s].r <= r ) then
	begin
		doChange( s );
		
		exit();
	end;
	
	if ( t[s].hasDebt ) then
	begin
		t[s].hasDebt := false;
		
		doChange( t[s].lSon );
		doChange( t[s].rSon );
	end;
	
	if ( t[ t[s].lSon ].r >= l ) then
		change( t[s].lSon, l, r );
		
	if ( t[ t[s].rSon ].l <= r ) then
		change( t[s].rSon, l, r );
		
	t[s].cnt[0] := t[ t[s].lSon ].cnt[0] + t[ t[s].rSon ].cnt[0];
	t[s].cnt[1] := t[ t[s].lSon ].cnt[1] + t[ t[s].rSon ].cnt[1];
end;

var	n, m, i, j, a, b: longInt;
	events: array[ 1..200000 ] of tEvent;
	first: array[ 0..100001 ] of longInt;
	ans, win: int64;

begin
	fillchar( first, sizeOf(first), 0 );

	readln( n, m );
	for i := 1 to n do
		read( s[i] );
		
	qsort( 1, n );
	s[0] := -1;
	s[n+1] := 1000000001;
	
	for i := 1 to m do
	begin
		readln( a, b );
		
		a := find( a, 0, n + 1 );
		b := find( b + 1, 0, n + 1 ) - 1;
		
		if ( a < b ) then
		begin
			events[i].l := a;
			events[i].r := b;
			events[i].next := first[a];
			first[a] := i;
			
			events[m+i].l := a;
			events[m+i].r := b;
			events[m+i].next := first[b+1];
			first[b+1] := m + i;
		end;
	end;
	
	build_tree( 1, n );
	
	ans := ( n * int64(n-1) * (n-2) ) div 6;
	for i := 1 to n do
	begin
		j := first[i];
		while ( j > 0 ) do
		begin
			change( 1, events[j].l, events[j].r );
			j := events[j].next;
		end;
	
		win := t[1].cnt[1];
		change( 1, i, i );
		win := min( win, t[1].cnt[1] );
		
		dec( ans, ( win * ( win - 1 ) ) div 2 );
	end;
	
	writeln( ans );
end.