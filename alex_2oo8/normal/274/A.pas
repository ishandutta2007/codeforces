program problem1;

var	a: array[ 1..100000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( a[i] < med ) do
				inc( i );
			while ( a[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := a[i];
				a[i] := a[j];
				a[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function find( x, n: longInt ): longInt;
var	l, r, c: longInt;
begin
	l := 1;
	r := n;
	while ( l < r ) do
	begin
		c := (l+r) div 2;
		
		if ( a[c] < x ) then
			l := c + 1
		else
			r := c;
	end;
	
	exit( l );
end;

var	n, k, i, ans, p: longInt;
	b: array[ 1..100000 ] of boolean;

begin
	readln( n, k );
	
	if ( k = 1 ) then
	begin
		writeln( n );
		halt;
	end;
	
	for i := 1 to n do
	begin
		read( a[i] );
		b[i] := true;
	end;
		
	qsort( 1, n );
	
	ans := n;
	for i := 1 to n do
		if ( ( a[i] mod k ) = 0 ) then
		begin
			p := find( a[i] div k, n );
			
			if ( a[p] = ( a[i] div k ) ) and ( b[p] ) then
			begin
				b[i] := false;
				dec( ans );
			end;
		end;
		
	writeln( ans );
end.