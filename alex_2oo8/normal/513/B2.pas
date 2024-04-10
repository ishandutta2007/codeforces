program problem2;

var	n, i, l, r: longInt;
	ans: array[ 1..50 ] of longInt;
	k: int64;

begin
	readln( n, k );
	
	l := 1;
	r := n;
	for i := 1 to n - 1 do
	begin
		if ( k <= int64(1) shl (n - i - 1) ) then
		begin
			ans[l] := i;
			inc( l );
		end
		else
		begin
			ans[r] := i;
			dec( r );
			
			dec( k, int64(1) shl (n - i - 1) );
		end;
	end;
	
	ans[l] := n;
	
	for i := 1 to n do
		write( ans[i], ' ' );
	writeln();
end.