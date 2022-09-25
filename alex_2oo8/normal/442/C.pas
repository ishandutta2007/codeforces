program problem3;
uses math;

var	a, next, prev, nextReady, added: array[ 0..1000001 ] of longInt;
	firstReady: longInt;
	sum: int64;
	
procedure addReady( x: longInt );
begin
	if ( a[x] > a[ prev[x] ] ) or ( a[x] > a[ next[x] ] ) or ( added[x] = 1 ) then
		exit();
	
	added[x] := 1;
	
	nextReady[x] := firstReady;
	firstReady := x;
end;

procedure remove( x: longInt );
begin
	inc( sum, min( a[ prev[x] ], a[ next[x] ] ) );
	
	next[ prev[x] ] := next[x];
	prev[ next[x] ] := prev[x];
	
	addReady( prev[x] );
	addReady( next[x] );
end;

var	n, i, x, l, r, c: longInt;
	s: int64;
	incr, decr: boolean;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( a[i] );
		
		next[i] := i + 1;
		prev[i] := i - 1;
	end;
	
	a[0] := 0;
	a[n + 1] := 0;
	
	if ( n < 3 ) then
	begin
		writeln( 0 );
		halt;
	end;
	
	firstReady := 0;
	for i := 2 to n - 1 do
		if ( a[i] <= a[i - 1] ) and ( a[i] <= a[i + 1] ) then
			addReady( i );
			
	while ( firstReady > 0 ) do
	begin
		x := firstReady;
		
		firstReady := nextReady[firstReady];
		
		remove( x );
	end;
	
	s := a[1];
	x := 1;
	i := next[1];
	while ( i <= n ) do
	begin
		inc( x );
		a[x] := a[i];
		
		inc( s, a[x] );
		
		i := next[i];
	end;
	
	a[0] := 0;
	a[x + 1] := 0;

	if ( x < 3 ) then
	begin
		writeln( sum );
		halt;
	end;
	
	incr := false;
	decr := false;
	for i := 2 to x do
		if ( a[i] > a[i - 1] ) then
			incr := true
		else if ( a[i] < a[i - 1] ) then
			decr := true;

	if ( incr and decr ) then
	begin
		l := 1;
		while ( a[l + 1] >= a[l] ) do
			inc( l );
		
		r := l;
		while ( a[l - 1] = a[r] ) do
			dec( l );
		
		if ( r - l + 1 > 2 ) then
			inc( sum, int64(r - l - 1) * a[l] );
		
		c := l;
		l := l - 1;
		if ( r = c ) then
			inc( r );
		
		while ( a[l] > 0 ) or ( a[r] > 0 ) do
		begin
			if ( a[l] > 0 ) and ( a[l - 1] > a[r] ) then
			begin
				inc( sum, a[l - 1] );
				dec( l );
			end
			else if ( a[r] > 0 ) and ( a[r + 1] > a[l] ) then
			begin
				inc( sum, a[r + 1] );
				inc( r );
			end
			else
			begin
				inc( sum, min( a[l], a[r] ) );
				
				if ( a[l] > a[r] ) then
				begin
					c := l;
					dec( l );
				end
				else
				begin
					c := r;
					inc( r );
				end;
			end;
		end;
	end
	else if ( incr ) then
		inc( sum, s - a[x] - a[x - 1] )
	else
		inc( sum, s - a[1] - a[2] );
	
	writeln( sum );
end.