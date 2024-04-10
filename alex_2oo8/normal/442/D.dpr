program problem4;
uses math;

var	p, a, b, g: array[ 0..1000001 ] of longInt;
	ans: longInt;
	
procedure update( v, x: longInt );
begin
	if ( g[v] = x ) then
		exit;

	g[v] := x;
	
	if ( p[v] = 1 ) then
	begin
		ans := max( ans, x );
		
		exit;
	end;
	
	if ( v = a[ p[v] ] ) or ( v = b[ p[v] ] ) then
	begin
		if ( x > g[ a[ p[v] ] ] ) then
		begin
			a[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
			b[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
			a[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
		end;
		
		update( p[v], max( g[ a[ p[v] ] ], g[ b[ p[v] ] ] + 1 ) );
	end
	else if ( x > g[ b[ p[v] ] ] ) then
	begin
		b[ p[v] ] := v;

		if ( x > g[ a[ p[v] ] ] ) then
		begin
			a[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
			b[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
			a[ p[v] ] := a[ p[v] ] xor b[ p[v] ];
		end;
		
		update( p[v], max( g[ a[ p[v] ] ], g[ b[ p[v] ] ] + 1 ) );
	end;
end;
	
var	i, n: longInt;

begin
	ans := 0;
	
	readln( n );
	for i := 1 to n do
	begin
		read( p[i + 1] );
		
		update( i + 1, 1 );
		
		write( ans, ' ' );
	end;
	writeln;
end.