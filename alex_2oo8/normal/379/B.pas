program problem2;
uses math;

var	n, i, k, ii: longInt;
	a: array[ 1..500 ] of longInt;
	ans: array[ 1..1000000 ] of char;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	k := 0;
	for ii := 1 to 500 do
	begin
		for i := 1 to n do
		begin
			if ( a[i] > 0 ) then
			begin
				dec( a[i] );
				inc( k );
				ans[k] := 'P';
			end;
			
			if ( i < n ) then
			begin
				inc( k );
				ans[k] := 'R';
			end;
		end;
		
		for i := 2 to n do
		begin
			inc( k );
			ans[k] := 'L';
		end;
	end;
	
	for i := 1 to k do
		write( ans[i] );
	writeln();
end.