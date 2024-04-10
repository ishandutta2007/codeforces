program problem5;
uses math;

const	inf =	1000000005;

type	tArr =	array[ 0..200000 ] of longInt;
		tTreeRec =	record
						l, r, lSon, rSon, minVal, debtSum, cntSum: longInt;
					end;

var	b: tArr;
	t: array[ 1..9000000 ] of tTreeRec;
	tw: longInt = 0;
	h, len: longInt;

procedure qsort( var a: tArr; l, r: longInt );
var	i, j, tmp, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( a[i] > med ) do
				inc( i );
			while ( a[j] < med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp := a[i];
				a[i] := a[j];
				a[j] := tmp;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( a, l, j );
		qsort( a, i, r );
	end;
end;

function find( x: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 0;
	r := len;
	while ( l < r ) do
	begin
		c := ( l + r + 1 ) div 2;
		if ( b[c] + x >= h ) then
			l := c
		else
			r := c - 1;
	end;
	
	exit( l );
end;

function new( l, r: longInt ): longInt;
begin
	inc( tw );
	t[tw].l := l;
	t[tw].r := r;
	t[tw].lSon := 0;
	t[tw].rSon := 0;
	t[tw].minVal := inf;
	t[tw].debtSum := 0;
	t[tw].cntSum := 0;
	
	exit( tw );
end;

procedure processDebts( s: longInt );
begin
	if ( t[s].lSon = 0 ) then
		t[s].lSon := new( t[s].l, ( t[s].l + t[s].r ) div 2 );
		
	if ( t[s].rSon = 0 ) then
		t[s].rSon := new( ( t[s].l + t[s].r ) div 2 + 1, t[s].r );
		
	inc( t[ t[s].lSon ].debtSum, t[s].debtSum );
	inc( t[ t[s].rSon ].debtSum, t[s].debtSum );
	inc( t[ t[s].lSon ].minVal, t[s].debtSum );
	inc( t[ t[s].rSon ].minVal, t[s].debtSum );
	
	t[s].debtSum := 0;
end;

procedure t_increaseRange( s, l, r, d: longInt );
begin
	if ( t[s].l >= l ) and ( t[s].r <= r ) then
	begin
		inc( t[s].debtSum, d );
		inc( t[s].minVal, d );
		
		exit();
	end;
	
	processDebts( s );
	
	if ( t[ t[s].lSon ].r >= l ) then
		t_increaseRange( t[s].lSon, l, r, d );
	if ( t[ t[s].rSon ].l <= r ) then
		t_increaseRange( t[s].rSon, l, r, d );
		
	t[s].minVal := min( t[ t[s].lSon ].minVal, t[ t[s].rSon ].minVal );
end;

procedure t_decCnt( s, x: longInt );
begin
	dec( t[s].cntSum );

	if ( t[s].l = t[s].r ) then
	begin
		if ( t[s].cntSum = 0 ) then
			t[s].minVal := inf;
			
		exit();
	end;
	
	processDebts( s );
	
	if ( t[ t[s].lSon ].r >= x ) then
		t_decCnt( t[s].lSon, x )
	else
		t_decCnt( t[s].rSon, x );
		
	t[s].minVal := min( t[ t[s].lSon ].minVal, t[ t[s].rSon ].minVal );
end;

procedure t_incCnt( s, x, currPos: longInt );
begin
	inc( t[s].cntSum );
	
	if ( t[s].l = t[s].r ) then
	begin
		if ( t[s].cntSum = 1 ) then
			t[s].minVal := find( x ) - currPos - 1;
			
		exit();
	end;
	
	processDebts( s );
	
	if ( t[ t[s].lSon ].r >= x ) then
		t_incCnt( t[s].lSon, x, currPos )
	else
		t_incCnt( t[s].rSon, x, currPos + t[ t[s].lSon ].cntSum );
		
	t[s].minVal := min( t[ t[s].lSon ].minVal, t[ t[s].rSon ].minVal );
end;

procedure removeNumber( x: longInt );
begin
	t_increaseRange( 1, x, inf, +1 );
	t_decCnt( 1, x );
end;

procedure addNumber( x: longInt );
begin
	t_increaseRange( 1, x, inf, -1 );
	t_incCnt( 1, x, 0 );
end;

var	n, ans, i: longInt;
	a: tArr;

begin
	readln( n, len, h );
	for i := 1 to len do
		read( b[i] );
		
	for i := 1 to n do
		read( a[i] );
		
	b[0] := inf;
	qsort( b, 1, len );
	
	new( 1, inf );
	
	a[0] := 1;
	for i := 0 to len - 1 do
		addNumber( a[i] );
		
	ans := 0;
	for i := len to n do
	begin
		removeNumber( a[i-len] );
		addNumber( a[i] );
		
		if ( t[1].minVal >= 0 ) then
			inc( ans );
	end;
	
	writeln( ans );
end.