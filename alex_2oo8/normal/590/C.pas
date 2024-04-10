program problem3;
uses math;

const	INF =	10000000;

var	n, m: longInt;
	f: array[ 1..1000 ] of ansistring;
	d: array[ 1..1000, 1..1000, 1..3 ] of longInt;
	s: array[ -1000000..1000000, 0..1 ] of longInt;

procedure bfs( c: longInt );
var	i, j, x, y, l, r: longInt;
begin
	l := 1;
	r := 0;
	for i := 1 to n do
		for	j := 1 to m do
			if ( ord( f[i][j] ) - ord( '0' ) = c ) then
			begin
				d[i][j][c] := 0;
				
				inc( r );
				s[r][0] := i;
				s[r][1] := j;
			end
			else
				d[i][j][c] := INF;
	
	while ( l <= r ) do
	begin
		x := s[l][0];
		y := s[l][1];
		inc( l );
		for i := -1 to 1 do
			for j := -1 to 1 do
				if ( i * i + j * j = 1 ) and ( x + i > 0 ) and ( x + i <= n ) and ( y + j > 0 ) and ( y + j <= m ) and ( f[x + i][y + j] <> '#' ) and ( d[x + i][y + j][c] = INF ) then
				begin
					if ( f[x + i][y + j] = '.' ) then
					begin
						d[x + i][y + j][c] := d[x][y][c] + 1;
						
						inc( r );
						s[r][0] := x + i;
						s[r][1] := y + j;
					end
					else
					begin
						d[x + i][y + j][c] := d[x][y][c];
					
						dec( l );
						s[l][0] := x + i;
						s[l][1] := y + j;
					end;
				end;
	end;
end;

var	i, j, k, ans, a, b, c: longInt;

begin
	readln( n, m );
	for i := 1 to n do
		readln( f[i] );
	
	for i := 1 to 3 do
		bfs( i );
	
	ans := INF;
	a := INF;
	b := INF;
	c := INF;
	for i := 1 to n do
		for j := 1 to m do
		begin
			k := 0;
			if ( f[i][j] = '.' ) then
				k := 1;
			
			ans := min( ans, d[i][j][1] + d[i][j][2] + d[i][j][3] - 2 * k );
			a := min( a, d[i][j][1] + d[i][j][2] - k );
			b := min( b, d[i][j][1] + d[i][j][3] - k );
			c := min( c, d[i][j][2] + d[i][j][3] - k );
		end;
	
	ans := min( ans, a + b );
	ans := min( ans, a + c );
	ans := min( ans, b + c );
	
	if ( ans = INF ) then
		ans := -1;
	
	writeln( ans );
end.