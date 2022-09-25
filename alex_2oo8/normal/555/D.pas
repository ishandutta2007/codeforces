program problem4;

var	a, id: array[ 1..200000 ] of longInt;

procedure qsort( l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( a[i] < med ) do
				inc( i );
			
			while ( a[j] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := a[i];
				a[i] := a[j];
				a[j] := t;
				
				t := id[i];
				id[i] := id[j];
				id[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var	n, m, i, j, k, x, l, p, q: longInt;
	y, last, len: array[ 1..200000 ] of longInt;

begin
	readln( n, m );
	for i := 1 to n do
	begin
		read( y[i] );
		
		a[i] := y[i];
		id[i] := i;
	end;
	
	qsort( 1, n );
	
	for i := 1 to m do
	begin
		readln( x, l );
		
		k := 0;
		for j := 20 downto 0 do
			if ( k + 1 shl j <= n ) and ( a[k + 1 shl j] <= y[x] ) then
				inc( k, 1 shl j );
		
		x := 1;
		p := 0;
		while ( l > 0 ) and ( p < 2 ) do
		begin
			if ( last[k] = i ) and ( len[k] > l ) then
				l := l mod ( len[k] - l );
		
			last[k] := i;
			len[k] := l;
			
			if ( x = 1 ) then
			begin
				q := 0;
				for j := 20 downto 0 do
					if ( q + 1 shl j <= n ) and ( a[q + 1 shl j] <= a[k] + l ) then
						inc( q, 1 shl j );
				
				if ( q = k ) then
					inc( p )
				else
				begin
					dec( l, a[q] - a[k] );
					k := q;
					p := 0;
				end;
			end
			else
			begin
				q := 0;
				for j := 20 downto 0 do
					if ( q + 1 shl j <= n ) and ( a[q + 1 shl j] < a[k] - l ) then
						inc( q, 1 shl j );
				
				inc( q );
				if ( q = k ) then
					inc( p )
				else
				begin
					dec( l, a[k] - a[q] );
					k := q;
					p := 0;
				end;
			end;
			
			x := 1 - x;
		end;
		
		writeln( id[k] );
	end;
end.