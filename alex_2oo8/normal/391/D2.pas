program problem4;
uses math;

const	inf =	1000000000;
		_queryEvent = 0;
		_addEvent = 1;
		_delEvent = 2;
		
type	tEvent =	record
						t, x, e: longInt;
					end;
		tTreeRec =	record
						l, r, lSon, rSon, val: longInt;
					end;

var	n, m, tw, ew: longInt;
	x0, y0, l0, x1, y1, l1: array[ 1..100000 ] of longInt;
	t: array[ 1..10000000 ] of tTreeRec;
	events: array[ 1..1000000 ] of tEvent;
	
procedure addEvent( x: extended; t, e: longInt );
begin
	inc( ew );
	events[ew].t := t;
	events[ew].x := round(2 * x);
	events[ew].e := e;
end;

procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tEvent;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := events[ l + random(r - l + 1) ].x;
		while ( i <= j ) do
		begin
			while ( events[i].x < med ) do
				inc( i );
			while ( events[j].x > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := events[i];
				events[i] := events[j];
				events[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;
	
function new( l, r: longInt ): longInt;
begin
	inc( tw );
	t[tw].l := l;
	t[tw].r := r;
	t[tw].val := -inf;
	
	exit( tw );
end;

procedure update( v, x, val: longInt );
var	c: longInt;
begin
	if ( t[v].l = t[v].r ) then
	begin
		t[v].val := val;
		exit();
	end;
	
	c := t[v].l + ( t[v].r - t[v].l ) div 2;
	
	if ( x <= c ) then
	begin
		if ( t[v].lSon = 0 ) then
			t[v].lSon := new( t[v].l, c );
		
		update( t[v].lSon, x, val );
	end
	else
	begin
		if ( t[v].rSon = 0 ) then
			t[v].rSon := new( c + 1, t[v].r );
			
		update( t[v].rSon, x, val );
	end;
	
	t[v].val := -inf;
	if ( t[v].lSon > 0 ) then
		t[v].val := max( t[v].val, t[ t[v].lSon ].val );

	if ( t[v].rSon > 0 ) then
		t[v].val := max( t[v].val, t[ t[v].rSon ].val );
end;

function get( v, l, r: longInt ): longInt;
var	res: longInt;
begin
	if ( t[v].l >= l ) and ( t[v].r <= r ) then
		exit( t[v].val );
	
	res := -inf;
	if ( t[v].lSon > 0 ) and ( t[ t[v].lSon ].r >= l ) then
		res := max( res, get( t[v].lSon, l, r ) );
	
	if ( t[v].rSon > 0 ) and ( t[ t[v].rSon ].l <= r ) then
		res := max( res, get( t[v].rSon, l, r ) );
	
	exit( res );
end;

function query( e: longInt ): longInt;
var	x, yl, yr, l, r, c: longInt;
begin
	x := x0[e];
	yl := y0[e];
	yr := y0[e] + l0[e];
	
	l := 0;
	r := l0[e] div 2;
	while ( l < r ) do
	begin
		c := ( l + r + 1 ) div 2;
		
		if ( get( 1, yl + c, yr - c ) - x >= c ) then
			l := c
		else
			r := c - 1;
	end;
	
	exit( l );
end;

function calc(): longInt;
var res, i: longInt;
begin
	fillchar( t, sizeOf(t), 0 );
	tw := 0;
	ew:= 0;

	new( -inf, inf );
	
	for i := 1 to n do
		addEvent( x0[i], _queryEvent, i );
	
	for i := 1 to m do
	begin
		addEvent( x1[i] + ( (l1[i] + 1) div 2 ) - 0.5, _addEvent, i );
		addEvent( x1[i] + l1[i] + 0.5, _delEvent, i );
	end;
	
	qsort( 1, ew );
	
	res := 0;
	for i := 1 to ew do
	begin
		if ( events[i].t = _queryEvent ) then
			res := max( res, query( events[i].e ) )
		else if ( events[i].t = _addEvent ) then
			update( 1, y1[ events[i].e ], x1[ events[i].e ] + l1[ events[i].e ] )
		else
			update( 1, y1[ events[i].e ], -inf );
	end;
	
	exit( res );
end;

var	i, ans: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( x0[i], y0[i], l0[i] );
	
	for i := 1 to m do
		readln( x1[i], y1[i], l1[i] );
	
	ans := calc();
	
	for i := 1 to n do
		x0[i] := -x0[i];
	
	for i := 1 to m do
		x1[i] := -x1[i] - l1[i];
		
	ans := max( ans, calc() );
	
	writeln( ans );
end.