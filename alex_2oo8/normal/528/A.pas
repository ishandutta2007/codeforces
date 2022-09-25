program problem1;
uses math;

type	tArr =	array[ 1..500000, 0..1 ] of longInt;
		tArrr =	array[ 1..500000 ] of longInt;

function dsu_get( var p: tArr; v: longInt ): longInt;
begin
	if ( p[v][0] <> v ) then
		p[v][0] := dsu_get( p, p[v][0] );
	
	exit( p[v][0] );
end;

procedure dsu_merge( var p: tArr; x: longInt; var mx: longInt );
var	u, v: longInt;
begin
	u := dsu_get( p, x );
	v := dsu_get( p, x + 1 );
	
	inc( p[u][1], p[v][1] );
	p[v][0] := u;
	
	mx := max( mx, p[u][1] );
end;

procedure init( var p: tArr; n: longInt );
var	i: longInt;
begin
	for i := 1 to n do
	begin
		p[i][0] := i;
		p[i][1] := 1;
	end;
end;

procedure preprocess( var p: tArr; const a: tArrr; n: longInt; var mx: longInt );
var	i: longInt;
begin
	mx := 1;
	
	for i := 1 to n - 1 do
		if ( a[i] = 0 ) then
			dsu_merge( p, i, mx );
end;

var	w, h, n, i, max_hor, max_ver: longInt;
	c: array[ 1..500000 ] of char;
	x, hh, vv: tArrr;
	ans: array[ 1..500000 ] of int64;
	hor, ver: tArr;

begin
	readln( w, h, n );
	
	init( hor, h );
	init( ver, w );
	
	for i := 1 to n do
	begin
		readln( c[i], x[i] );
		
		if ( c[i] = 'H' ) then
			hh[ x[i] ] := 1
		else
			vv[ x[i] ] := 1;
	end;
	
	preprocess( hor, hh, h, max_hor );
	preprocess( ver, vv, w, max_ver );
	
	for i := n downto 1 do
	begin
		ans[i] := max_hor * int64( max_ver );
		
		if ( c[i] = 'H' ) then
			dsu_merge( hor, x[i], max_hor )
		else
			dsu_merge( ver, x[i], max_ver );
	end;
	
	for i := 1 to n do
		writeln( ans[i] );
end.