program problem2;
uses math;

var	n, k, i: longInt;
	a, pref, suff: array[ 0..200001 ] of int64;
	res, x, p: int64;

begin
	readln( n, k, x );
	for i := 1 to n do
		read( a[i] );
	
	pref[0] := 0;
	for i := 1 to n do
		pref[i] := pref[i - 1] or a[i];
	
	suff[n + 1] := 0;
	for i := n downto 1 do
		suff[i] := suff[i + 1] or a[i];
	
	p := 1;
	for i := 1 to k do
		p := p * x;
	
	res := 0;
	for i := 1 to n do
	begin
		x := a[i] * p;
		
		res := max( res, pref[i - 1] or suff[i + 1] or x );
	end;
	
	writeln( res );
end.