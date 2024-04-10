program problem3;

type tRec = record
				sum, c: longInt;
				arr: array[ 1..50 ] of longInt;
			end;

var n, m, i, j, k, l, x: longInt;
	a: array[ 1..50 ] of longInt;
	ans: array[ 0..2550 ] of tRec;
	ok: boolean;

begin
	readln( n, m );
	for i := 1 to n do
		read( a[i] );
		
	k := 0;
	ans[0].sum := 0;
	ans[0].c := 0;
	for i := 1 to n do
	begin
		x := 1;
		for j := 0 to k do
		begin
			ans[k+x].sum := ans[j].sum + a[i];
			ok := true;
			for l := 1 to k do
				if ( ans[l].sum = ans[k+x].sum ) then
					ok := false;
					
			if ( ok ) then
			begin
				ans[k+x].c := ans[j].c + 1;
				ans[k+x].arr := ans[j].arr;
				ans[k+x].arr[ ans[k+x].c ] := a[i];
				inc( x );
			end;
			
			if ( (k+x-1) >= m ) then
				break;
		end;
		k := k + x - 1;
	
		if ( k >= m ) then
			break;
	end;
	
	for i := 1 to m do
	begin
		write( ans[i].c );
		for j := 1 to ans[i].c do
			write( ' ', ans[i].arr[j] );
		writeln();
	end;
end.