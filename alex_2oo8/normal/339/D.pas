program problem4;

var	n, m, i, j, p, b: longInt;
	f: array[ 0..17, 1..1 shl 17 ] of longInt;
	isOr: boolean;

begin
	readln( n, m );
	
	for i := 1 to (1 shl n) do
		read( f[n][i] );
		
	isOr := true;
	for j := n - 1 downTo 0 do
	begin
		for i := 1 to (1 shl j) do
			if ( isOr ) then
				f[j][i] := f[j+1][2*i-1] or  f[j+1][2*i]
			else
				f[j][i] := f[j+1][2*i-1] xor f[j+1][2*i];
				
		isOr := not isOr;
	end;
	
	for i := 1 to m do
	begin
		readln( p, b );
		
		f[n][p] := b;
		isOr := true;
		for j := n - 1 downTo 0 do
		begin
			p := (p+1) div 2;
			
			if ( isOr ) then
				f[j][p] := f[j+1][2*p-1] or  f[j+1][2*p]
			else
				f[j][p] := f[j+1][2*p-1] xor f[j+1][2*p];
				
			isOr := not isOr;
		end;
		
		writeln( f[0][1] );
	end;
end.