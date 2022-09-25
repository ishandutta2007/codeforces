program problem4;
uses math, dos;

const	m = ( 1 shl 23 ) + 10;

var	n, r: longInt;
	used: array[ 0..m ] of boolean;
	s: array[ 1..m ] of longInt;
	
procedure add( mask: longInt );
begin
	if ( used[mask] ) then
		exit();
		
	used[mask] := true;
	s[r] := mask;
	inc( r );
end;

function leftBit( mask: longInt ): longInt;
var	i, res: longInt;
begin
	res := 1;
	for i := 1 to n do
		if ( ( mask and ( 1 shl (i-1) ) ) > 0 ) then
			res := i;
			
	exit( res );
end;

function bitCnt( mask: longInt ): longInt;
var	i, res: longInt;
begin
	res := 0;
	for i := 0 to n do
		if ( ( mask and ( 1 shl i ) ) > 0 ) then
			inc( res );
			
	exit( res );
end;

var	i, j, k, l, ans: longInt;
	a: array[ 1..25 ] of longInt;
	b: array[ 1..25, 1..25 ] of longInt;
	ok: boolean;
	t1, t2: int64;
	
begin
	t1 := getMsCount();
	fillchar( b, sizeOf(b), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to n do
		for j := i to n do
			for k := (j+1) to n do
				if ( ( a[i] + a[j] ) = a[k] ) then
				begin
					b[i][k] := b[i][k] or ( 1 shl (j-1) );
					b[j][k] := b[j][k] or ( 1 shl (i-1) );
				end;
	
	ans := n + 1;
	l := 1;
	r := 2;
	s[1] := 1;
	while ( l < r ) do
	begin
		t2 := getMsCount();
		if ( (t2-t1) > 1980 ) then
			break;
	
		k := leftBit( s[l] );
		if ( k = n ) then
			ans := min( ans, bitCnt( s[l] ) );
			
		ok := false;
		for i := 1 to k do
			if ( ( s[l] and ( 1 shl (i-1) ) ) > 0 ) and ( ( s[l] and b[i][k+1] ) > 0 ) then
			begin
				ok := true;
				break;
			end;
			
		if ( ok ) then
		begin			
			for i := 1 to k do
				if ( ( s[l] and ( 1 shl (i-1) ) ) > 0 ) then
					add( s[l] + ( 1 shl k ) - ( 1 shl (i-1) ) );
					
			add( s[l] + ( 1 shl k ) );
		end;
		
		inc( l );
	end;
	
	if ( ans  = (n+1) ) then
		ans := -1;
		
	writeln( ans );
end.