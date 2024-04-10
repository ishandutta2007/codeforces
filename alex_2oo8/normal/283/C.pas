program problem3;

const	md =	1000000007;

var	n, q: longInt;
	a, p, next, v: array[ 1..300 ] of longInt;
	sum: int64;

function DFS( s: longInt ): longInt;
var	res: longInt;
begin
	if ( next[s] = 0 ) then
		exit( 1 );
		
	res := DFS( next[s] );
	dec( sum, ( res * a[s] ) );
	exit( res + 1 );
end;

procedure DFS2( s: longInt );
begin
	if ( p[s] = 0 ) then
		exit();
		
	DFS2( p[s] );
	inc( a[s], a[ p[s] ] );
end;

function DFS3( s: longInt ): boolean;
var	res: boolean;
begin
	if ( s = 0 ) then
		exit( false )
	else if ( v[s] = 1 ) then
		exit( true )
	else if ( v[s] = 2 ) then
		exit( false );
		
	v[s] := 1;
	res := DFS3( p[s] );
	v[s] := 2;
	exit( res );
end;
	
var i, j, k, t: longInt;
	dp: array[ 0..100000 ] of longInt;

begin
	readln( n, q, sum );
	for i := 1 to n do
		read( a[i] );
		
	for i := 1 to q do
	begin
		readln( j, k );
		p[k] := j;
		next[j] := k;
	end;
	
	for i := 1 to n do
		if ( v[i] = 0 ) and ( DFS3( i ) ) then
		begin
			writeln( 0 );
			halt;
		end;
	
	for i := 1 to n do
		if ( p[i] = 0 ) then
			DFS( i );
			
	for i := 1 to n do
		if ( next[i] = 0 ) then
			DFS2( i );
			
	if ( sum < 0 ) then
	begin
		writeln( 0 );
		halt;
	end;
			
	t := sum;
	dp[0] := 1;
	for i := 1 to n do
		for j := a[i] to t do
			dp[j] := ( dp[j] + dp[ j - a[i] ] ) mod md;
			
	writeln( dp[t] );
end.