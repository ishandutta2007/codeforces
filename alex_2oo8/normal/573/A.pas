program problem1;

var	n, i: longInt;
	a: array[ 1..100000 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
	begin
		while ( a[i] mod 2 = 0 ) do
			a[i] := a[i] div 2;
			
		while ( a[i] mod 3 = 0 ) do
			a[i] := a[i] div 3;
	end;
	
	for i := 2 to n do
		if ( a[i] <> a[1] ) then
		begin
			writeln( 'No' );
			
			halt;
		end;
	
	writeln( 'Yes' );
end.