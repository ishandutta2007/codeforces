program problem2;

type	tArr =	array[ 0..1 ] of longInt;

var	arr: array[ 0..200000 ] of tArr;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tArr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := arr[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( arr[i][0] < med[0] ) or ( ( arr[i][0] = med[0] ) and ( arr[i][1] < med[1] ) ) do
				inc( i );
			while ( arr[j][0] > med[0] ) or ( ( arr[j][0] = med[0] ) and ( arr[j][1] > med[1] ) ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := arr[i];
				arr[i] := arr[j];
				arr[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, i, a, ans: longInt;
	b: int64;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( a, b );
		arr[i][0] := a;
		arr[i][1] := 0;
		
		arr[n+i][0] := b;
		if ( a <> b ) then
			arr[n+i][1] := 1
		else
			arr[n+i][1] := n + 1;
	end;
	
	qsort( 1, (2*n) );
	
	ans := n + 1;
	a := 0;
	b := 0;
	arr[0] := arr[1];
	for i := 1 to (2*n) do
	begin
		if ( arr[i][0] <> arr[i-1][0] ) then
		begin
			a := 1;
			b := arr[i][1];
		end
		else
		begin
			inc( a );
			inc( b, arr[i][1] );
		end;
		
		if ( a >= ( (n+1) div 2 ) ) and ( b < ans ) then
			ans := b;
	end;
	
	if ( ans > n ) then
		writeln( '-1' )
	else
		writeln( ans );
end.