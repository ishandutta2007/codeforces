program problem2;

const	days: array[ 1..12 ] of longInt = ( 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 );

var	a: array[ 0..100000 ] of ansistring;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: ansistring;
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

function checkDate( s: ansistring ): boolean;
var	d, m, y: longInt;
begin
	if ( s[3] <> '-' ) or ( s[6] <> '-' ) then
		exit( false );
		
	val( copy( s, 1, 2 ), d );
	val( copy( s, 4, 2 ), m );
	val( copy( s, 7, 4 ), y );
	
	exit( ( y >= 2013 ) and ( y <= 2015 ) and ( m >= 1 ) and ( m <= 12 ) and ( d >= 1 ) and ( d <= days[m] ) );
end;

var	s: ansistring;
	i, n, k, curr: longInt;

begin
	readln( s );
	
	n := 0;
	for i := 1 to ( length(s) - 9 ) do
		if ( checkDate( copy( s, i, 10 ) ) ) then
		begin
			inc( n );
			a[n] := copy( s, i, 10 );
		end;
		
	qsort( 1, n );
	
	a[0] := a[1];
	k := 0;
	curr := 0;
	for i := 1 to n do
	begin
		if ( a[i] = a[i-1] ) then
			inc( curr )
		else
			curr := 1;
			
		if ( curr > k ) then
		begin
			k := curr;
			s := a[i];
		end;		
	end;
	
	writeln( s );
end.