program problem4;
uses math;

var	k, n1, n2, n3, t1, t2, t3, i, p1, p2, p3, tt, j: longInt;
	a1, a2, a3: array[ 1..1000 ] of longInt;

begin
	readln( k, n1, n2, n3, t1, t2, t3 );
	
	for j := 1 to k do
	begin
		p1 := 1;
		for i := 2 to n1 do
			if ( a1[i] < a1[p1] ) then
				p1 := i;
		
		p2 := 1;
		for i := 2 to n2 do
			if ( a2[i] < a2[p2] ) then
				p2 := i;
		
		p3 := 1;
		for i := 2 to n3 do
			if ( a3[i] < a3[p3] ) then
				p3 := i;
		
		tt := max( a1[p1], max( a2[p2] - t1, a3[p3] - t1 - t2 ) );
		
		a1[p1] := tt + t1;
		a2[p2] := tt + t1 + t2;
		a3[p3] := tt + t1 + t2 + t3;
	end;
	
	tt := 0;
	for i := 1 to n3 do
		tt := max( tt, a3[i] );
	
	writeln( tt );
end.