program problem3;
uses math;

const	inf =	1000000000;

function f( c: char ): longInt;
begin
	if ( c in ['a'..'z'] ) then
		exit( ord(c) - ord('a') + 1 )
	else if ( c in ['A'..'Z'] ) then
		exit( ord(c) - ord('A') + 27 )
	else
		exit( -1 );
end;

var	nn, n, m, i, j, l, r, k, d, ans: longInt;
	e: array[ 1..52, 1..52 ] of longInt;
	rowD, colD, p, s, colMin: array[ 1..100 ] of longInt;
	prev: array[ 1..100, 0..1 ] of longInt;
	used: array[ 1..100 ] of boolean;
	ok: boolean;
	ss, t: ansistring;
	bufIn: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );

	readln( n, k );
	readln( ss );
	readln( t );
	
	for i := 1 to k do
		for j := 1 to k do
			e[i][j] := n;
	
	for i := 1 to n do
		dec( e[ f( t[i] ) ][ f( ss[i] ) ] );

	nn := n;
	n := k;
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
	
	k := n;
	n := nn;
	
	ans := k * n;
	for i := 1 to k do
		dec( ans, e[ p[i] ][i] );
		
	writeln( ans );
	for i := 1 to k do
		if ( p[i] <= 26 ) then
			write( chr( ord('a') + p[i] - 1 ) )
		else
			write( chr( ord('A') + p[i] - 27 ) );
	writeln();
end.