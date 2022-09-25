program problem5;

type tRec =	record
				l, p: longInt;
			end;
			
var	a: array[ 1..50000 ] of tRec;

function isLess( x, y: tRec ): boolean;
var	xx, yy: int64;
begin
	xx := x.l * int64( x.p ) * ( 100 - y.p );
	yy := y.l * int64( y.p ) * ( 100 - x.p );
	
	exit( xx < yy );
end;

procedure qsort( l, r: longInt );
var	i, j: longInt;
	t, med: tRec;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( isLess( med, a[i] ) ) do
				inc( i );
			while ( isLess( a[j], med ) ) do
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

var	n, i: longInt;
	sum: int64;
	ans: extended;

begin
	readln( n );
	sum := 0;
	for i := 1 to n do
		readln( a[i].l, a[i].p );
		
	qsort( 1, n );
	
	sum := 0;
	ans := 0.0;	
	for i := n downTo 1 do
	begin
		ans := ans + a[i].l + ( a[i].l * a[i].p * sum / 10000 );
		inc( sum, ( 100 - a[i].p ) );
	end;
	
	writeln( ans:0:15 );
end.