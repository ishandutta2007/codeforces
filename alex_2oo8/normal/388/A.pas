program problem1;
uses math;

var	n, i, j, k, t: longInt;
	x, a: array[ 1..100 ] of longInt;

begin
	readln( n );
	for i := 1 to n do
		read( x[i] );
	
	for i := 1 to n do
		for j := i + 1 to n do
			if ( x[j] > x[i] ) then
			begin
				t := x[i];
				x[i] := x[j];
				x[j] := t;
			end;
			
	for k := 1 to n do
	begin
		for i := 1 to n do
			a[i] := x[i];
		
		t := 1;
		for i := k + 1 to n do
		begin
			t := -1;
			for j := 1 to i - 1 do
				if ( a[j] > 0 ) and ( ( t = -1 ) or ( a[j] > a[t] ) ) then
					t := j;
			
			if ( t = -1 ) then
				break;
				
			a[i] := min( a[t] - 1, a[i] );
			a[t] := 0;
		end;
		
		if ( t <> -1 ) then
		begin
			writeln( k );
			break;
		end;
	end;
end.