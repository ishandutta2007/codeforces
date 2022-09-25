program problem5;

type tNameStr = string[20];
	tRec =	record
				name: tNameStr;
				p: longInt;
			end;
	tEdge = record
				v, next: longInt;
			end;
	tQRec = record
				l, r, n: longInt;
			end;
			
var	names: array[ 1..100000 ] of tNameStr;
	first, firstL, level, vertex, lastChild, s, fwt, nextName, lastName: array[ 0..200000 ] of longInt;
	e: array[ 1..100000 ] of tEdge;
	qArr: array[ 1..100000 ] of tQRec;
	n, k: longInt;
	
procedure fwt_update( x, d: longInt );
begin
	while ( x <= n ) do
	begin
		inc( fwt[x], d );
		inc( x, (x and -x) );
	end;
end;

function fwt_read( x: longInt ): longInt;
var res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
		dec( x, (x and -x) );
	end;
	
	exit( res );
end;

procedure qsort( l, r: longInt );
var i, j: longInt;
	t, med: tNameStr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := names[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( names[i] < med ) do	
				inc( i );
			while ( names[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := names[i];
				names[i] := names[j];
				names[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

procedure qsortQ( l, r: longInt );
var i, j, med: longInt;
	t: tQRec;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := qArr[ l + random(r-l+1) ].l;
		while ( i <= j ) do
		begin
			while ( qArr[i].l < med ) do
				inc( i );
			while ( qArr[j].l > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := qArr[i];
				qArr[i] := qArr[j];
				qArr[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsortQ( l, j );
		qsortQ( i, r );
	end;
end;

procedure DFS( v, l: longInt );
var i: longInt;
begin
	vertex[v] := k;
	level[v] := l;
	inc( k );
	
	i := first[v];
	while ( i > 0 ) do
	begin
		DFS( e[i].v, (l+1) );
		i := e[i].next;
	end;
	
	lastChild[v] := k - 1;
end;

procedure find( v, sl, sr: longInt; var lRes, rRes: longInt );
var l, r, c: longInt;
begin
	if ( vertex[ s[sl] ] > lastChild[v] ) or ( vertex[ s[sr] ] < vertex[v] ) then
	begin
		lRes := 0;
		rRes := 0;
		exit();
	end;

	l := sl;
	r := sr;
	while ( l < r ) do
	begin
		c := (l+r) div 2;
		if ( vertex[ s[c] ] < vertex[v] ) then
			l := c + 1
		else
			r := c;
	end;
	
	lRes := l;
	
	l := sl;
	r := sr;
	while ( l < r ) do
	begin
		c := (l+r+1) div 2;
		if ( vertex[ s[c] ] > lastChild[v] ) then
			r := c - 1
		else
			l := c;
	end;
	
	rRes := l;
end;

function findName( str: tNameStr ): longInt;
var l, r, c: longInt;
begin
	l := 1;
	r := n;
	while ( l < r ) do
	begin
		c := (l+r) div 2;
		if ( names[c] < str ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

var m, l, r, v, i: longInt;
	a: array[ 1..100000 ] of tRec;
	ans: array[ 0..200000 ] of longInt;
	str: string;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( lastName, sizeOf(lastName), 0 );

	readln( n );
	for i := 1 to n do
	begin
		readln( str );
		a[i].name := copy( str, 1, ( pos( ' ', str ) - 1 ) );
		delete( str, 1, pos( ' ', str ) );
		val( str, a[i].p );
		
		e[i].v := i;
		e[i].next := first[ a[i].p ];
		first[ a[i].p ] := i;
				
		names[i] := a[i].name;
	end;
	
	qsort( 1, n );
	
	k := 0;
	DFS( 0, 0 );
	
	l := 0;
	r := 1;
	s[0] := 0;
	while ( l < r ) do
	begin	
		i := first[ s[l] ];
		while ( i > 0 ) do
		begin
			s[r] := e[i].v;
			inc( r );
			
			i := e[i].next;			
		end;
		
		inc( l );
	end;
	
	for i := n downTo 1 do
	begin
		nextName[i] := lastName[ findName( a[ s[i] ].name ) ];
		lastName[ findName( a[ s[i] ].name ) ] := i;
	end;
	
	fillchar( lastName, sizeOf(lastName), 0 );
	for i := 1 to n do
	begin
		if ( lastName[ findName( a[ s[i] ].name ) ] = 0 ) then
		begin
			lastName[ findName( a[ s[i] ].name ) ] := i;
			fwt_update( i, 1 );
		end;
	end;

	firstL[1] := 1;
	for i := 2 to n do
		if ( level[ s[i] ] > level[ s[i-1] ] ) then
			firstL[ level[ s[i] ] ] := i;
	firstL[ level[ s[n] ] + 1 ] := n + 1;

	readln( m );
	for i := 1 to m do
	begin
		readln( v, k );
		qArr[i].n := i;
		
		if ( ( level[v] + k ) > level[ s[n] ] ) then
		begin
			qArr[i].l := 0;
			qArr[i].r := 0;
		end
		else
			find( v, firstL[ level[v] + k ], (firstL[ level[v] + k + 1 ] - 1), qArr[i].l, qArr[i].r );
	end;
	
	qsortQ( 1, m );
	
	l := 1;
	for i := 1 to m do
	begin
		while ( l < qArr[i].l ) do
		begin
			fwt_update( l, -1 );
			if ( nextName[l] > 0 ) then
				fwt_update( nextName[l], 1 );
				
			inc( l );
		end;
		
		ans[ qArr[i].n ] := fwt_read( qArr[i].r );
	end;
	
	for i := 1 to m do
		writeln( ans[i] );
end.