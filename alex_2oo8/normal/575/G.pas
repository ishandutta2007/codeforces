program problem7;

type	tEdge = 	record
						v, next: longInt;
					end;

var	first: array[ 1..100000, 0..9 ] of longInt;
	p, eq, prev, prevD: array[ 1..100000 ] of longInt;
	e: array[ 1..200000 ] of tEdge;

procedure addEdge( u, v, l: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].next := first[u][l];
	first[u][l] := ee;
end;

function dsu_get( v: longInt ): longInt;
begin
	if ( p[v] <> v ) then
		p[v] := dsu_get( p[v] );
	
	exit( p[v] );
end;

procedure dsu_merge( u, v: longInt );
begin
	p[ dsu_get( u ) ] := dsu_get( v );
end;

procedure writePath( v, len: longInt );
begin
	inc( len );

	if ( v = 1 ) then
	begin
		writeln();
		writeln( len );
		write( 0 );
		
		exit();
	end;
	
	write( prevD[v] );
	writePath( prev[v], len );
	write( ' ', v - 1 );
end;

var	n, m, i, j, k, u, v, l, r, ll, rr, len, q: longInt;
	s, z: array[ 1..100000 ] of longInt;
	ok: boolean;

begin
	readln( n, m );
	for i := 1 to n do
	begin
		p[i] := i;
		prev[i] := -1;
		eq[i] := n + 42;
		z[i] := 0;
	end;
	
	for i := 1 to m do
	begin
		readln( u, v, l );
		
		inc( u );
		inc( v );
		
		addEdge( u, v, l );
		addEdge( v, u, l );
		
		if ( l = 0 ) then
			dsu_merge( u, v );
	end;
	
	prev[1] := 0;
	
	l := 1;
	r := 1;
	s[1] := 1;
	while ( l <= r ) do
	begin
		ll := l;
		rr := r;
		
		ok := false;
		for i := ll to rr do
			if ( dsu_get( s[i] ) = dsu_get( n ) ) then
				ok := true;
		
		if ( ok ) then
			break;
		
		for i := 0 to 9 do
			for j := ll to rr do
			begin
				k := first[ s[j] ][i];
				while ( k > 0 ) do
				begin
					if ( prev[ e[k].v ] = -1 ) then
					begin
						prev[ e[k].v ] := s[j];
						prevD[ e[k].v ] := i;
						
						inc( r );
						s[r] := e[k].v;
					end;
					
					k := e[k].next;
				end;
			end;
		
		l := rr + 1;
	end;
	
	eq[1] := 0;
	prevD[1] := -1;
	for i := 2 to r do
		if ( prevD[ s[i] ] = prevD[ s[i - 1] ] ) and ( eq[ prev[ s[i] ] ] = eq[ prev[ s[i - 1] ] ] ) then
			eq[ s[i] ] := eq[ s[i - 1] ]
		else
			eq[ s[i] ] := eq[ s[i - 1] ] + 1;
	
	q := 1;
	while ( dsu_get( s[q] ) <> dsu_get( n ) ) do
		inc( q );
	
	q := eq[ s[q] ];
	
	len := -1;
	l := 1;
	r := 1;
	s[1] := n;
	z[n] := -1;
	
	while ( l <= r ) do
	begin
		inc( len );
	
		ll := l;
		rr := r;
		
		v := s[ll];
		for i := ll to rr do
			if ( eq[ s[i] ] < eq[v] ) then
				v := s[i];
		
		if ( eq[v] = q ) then
		begin
			if ( v = 1 ) then
				write( 0 );
		
			writePath( v, len );
			
			while ( v <> n ) do
			begin
				v := z[v];
				write( ' ', v - 1 );
			end;
			
			writeln();
			
			break;
		end;
		
		for i := ll to rr do
		begin
			k := first[ s[i] ][0];
			while ( k > 0 ) do
			begin
				if ( z[ e[k].v ] = 0 ) then
				begin
					z[ e[k].v ] := s[i];
					
					inc( r );
					s[r] := e[k].v;
				end;
			
				k := e[k].next;
			end;
		end;
		
		l := rr + 1;
	end;
end.