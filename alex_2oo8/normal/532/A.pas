program problem1;
uses math;

const	inf: longInt =	1000000001;

type	tEdge =	record
					v, next: longInt;
				end;
		tArr =	array[ 1..1000000 ] of longInt;
		TreeElement = Record
			l, r: LongInt;
			lson, rson: LongInt;
			sum, minpsum: LongInt;
		End;

var	first, h, minH: array[ 1..1000000 ] of longInt;
	heights: tArr;
	e: array[ 1..1000000 ] of tEdge;
	n, k, ans: longInt;
	tW: LongInt = 1;
	t: Array[1..5000000] of TreeElement;

function TInit(const l, r: LongInt):LongInt;
begin
	TInit := tW;
	t[tW].l := l; t[tW].r := r;
	t[tW].lson := 0; t[tW].rson := 0;
	t[tW].sum := 0; t[tW].minpsum := 0;
	Inc(tW);
end;

procedure TAdd(const root, where, what: LongInt);
Var mid, lsonsum: LongInt;
begin
	Inc(t[root].sum, what);
	if t[root].l <> t[root].r then begin
		mid := (t[root].l + t[root].r) div 2;
		
		if where <= mid then begin
			if t[root].lson = 0 then
				t[root].lson := TInit(t[root].l, mid);
			TAdd(t[root].lson, where, what);
		end else begin
			if t[root].rson = 0 then
				t[root].rson := TInit(mid + 1, t[root].r);
			TAdd(t[root].rson, where, what);
		end;
		
		t[root].minpsum := 0;
		
		lsonsum := 0;
		if t[root].lson <> 0 then begin
			lsonsum := t[t[root].lson].sum;
			t[root].minpsum := t[t[root].lson].minpsum;
		end;
		
		if (t[root].rson <> 0) and (lsonsum + t[t[root].rson].minpsum < t[root].minpsum) then
			t[root].minpsum := lsonsum + t[t[root].rson].minpsum;
	end else begin
		t[root].minpsum := t[root].sum;
	end;
end;

Procedure QSort(var a: tArr; const l, r: LongInt);
Var i, j: LongInt;
    mid, tmp: LongInt;
Begin
	i := l;
	j := r;
	mid := a[i + Random(j - i + 1)];
	while i <= j do begin
		while a[i] > mid do Inc(i);
		while a[j] < mid do Dec(j);
		if i <= j then begin
			tmp := a[i];
			a[i] := a[j];
			a[j] := tmp;
			Inc(i);
			Dec(j);
		end;
	end;
	if l < j then QSort(a, l, j);
	if i < r then QSort(a, i, r);
End;

function binsearch( val: longInt ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 20 downto 0 do
		if ( res + (1 shl i) <= n + k ) and ( heights[res + 1 shl i] > val ) then
			inc( res, 1 shl i );
		
	exit( res + 1 );
end;

procedure add( v, where, what: longInt );
begin
	where := binsearch( where );
	
//	writeln( where, ' ', what );
	
	TAdd( 1, where, what );
end;

function get( v: longInt ): longInt;
begin
	exit( t[1].minpsum );
end;

procedure addEdge( u, v: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u];
	first[u] := ee;
end;

procedure dfs_precalc( v, p, mnH: longInt );
var	i: longInt;
begin
	minH[v] := mnH;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			dfs_precalc( e[i].v, v, min( mnH, h[ e[i].v ] ) );
		
		i := e[i].next;
	end;
end;

procedure dfs_recalc( v, p, hh, increase: longInt );
var	i: longInt;
begin
	add( 1, hh, +increase );
	add( 1, minH[v], -increase );

	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			dfs_recalc( e[i].v, v, min( hh, h[ e[i].v ] ), increase );
	
		i := e[i].next;
	end;
end;

procedure dfs_solve( v, p, hh: longInt );
var	i: longInt;
begin
	if ( h[v] < hh ) then
	begin
		dfs_recalc( v, p, hh, +1 );
		
		if ( get( 1 ) >= 0 ) then
			ans := min( ans, hh - h[v] );
		
		dfs_recalc( v, p, hh, -1 );
	
		exit();
	end;
	
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].v <> p ) then
			dfs_solve( e[i].v, v, hh );
	
		i := e[i].next;
	end;
end;

var	i, u, v: longInt;
	s: tArr;
	bufIn: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );

	readln( n );
	for i := 1 to n do
		read( h[i] );
		
	for i := 2 to n do
	begin
		readln( u, v );
		
		addEdge( u, v );
		addEdge( v, u );
	end;
	
	readln( k );
	for i := 1 to k do
		read( s[i] );
	
	for i := 1 to n do
		heights[i] := h[i];
	
	for i := 1 to k do
		heights[n + i] := s[i];
	
	qsort( heights, 1, n + k );
	
	dfs_precalc( 1, 0, h[1] );
	
	TInit( 1, n + k );
	
	for i := 1 to n do
		add( 1, minH[i], +1 );
	
	qsort( s, 1, k );
	
	i := 1;
	while ( i <= k ) do
	begin
		add( 1, s[i], -1 );
		
		if ( get( 1 ) < 0 ) then
			break;
	
		inc( i );
	end;
	
	if ( i > k ) then
	begin
		writeln( 0 );
		
		halt;
	end;
	
	v := i;
	for i := v + 1 to k do
		add( 1, s[i], -1 );
	
	ans := inf;
	
	dfs_solve( 1, 0, s[v] );
	
	if ( ans = inf ) then
		writeln( -1 )
	else
		writeln( ans );
end.