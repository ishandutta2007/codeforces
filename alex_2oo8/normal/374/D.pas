program problem4;

var	fwt, next, prev, val, a: array[ 0..2000000 ] of longInt;
	len, last: longInt;

procedure fwt_update( x, d: longInt );
begin
	while ( x <= 2000000 ) do
	begin
		inc( fwt[x], d );
		inc( x, x and -x );
	end;
end;

function fwt_getKth( k: longInt ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 20 downTo 0 do
		if ( fwt[ res + (1 shl i) ] < k ) then
		begin
			dec( k, fwt[ res + (1 shl i) ] );
			inc( res, 1 shl i );
		end;
		
	exit( res + 1 );
end;

procedure delete( x: longInt );
begin
	if ( x = last ) then
		last := prev[last];
		
	dec( len );
	
	next[ prev[x] ] := next[x];
	prev[ next[x] ] := prev[x];
	
	fwt_update( x, -1 );
end;

var	n, m, i, j, p: longInt;

begin
	readln( n, m );
	for i := 1 to m do
		read( a[i] );
	
	last := 0;
	len := 0;
	for i := 1 to n do
	begin
		read( p );
		
		if ( p = -1 ) then
		begin
			j := 1;
			while ( j <= m ) and ( a[j] - j + 1 <= len ) do
			begin
				delete( fwt_getKth( a[j] - j + 1 ) );
			
				inc( j );
			end;
		end
		else
		begin
			inc( len );
			val[i] := p;
			prev[i] := last;
			next[last] := i;
			last := i;
			
			fwt_update( i, +1 );
		end;
	end;
	
	if ( len = 0 ) then
		writeln( 'Poor stack!' )
	else
	begin
		i := next[0];
		while ( i > 0 ) do
		begin
			write( val[i] );
			i := next[i];
		end;
		writeln();
	end;
end.