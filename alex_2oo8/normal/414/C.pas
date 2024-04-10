program problem3;

var	a: array[ 1..1 shl 20 ] of longInt;
	ll, rr: array[ 0..20 ] of int64;
	s: array[ 1..100000000 ] of longInt;
	w: longInt = 0;
	
procedure swap( var a, b: int64 );
var	c: int64;
begin
	c := a;
	a := b;
	b := c;
end;
	
function calc( l1, r1, l2, r2: longInt ): int64;
var	i, j: longInt;
	res: int64;
begin
	res := 0;
	
	j := l2 - 1;
	for i := l1 to r1 do
	begin
		while ( j < r2 ) and ( s[j + 1] < s[i] ) do
			inc( j );
		
		inc( res, j - l2 + 1 );
	end;
	
	exit( res );
end;
	
procedure add( x: longInt );
begin
	inc( w );
	s[w] := x;
end;
	
procedure prepare( f, p: longInt; var l, r: longInt );
var	l1, r1, l2, r2: longInt;
begin
	if ( p = 0 ) then
	begin
		l := w + 1;
		add( a[f] );
		r := w;
		
		exit();
	end;
	
	prepare( f, p - 1, l1, r1 );
	prepare( f + ( 1 shl (p - 1) ), p - 1, l2, r2 );
	
	inc( ll[p], calc( l1, r1, l2, r2 ) );
	inc( rr[p], calc( l2, r2, l1, r1 ) );
	
	l := w + 1;
	while ( l1 <= r1 ) and ( l2 <= r2 ) do
	begin
		if ( s[l1] < s[l2] ) then
		begin
			add( s[l1] );
			inc( l1 );
		end
		else
		begin
			add( s[l2] );
			inc( l2 );
		end;
	end;
	
	while ( l1 <= r1 ) do
	begin
		add( s[l1] );
		inc( l1 );
	end;
	
	while ( l2 <= r2 ) do
	begin
		add( s[l2] );
		inc( l2 );
	end;
	
	r := w;
end;

var	n, m, i, j, q, l, r: longInt;
	ans: int64;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );

	fillchar( ll, sizeOf(ll), 0 );
	fillchar( rr, sizeOf(rr), 0 );

	readln( n );
	for i := 1 to (1 shl n) do
		read( a[i] );
	
	prepare( 1, n, l, r );
	
	readln( m );
	for i := 1 to m do
	begin
		read( q );
		
		for j := 0 to q do
			swap( ll[j], rr[j] );
		
		ans := 0;
		for j := 0 to n do
			inc( ans, ll[j] );
		
		writeln( ans );
	end;
end.