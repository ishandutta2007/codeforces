program problem2;

var s, t: ansistring;
	cnt: array[ 'A'..'Z' ] of longInt;
	sum: array[ 1..100001, 'A'..'Z' ] of longInt;
	i, n, ans: longInt;
	c: char;

begin
	assign( input, 'input.txt' );
	reset( input );
	assign( output, 'output.txt' );
	rewrite( output );
	
	fillchar( cnt, sizeOf(cnt), 0 );
	
	readln( s );
	readln( t );
	
	n := length( s );
	ans := 0;
	
	for i := 1 to n do
	begin
		inc( cnt[ s[i] ] );
		dec( cnt[ t[i] ] );
	end;
	
	for c := 'A' to 'Z' do
		sum[n+1][c] := 0;
		
	for i := n downTo 1 do
	begin
		for c := 'A' to 'Z' do
			sum[i][c] := sum[i+1][c];
			
		inc( sum[i][ s[i] ] );
	end;
	
	c := 'A';
	for i := 1 to n do
	begin
		if ( cnt[ s[i] ] > 0 ) then
		begin
			while ( cnt[c] >= 0 ) do
				inc( c );
				
			if ( sum[i][ s[i] ] = cnt[ s[i] ] ) or ( c < s[i] ) then
			begin
				inc( ans );
				dec( cnt[ s[i] ] );
				inc( cnt[c] );
				
				s[i] := c;
			end;
		end;
	end;
	
	writeln( ans );
	writeln( s );
	
	close( input );
	close( output );
end.