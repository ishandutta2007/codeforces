program problem1;

var	next, prev, ans, fwt: array[ 1..300001 ] of longInt;

procedure fwt_update( x, d: longInt );
begin
	while ( x <= 300000 ) do
	begin
		inc( fwt[x], d );
		inc( x, x and -x );
	end;
end;

function fwt_read( x: longInt ): longInt;
var	res: longInt;
begin
	res := 0;
	while ( x > 0 ) do
	begin
		inc( res, fwt[x] );
		dec( x, x and -x );
	end;
	
	exit( res );
end;

procedure setPrev( x, y: longInt );
begin
	prev[x] := y;
	next[y] := x;
end;

procedure delete( x: longInt );
begin
	setPrev( next[x], prev[x] );
	
	fwt_update( x, -1 );
end;

function firstAfter( x: longInt ): longInt;
var	l, r, c, p: longInt;
begin
	p := fwt_read( x - 1 );

	l := x;
	r := 300000;
	while ( l < r ) do
	begin
		c := ( l + r ) div 2;
		
		if ( fwt_read( c ) > p ) then
			r := c
		else
			l := c + 1;
	end;
	
	exit( l );
end;

var	n, m, i, j, l, r, x: longInt;

begin
	readln( n, m );
	
	for i := 1 to n + 1 do
		setPrev( i, i - 1 );
		
	for i := 1 to n do
		fwt_update( i, +1 );
		
	for i := 1 to m do
	begin
		readln( l, r, x );
		
		j := firstAfter( l );
		while ( j <= r ) do
		begin
			if ( j <> x ) then
			begin
				ans[j] := x;
				delete( j );
			end;
		
			j := next[j];
		end;
	end;
	
	for i := 1 to n do
		if ( ans[i] = i ) then
			write( 0, ' ' )
		else
			write( ans[i], ' ' );
			
	writeln();
end.