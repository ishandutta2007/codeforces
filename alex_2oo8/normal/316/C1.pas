program problem3;
uses math;

const	inf =	1000000000;

var	n, m, i, j, l, r, k, d, ans: longInt;
	e, f, id: array[ 1..32, 1..32 ] of longInt;
	rowD, colD, p, s, colMin: array[ 1..100 ] of longInt;
	prev: array[ 1..100, 0..1 ] of longInt;
	used: array[ 1..100 ] of boolean;
	ok: boolean;

begin
	readln( n, m );
	
	for i := 1 to (n * m) div 2 do
		for j := 1 to (n * m) div 2 do
			e[i][j] := 10000;
			
	for i := 1 to n do
		for j := 1 to m do
			read( f[i][j] );
			
	k := 0;
	for i := 1 to n do
		for j := 1 to m do
			if ( not odd(i+j) ) then
			begin
				inc( k );
				id[i][j] := k;
			end;

	k := 0;
	for i := 1 to n do
		for j := 1 to m do
			if ( odd(i+j) ) then
			begin
				inc( k );
				id[i][j] := k;
			end;
			
	for i := 1 to n do
		for j := 1 to m do
			if ( not odd(i+j) ) then
			begin
				if ( i > 1 ) then
				begin
					if ( f[i][j] = f[i-1][j] ) then
						e[ id[i][j] ][ id[i-1][j] ] := 0
					else
						e[ id[i][j] ][ id[i-1][j] ] := 1;
				end;
				
				if ( i < n ) then
				begin
					if ( f[i][j] = f[i+1][j] ) then
						e[ id[i][j] ][ id[i+1][j] ] := 0
					else
						e[ id[i][j] ][ id[i+1][j] ] := 1;
				end;
				
				if ( j > 1 ) then
				begin
					if ( f[i][j] = f[i][j-1] ) then
						e[ id[i][j] ][ id[i][j-1] ] := 0
					else
						e[ id[i][j] ][ id[i][j-1] ] := 1;
				end;
				
				if ( j < m ) then
				begin
					if ( f[i][j] = f[i][j+1] ) then
						e[ id[i][j] ][ id[i][j+1] ] := 0
					else
						e[ id[i][j] ][ id[i][j+1] ] := 1;
				end;
			end;

	n := (n * m) div 2;
	for i := 1 to n do
	begin
		fillchar( used, sizeOf(used), 0 );
		
		for j := 1 to n do
			colMin[j] := e[i][j] - rowD[i] - colD[j];
		
		prev[i][0] := 0;
		prev[i][1] := 0;
		ok := false;
		r := 2;
		s[1] := i;
		while ( not ok ) do
		begin
			l := 1;
			while ( not ok ) and ( l < r ) do
			begin
				for j := 1 to n do
					if ( e[ s[l] ][j] = ( rowD[ s[l] ] + colD[j] ) ) and ( not used[j] ) then
					begin
						if ( p[j] = 0 ) then
						begin
							k := s[l];
							p[j] := k;
							while ( prev[k][1] > 0 ) do
							begin
								p[ prev[k][0] ] := prev[k][1];
								k := prev[k][1];
							end;
							
							ok := true;
							break;
						end
						else
						begin
							used[j] := true;
							
							s[r] := p[j];
							prev[ p[j] ][0] := j;
							prev[ p[j] ][1] := s[l];
							inc( r );
							
							for k := 1 to n do
								colMin[k] := min( colMin[k], ( e[ p[j] ][k] - rowD[ p[j] ] - colD[k] ) );
						end;
					end;
					
				inc( l );
			end;
			
			if ( ok ) then
				break;
				
			d := inf;
			for j := 1 to n do
				if ( not used[j] ) then
					d := min( d, colMin[j] );
					
			inc( rowD[i], d );
			for j := 1 to n do
				if ( used[j] ) then
				begin
					inc( rowD[ p[j] ], d );
					dec( colD[j], d );
				end
				else
					dec( colMin[j], d );
		end;
	end;
	
	ans := 0;
	for i := 1 to n do
		inc( ans, e[ p[i] ][i] );
		
	writeln( ans );
end.