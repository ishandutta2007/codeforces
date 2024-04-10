program problem1;

var n, i, j, m, a: longInt;
	last: array[ 1..5000 ] of longInt;
	ansArr: array[ 1..300000, 0..1 ] of longInt;

begin
	assign( input, 'input.txt' );
	reset( input );
	assign( output, 'output.txt' );
	rewrite( output );
	
	fillchar( last, sizeOf(last), 0 );
	
	readln( n );
	n := n + n;
	m := 0;
	for i := 1 to n do
	begin
		read( a );
		if ( last[a] > 0 ) then
		begin
			inc( m );
			ansArr[m][0] := last[a];
			ansArr[m][1] := i;
			last[a] := 0;
		end
		else
			last[a] := i;
	end;
	
	if ( (2*m) < n ) then
	begin
		writeln( '-1' );
		halt;
	end;
	
	for i := 1 to m do
		writeln( ansArr[i][0], ' ', ansArr[i][1] );
	
	close( input );
	close( output );
end.