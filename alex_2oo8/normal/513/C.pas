program problem3;
uses math;

var	n, i, j, k, p: longInt;
	l, r: array[ 1..5 ] of longInt;
	f: array[ 0..5, 0..5 ] of extended;
	ans: extended;

begin
	readln( n );
	for i := 1 to n do
		readln( l[i], r[i] );
	
	ans := 0.0;
	for i := 1 to n do
		for j := 1 to r[i] do
		begin
			f[0][0] := 1.0;
			for k := 1 to n do
			begin
				if ( k = i ) then
				begin
					move( f[k - 1], f[k], sizeOf( f[k] ) );
					
					continue;
				end;
				
				for p := 0 to n do
					f[k][p] := 0.0;
				
				f[k][0] := f[k - 1][0] * max( min( r[k] + 1, j ) - l[k], 0 ) / ( r[k] - l[k] + 1 );
				if ( l[k] <= j ) and ( j <= r[k] ) then
				begin
					for p := 1 to n do
						f[k][p] := ( f[k - 1][p] * ( j - l[k] ) + f[k - 1][p - 1] ) / ( r[k] - l[k] + 1 )
				end
				else
				begin
					for p := 1 to n do
						f[k][p] := f[k - 1][p] * max( min( r[k] + 1, j ) - l[k], 0 ) / ( r[k] - l[k] + 1 );
				end;
			end;
			
			for k := 1 to n do
			begin
				ans := ans + f[n][k] * j * ( r[i] - max( j, l[i] - 1 ) ) / ( r[i] - l[i] + 1 );
				
				if ( j >= l[i] ) then
					ans := ans + f[n][k] * j / ( ( r[i] - l[i] + 1 ) * (k + 1) );
			end;
		end;
	
	writeln( ans:0:15 );
end.