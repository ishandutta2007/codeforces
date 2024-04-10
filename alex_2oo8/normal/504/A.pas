program problem1;

var	deg, s, queue: array[ 0..100000 ] of longInt;
	l, r: longInt;

procedure add( x: longInt );
begin
	queue[r] := x;
	inc( r );
end;
	
var	n, i, m: longInt;

begin
	readln( n );
	for i := 0 to n - 1 do
		readln( deg[i], s[i] );
	
	m := 0;
	for i := 0 to n - 1 do
		inc( m, deg[i] );
	
	writeln( m div 2 );
	
	l := 1;
	r := 1;
	
	for i := 0 to n - 1 do
		if ( deg[i] = 1 ) then
			add( i );
	
	while ( l < r ) do
	begin
		if ( deg[ queue[l] ] = 0 ) then
		begin
			inc( l );
			
			continue;
		end;
	
		writeln( queue[l], ' ', s[ queue[l] ] );
		
		s[ s[ queue[l] ] ] := s[ s[ queue[l] ] ] xor queue[l];
		dec( deg[ s[ queue[l] ] ] );
		if ( deg[ s[ queue[l] ] ] = 1 ) then
			add( s[ queue[l] ] );
		
		inc( l );
	end;
end.