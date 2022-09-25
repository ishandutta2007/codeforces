program problem2;
uses math;

type tEdge = record
				u, v, next: longInt;
			 end;

var q, p: array[1..100000] of longInt;
	h, t, n: longInt;

procedure writeAns( u, v, hi, ti, ii: longInt );
var i, j, cnt: longInt;
begin
	writeln( u, ' ', v );
	
	cnt := 0;
	i := 1;
	while ( cnt < h ) do
	begin
		if ( q[i] = ii ) and ( p[i] = hi ) then
		begin	
			write( i, ' ' );
			inc( cnt );
		end;
		
		inc( i );
	end;
	writeln();
	
	cnt := 0;
	i := 1;
	while ( cnt < t ) do
	begin
		if ( q[i] = ii ) and ( p[i] = ti ) then
		begin
			write( i, ' ' );
			inc( cnt );
		end;
		
		inc( i );
	end;
	writeln();
end;

var m, i, j, k, u, v, cnt1, cnt2: longInt;
	first: array[1..100000] of longInt;
	e: array[1..200000] of tEdge;

begin
	fillchar( first, sizeOf(first), 0 );
	fillchar( q, sizeOf(q), 0 );

	readln( n, m, h, t );
	for i := 1 to m do
	begin
		readln( u, v );
		e[i].u := u;
		e[i].v := v;
		e[i].next := first[u];
		first[u] := i;
		
		e[i+m].u := v;
		e[i+m].v := u;
		e[i+m].next := first[v];
		first[v] := i + m;
	end;
	
	for i := 1 to m do
	begin
		u := e[i].u;
		v := e[i].v;
		
		cnt1 := 0;
		j := first[u];
		while ( j > 0 ) do
		begin
			if ( e[j].v <> v ) then
			begin
				inc( cnt1 );
				q[ e[j].v ] := i;
				p[ e[j].v ] := 0;
				
				if ( cnt1 >= (h+t) ) then
					break;
			end;
			
			j := e[j].next;
		end;
		
		if ( cnt1 >= min( h, t ) ) then
		begin
			if ( cnt1 >= max( h, t ) ) then
				k := max( h, t )
			else
				k := min( h, t );
				
			cnt2 := 0;
			j := first[v];
			while ( j > 0 ) do
			begin
				if ( e[j].v <> u ) and ( q[ e[j].v ] < i ) then
				begin
					inc( cnt2 );
					q[ e[j].v ] := i;
					p[ e[j].v ] := 1;
				end
				else if ( e[j].v <> u ) and ( q[ e[j].v ] = i ) and ( cnt1 > k ) then
				begin
					inc( cnt2 );
					dec( cnt1 );
					p[ e[j].v ] := 1;
				end;
				
				if ( cnt2 >= (h+t-k) ) then
					break;
				
				j := e[j].next;
			end;
			
			if ( cnt2 >= (h+t-k) ) then
			begin
				writeln( 'YES' );
				if ( k = h ) then
					writeAns( u, v, 0, 1, i )
				else
					writeAns( v, u, 1, 0, i );

				halt;
			end;
		end;
	end;
	
	writeln( 'NO' );
end.