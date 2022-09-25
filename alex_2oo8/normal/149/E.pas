program problem5;
uses math;

type	tArr =	array[ 1..200000 ] of longInt;

var	z: tArr;

function reverse( const s: ansistring ): ansistring;
var	res: ansistring;
	i, n: longInt;
begin
	n := length(s);

	res := '';
	for i := 1 to n do
		res := s[i] + res;
		
	exit( res );
end;

procedure KMP( s: ansistring; var res: tArr );
var	i, k, n: longInt;
begin
	n := length(s);
	
	z[1] := 0;
	res[1] := 0;
	for i := 2 to n do
	begin
		k := z[i-1];
		while ( k > 0 ) and ( s[i] <> s[k+1] ) do
			k := z[k];
			
		if ( s[i] = s[k+1] ) then
			z[i] := k + 1
		else
			z[i] := 0;
			
		res[i] := max( z[i], res[i-1] );
		if ( s[i] = '#' ) then
			res[i] := 0;
	end;
end;

var	n, m, k, i, j, ans: longInt;
	s, r, t: ansistring;
	z1, z2: tArr;

begin
	readln( s );

	n := length( s );
	r := reverse( s );
	ans := 0;

	readln( m );
	for i := 1 to m do
	begin
		readln( t );
		k := length(t);
		
		if ( k = 1 ) then
			continue;
		
		KMP( t + '#' + s, z1 );
		KMP( reverse(t) + '#' + r, z2 );

		for j := 2 to n do
			if ( z1[k+j] + z2[n+k-j+2] >= k ) then
			begin
				inc( ans );
				break;
			end;
	end;
	
	writeln( ans );
end.