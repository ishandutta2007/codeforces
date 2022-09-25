program problem1;

var	a: array[1..100000] of longInt;
	b: array[0..1050000] of boolean;
	l: array[1..100000] of longInt;
	p: array[ 0..20, 0..100000 ] of longInt;
	
procedure proc( x: longWord );
var i, j: longInt;
begin
	for i := 0 to 20 do
		if ( ( a[x] and (1 shl i) ) > 0 ) then
		begin
			for j := 1 to p[i][0] do
			begin
				l[ p[i][j] ] := l[ p[i][j] ] or a[x];
				b[ l[ p[i][j] ] ] := true;
			end;
			
			p[i][0] := 0;
		end
		else
		begin
			inc( p[i][0] );
			p[i][ p[i][0] ] := x;
		end;
end;

var n, i, j, k, ans: longInt;

begin
	fillchar( b, sizeOf(b), 0 );
	fillchar( p, sizeOf(p), 0 );

	readln( n );
	for i := 1 to n do
		read( a[i] );
		
	l[1] := a[1];
	b[ a[1] ] := true;
	proc( 1 );
	
	for i := 2 to n do
	begin
		l[i] := a[i];
		b[ a[i] ] := true;
		proc( i );
	end;
	
	ans := 0;
	for i := 0 to 1050000 do
		if ( b[i] ) then
			inc( ans );
			
	writeln( ans );
end.