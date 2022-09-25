program problemC;
uses math;

type	tQuery =	record
						l, r, id: longInt;
					end;

var	queries: array[ 1..100000 ] of tQuery;
	maxVal, debt: array[ 1..10000000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, med: longInt;
	t: tQuery;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := queries[ l + random(r - l + 1) ].l;
		while ( i <= j ) do
		begin
			while ( queries[i].l < med ) do
				inc( i );
				
			while ( queries[j].l > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := queries[i];
				queries[i] := queries[j];
				queries[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

procedure update( v, l, r, x, val: longInt );
var	c: longInt;
begin
	c := ( l + r ) div 2;
	
	if ( l = r ) then
	begin
		maxVal[v] := val;
		exit();
	end;
	
	if ( x <= c ) then
		update( 2 * v, l, c, x, val )
	else
		update( 2 * v + 1, c + 1, r, x, val );
		
	maxVal[v] := max( maxVal[2 * v], maxVal[2 * v + 1] );
end;

procedure decrease( v, l, r, x: longInt );
var	c: longInt;
begin
	c := ( l + r ) div 2;
	
	if ( l = r ) then
	begin
		dec( maxVal[v] );
		exit();
	end;
	
	if ( c >= x ) then
	begin
		decrease( 2 * v, l, c, x );
		dec( debt[2 * v + 1] );
	end
	else
		decrease( 2 * v + 1, c + 1, r, x );
		
	maxVal[v] := max( maxVal[2 * v] + debt[2 * v], maxVal[2 * v + 1] + debt[2 * v + 1] );
end;

function getMax( v, l, r, x: longInt ): longInt;
var	res, c: longInt;
begin
	c := ( l + r ) div 2;

	if ( l = r ) then
		exit( maxVal[v] + debt[v] );

	if ( x > c ) then
		res := max( maxVal[2 * v] + debt[2 * v], getMax( 2 * v + 1, c + 1, r, x ) )
	else
		res := getMax( 2 * v, l, c, x );
		
	exit( res + debt[v] );
end;

var	s: ansistring;
	balance, zeroBalance, lastWithBalance, ans: array[ -1000000..1000001 ] of longInt;
	n, i, m, b, cur: longInt;

begin
	fillchar( lastWithBalance, sizeOf(lastWithBalance), 0 );

	readln( s );
	n := length( s );
	
	balance[0] := 0;
	for i := 1 to n do
		if ( s[i] = '(' ) then
			balance[i] := balance[i - 1] + 1
		else
			balance[i] := balance[i - 1] - 1;
			
	for i := n downto 1 do
	begin
		zeroBalance[i] := lastWithBalance[ balance[i - 1] ];
		lastWithBalance[ balance[i] ] := i;
	end;

	readln( m );
	for i := 1 to m do
	begin
		readln( queries[i].l, queries[i].r );
		queries[i].id := i;
	end;
	
	qsort( 1, m );
	
	b := 0;
	cur := 0;
	for i := 1 to n do
	begin
		if ( s[i] = '(' ) then
			inc( b )
		else if ( b > 0 ) then
		begin
			dec( b );
			inc( cur );
		end;
		
		update( 1, 1, n, i, cur );
	end;
	
	cur := 1;
	for i := 1 to m do
	begin
		while ( cur < queries[i].l ) do
		begin
			if( s[cur] = '(' ) and ( zeroBalance[cur] > 0 ) then
				decrease( 1, 1, n, zeroBalance[cur] );
				
			inc( cur );
		end;

		ans[ queries[i].id ] := 2 * getMax( 1, 1, n, queries[i].r );
	end;
	
	for i := 1 to m do
		writeln( ans[i] );
end.