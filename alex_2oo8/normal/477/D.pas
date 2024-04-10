program problem4;
uses math;

const	md =	1000000007;

type	tTrieNode =	record
						next: array[ '0'..'1' ] of longInt;
					end;

var	s: ansistring;
	t: array[ 1..12510000 ] of tTrieNode;
	nodeInTrie: array[ 1..5000, 1..5000 ] of longInt;
	n: longInt;
	
function newTrieNode(): longInt;
const	tw: longInt = 0;
begin
	inc( tw );
	t[tw].next['0'] := 0;
	t[tw].next['1'] := 0;
	
	exit( tw );
end;

function nextTrieNode( v: longInt; c: char ): longInt;
begin
	if ( t[v].next[c] = 0 ) then
		t[v].next[c] := newTrieNode();
	
	exit( t[v].next[c] );
end;

procedure initTrie();
var	i, j, v: longInt;
begin
	newTrieNode();
	
	for i := 1 to n do
	begin
		v := 1;
		for j := i to n do
		begin
			v := nextTrieNode( v, s[j] );
			
			nodeInTrie[i][j] := v;
		end;
	end;
end;

function lessOrEqual( a, b, p, q: longInt ): boolean;
var	l, r, c: longInt;
begin
	if ( nodeInTrie[a][b] = nodeInTrie[p][q] ) then
		exit( true );
	
	if ( s[a] <> s[p] ) then
		exit( s[a] < s[p] );
	
	l := 1;
	r := b - a + 1;
	while ( l < r ) do
	begin
		c := ( l + r + 1 ) div 2;
		if ( nodeInTrie[a][a + c - 1] = nodeInTrie[p][p + c - 1] ) then
			l := c
		else
			r := c - 1;
	end;
	
	exit( s[a + l] < s[p + l] );
end;

function findDifference( a, b, p, q: longInt ): int64;
var	i: longInt;
	sum: int64;
begin
	if ( b - a < q - p ) then
		exit( -findDifference( p, q, a, b ) );
	
	sum := 0;
	for i := 1 to (b - a) - (q - p) do
	begin
		sum := 2 * sum + ord( s[a + i - 1] ) - ord( '0' );
		
		if ( sum > 1.0e+16 ) then
			exit( sum );
	end;
	
	inc( a, (b - a) - (q - p) );
	for i := 0 to b - a do
	begin
		sum := 2 * sum + ord( s[a + i] ) - ord( s[p + i] );
		
		if ( sum > 1.0e+16 ) then
			exit( sum );
	end;
	
	exit( sum );
end;

var	cntSum, minLength, cumulativeMinLength: array[ 1..5001, 1..5000 ] of longInt;
	i, j, k, ans, cnt: longInt;
	
begin
	readln( s );
	n := length( s );
	
	initTrie();
	
	cntSum[1][1] := 1;
	minLength[1][1] := 1;
	cumulativeMinLength[1][1] := 1;
	for j := 2 to n do
	begin
		cntSum[j + 1][j] := 0;
		cumulativeMinLength[j + 1][j] := md;
		for i := j downto 2 do
		begin
			if ( s[i] = '0' ) then
			begin
				cnt := 0;
				minLength[i][j] := md;
			end
			else
			begin
				k := 2 * i - j - 1;
				
				cnt := cntSum[ max( 1, k + 1 ) ][i - 1];
				minLength[i][j] := cumulativeMinLength[ max( 1, k + 1 ) ][i - 1] + 1;
				
				if ( k > 0 ) and ( lessOrEqual( k, i - 1, i, j ) ) then
				begin
					cnt := cntSum[k][i - 1];
					minLength[i][j] := cumulativeMinLength[k][i - 1] + 1;
				end;
			end;
		
			cntSum[i][j] := ( cntSum[i + 1][j] + cnt ) mod md;
			cumulativeMinLength[i][j] := min( cumulativeMinLength[i + 1][j], minLength[i][j] );
		end;
		
		cntSum[1][j] := ( cntSum[2][j] + 1 ) mod md;
		
		minLength[1][j] := 1;
		cumulativeMinLength[1][j] := 1;
	end;
	
	k := 1;
	for i := 2 to n do
		if ( minLength[i][n] < md ) and ( findDifference( i, n, k, n ) + minLength[i][n] - minLength[k][n] < 0 ) then
			k := i;
	
	ans := 0;
	for i := k to n do
		ans := ( 2 * ans + ord( s[i] ) - ord( '0' ) ) mod md;
	
	ans := ( ans + minLength[k][n] ) mod md;
	
	writeln( cntSum[1][n] );
	writeln( ans );
end.