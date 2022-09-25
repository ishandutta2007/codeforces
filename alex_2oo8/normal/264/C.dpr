program problem3;
uses math;

var	n, q, i, j, k: longInt;
	t, a, b: int64;
	v, c: array[ 1..100000 ] of longInt;
	dp: array[ 1..100000 ] of int64;
	ok: array[ 1..100000 ] of boolean;
	val, col: array[ 1..3 ] of int64;

begin
	readln( n, q );
	
	for i := 1 to n do
		read( v[i] );
		
	for i := 1 to n do
		read( c[i] );
		
	for i := 1 to q do
	begin
		fillchar( dp, sizeOf(dp), 0 );
		fillchar( ok, sizeOf(ok), 0 );
		val[1] := 0;	col[1] := 0;
		val[2] := 0;	col[2] := 0;
		
		readln( a, b );
		for j := 1 to n do
		begin
			if ( ok[ c[j] ] ) then
			begin
				dp[ c[j] ] := max( ( dp[ c[j] ] + ( v[j] * a ) ), dp[ c[j] ] );
				dp[ c[j] ] := max( ( ifthen( ( col[1] <> c[j] ), val[1], val[2] ) + ( v[j] * b ) ), dp[ c[j] ] );
			end
			else
			begin
				ok[ c[j] ] := true;
				dp[ c[j] ] := val[1] + ( v[j] * b );
			end;
			
			val[3] := dp[ c[j] ];
			col[3] := c[j];
			for k := 1 to 2 do
				if ( col[k] = c[j] ) then
					val[k] := -1;
					
			for k := 1 to 2 do
				if ( val[3] > val[k] ) then
				begin
					t := val[3];
					val[3] := val[k];
					val[k] := t;
					
					t := col[3];
					col[3] := col[k];
					col[k] := t;
				end;
		end;
		
		writeln( val[1] );
	end;
end.