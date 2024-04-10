program problem3;
uses math;

const	inf: int64 =	round(1.0e+15);

var	p, e: array[ 1..200000 ] of longInt;
	used: array[ 1..200000 ] of boolean;
	n, k: longInt;

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
			while ( p[i] > med ) do
				inc( i );
			while ( p[j] < med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := p[i];
				p[i] := p[j];
				p[j] := t;
				
				t := e[i];
				e[i] := e[j];
				e[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function f( pp: longInt ): int64;
var	cnt1, cnt2, i, l, z: longInt;
	res: int64;
begin
	fillchar( used, sizeOf(used), 0 );

	if ( pp > n ) then
		exit( inf );
		
	cnt1 := 0;
	cnt2 := 0;
	for i := 1 to n do
		if ( p[i] > pp ) then
			inc( cnt1 )
		else if ( p[i] >= pp - 1 ) then
			inc( cnt2 );
	
	if ( cnt1 >= k ) then
		exit( inf );
	
	z := max( 0, cnt2 - (k - cnt1 - 1) );
	l := pp;
	
	res := 0;
	for i := n downto 1 do
		if ( p[i] >= pp - 1 ) and ( p[i] <= pp ) and ( z > 0 ) then
		begin
			used[i] := true;
			
			inc( res, e[i] );
			dec( z );
			dec( l );
		end;
		
	for i := n downto 1 do
		if ( not used[i] ) and ( l > 0 ) then
		begin
			inc( res, e[i] );
			dec( l );
		end;
		
	exit( res );
end;

var	i, pp, t: longInt;
	ans: int64;

begin
	readln( n, k );
	
	if ( k = n + 1 ) then
	begin
		writeln( 0 );
		halt;
	end;
	
	for i := 1 to n do
		readln( p[i], e[i] );
		
	qsort( 1, n );
	
	pp := p[k];
	
	for i := 1 to n do
	begin
		t := e[i];
		e[i] := p[i];
		p[i] := t;
	end;
	
	qsort( 1, n );
	
	for i := 1 to n do
	begin
		t := e[i];
		e[i] := p[i];
		p[i] := t;
	end;
	
	ans := min( f(pp), min( f(pp + 1), f(pp + 2) ) );
	
	if ( ans = inf ) then
		ans := -1;
		
	writeln( ans );
end.