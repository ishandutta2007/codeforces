program problem2;

type	tRec =	record
					q, op, next: longInt;
				end;
				
var	list: array[ 1..200000 ] of tRec;
	first: array[ 1..200000 ] of longInt;
	
procedure add( x, q, op: longInt );
const	ll: longInt = 0;
begin
	inc( ll );
	list[ll].q := q;
	list[ll].op := op;
	list[ll].next := first[x];
	first[x] := ll;
end;

var	n, m, i, j, k: longInt;
	l, r, q, ans, max2pow: array[ 1..100000 ] of longInt;
	cnt: array[ 0..30 ] of longInt;
	sparse: array[ 1..100000, 0..20 ] of longInt;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( cnt, sizeOf(cnt), 0 );

	readln( n, m );
	for i := 1 to m do
	begin
		readln( l[i], r[i], q[i] );
		
		add( l[i], q[i], +1 );
		add( r[i] + 1, q[i], -1 );
	end;
	
	for i := 1 to n do
	begin
		j := first[i];
		while ( j > 0 ) do
		begin
			for k := 0 to 30 do
				inc( cnt[k], list[j].op * ( (list[j].q shr k) and 1 ) );
		
			j := list[j].next;
		end;
		
		ans[i] := 0;
		for k := 0 to 30 do
			if ( cnt[k] > 0 ) then
				inc( ans[i], 1 shl k );
	end;
	
	for i := 1 to n do
		sparse[i][0] := ans[i];
	
	for j := 0 to 19 do
		for i := 1 to n - (2 shl j) + 1 do
			sparse[i][j + 1] := sparse[i][j] and sparse[ i + (1 shl j) ][j];
			
	max2pow[1] := 0;
	for i := 2 to n do
	begin
		max2pow[i] := max2pow[i - 1];
		if ( i = 2 shl max2pow[i] ) then
			inc( max2pow[i] );
	end;
			
	for i := 1 to m do
	begin
		k := max2pow[ r[i] - l[i] + 1 ];
		
		if ( sparse[ l[i] ][k] and sparse[ r[i] - (1 shl k) + 1 ][k] <> q[i] ) then
		begin
			writeln( 'NO' );
			
			halt;
		end;
	end;
	
	writeln( 'YES' );
	for i := 1 to n do
		write( ans[i], ' ' );
	writeln();
end.