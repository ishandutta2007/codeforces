program problem3;
uses math;

const	md =	1000000007;

var	a: array[ 0..100001 ] of longInt;

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

function pow( a, p: longInt ): longInt;
var	res: longInt;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * int64(a) ) mod md;
			
		a := ( a * int64(a) ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

var	n, i, j, l, ans: longInt;
	k, lt, kk, kkk, d: array[ 1..100001 ] of longInt;

begin
	fillchar( k, sizeOf(k), 0 );
	fillDWord( lt, sizeOf(lt) div sizeOf(lt[1]), 1 );
	fillDWord( kk, sizeOf(kk) div sizeOf(kk[1]), 1 );
	fillDWord( kkk, sizeOf(kkk) div sizeOf(kkk[1]), 1 );
	fillchar( d, sizeOf(d), 0 );
	
	for i := 1 to 100000 do
		for j := 1 to ( 100000 div i ) do
			inc( d[i*j] );
			
	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	qsort( 1, n );

	a[0] := 0;
	for i := 1 to n do
	begin
		for j := ( a[i-1] + 1 ) to a[i] do
			for l := 1 to ( 100000 div j ) do
			begin
				kk[j*l] := ( int64( kk[j*l] ) * pow( k[j*l], ( i - lt[j*l] ) ) ) mod md;
				kkk[j*l] := ( int64( kkk[j*l] ) * pow( k[j*l], ( i - lt[j*l] ) ) ) mod md;
				
				inc( k[j*l] );
				lt[j*l] := i;
			end;			
	end;
	
	for i := 1 to 100000 do
	begin
		kk[i] := ( int64( kk[i] ) * pow( k[i], ( n - lt[i] + 1 ) ) ) mod md;
		
		if ( k[i] = d[i] ) then
			kkk[i] := ( int64( kkk[i] ) * pow( ( k[i] - 1 ), ( n - lt[i] + 1 ) ) ) mod md
		else
			kkk[i] := ( int64( kkk[i] ) * pow( k[i], ( n - lt[i] + 1 ) ) ) mod md;
	end;
	
	ans := 0;
	for i := 1 to 100000 do
		ans := ( ans + int64(md) + kk[i] - kkk[i] ) mod md;
			
	writeln( ans );
end.