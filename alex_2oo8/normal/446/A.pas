program problem1;
uses math;

var	n, i, ans, f, s: longInt;
	a, b: array[ 1..100001 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	a[n + 1] := 1000000001;
	
	ans := 1;
	f := n + 1;
	s := n + 1;
	for i := n - 1 downto 1 do
	begin
		if ( a[i] >= a[i + 1] ) then
		begin
			if ( a[i + 2] <= a[i] + 1 ) then
			begin
				f := i + 1;
				s := i + 2;
			end
			else
			begin
				s := f;
				f := i + 1;
			end;
		end;
		
		ans := max( ans, s - i );
	end;
	
	for i := 1 to n do
		b[i] := -a[n - i + 1];
	
	for i := 1 to n do
		a[i] := b[i];
	
	f := n + 1;
	s := n + 1;
	for i := n - 1 downto 1 do
	begin
		if ( a[i] >= a[i + 1] ) then
		begin
			if ( a[i + 2] <= a[i] + 1 ) then
			begin
				f := i + 1;
				s := i + 2;
			end
			else
			begin
				s := f;
				f := i + 1;
			end;
		end;
		
		ans := max( ans, s - i );
	end;
 		
	writeln( ans );
end.