program problem3;

var	x, y, p: array[ 1..1000000 ] of longInt;

function less( a, b: longInt ): boolean;
begin
	if ( x[a] div 1000 <> x[b] div 1000 ) then
		less := x[a] div 1000 < x[b] div 1000
	else if ( y[a] = y[b] ) then
		less := x[a] < x[b]
	else if ( ( x[a] div 1000 ) mod 2 = 0 ) then
		less := y[a] < y[b]
	else
		less := y[a] > y[b];
end;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := p[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( less( p[i], med ) ) do
				inc( i );
			
			while ( less( med, p[j] ) ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := p[i];
				p[i] := p[j];
				p[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, i: longInt;

begin
	readln( n );
	for i := 1 to n do
	begin
		readln( x[i], y[i] );
		
		p[i] := i;
	end;
	
	qsort( 1, n );
	
	for i := 1 to n do
		write( p[i], ' ' );
	
	writeln;
end.