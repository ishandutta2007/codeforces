program problem6;

type tStr = string[20];

var	names: array[ 1..10000 ] of tStr;
	n: longInt;
	
procedure qsort( l, r: longInt );
var i, j: longInt;
	t, med: tStr;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := names[ l + random(r-l+1) ];
		while ( i <= j ) do
		begin
			while ( names[i] < med ) do
				inc( i );
			while ( names[j] > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				t := names[i];
				names[i] := names[j];
				names[j] := t;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

function find( str: tStr ): longInt;
var l, r, c: longInt;
begin
	l := 1;
	r := n;
	while ( l <> r ) do
	begin
		c := (l+r) div 2;
		if ( names[c] < str ) then
			l := c + 1
		else
			r := c;
	end;
	
	find := l;
end;

var m, i, j, a, b, ans, max: longInt;
	str: array[ 1..5000 ] of ansistring;
	first, k: array[ 1..10000 ] of longInt;
	e: array[ 1..10000, 0..1 ] of longInt;
	f: array[ 1..10000, 1..10000 ] of boolean;

begin
	fillchar( f, sizeOf(f), 0 );
	fillchar( first, sizeOf(first), 0 );

	readln( m );
	for i := 1 to m do
	begin
		readln( str[i] );
		
		names[i] := copy( str[i], 1, ( pos( ' ', str[i] ) - 1 ) );
		names[i+m] := copy( str[i], ( pos( ' ', str[i] ) + 1 ), ( length(str[i]) - pos( ' ', str[i] ) ) );
	end;
	
	qsort( 1, (2*m) );
	
	n := 1;
	for j := 2 to (2*m) do
		if ( names[j] <> names[n] ) then
		begin
			inc( n );
			names[n] := names[j];
		end;
	
	for i := 1 to m do
	begin
		a := find( copy( str[i], 1, ( pos( ' ', str[i] ) - 1 ) ) );
		b := find( copy( str[i], ( pos( ' ', str[i] ) + 1 ), ( length(str[i]) - pos( ' ', str[i] ) ) ) );
		
		e[i][0] := a;
		e[i][1] := first[b];
		first[b] := i;
		
		e[i+m][0] := b;
		e[i+m][1] := first[a];
		first[a] := i + m;
		
		f[a][b] := true;
		f[b][a] := true;
	end;
	
	writeln( n );
	for i := 1 to n do
	begin
		fillchar( k, sizeOf(k), 0 );
		
		j := first[i];
		while ( j > 0 ) do
		begin
			a := first[ e[j][0] ];
			while ( a > 0 ) do
			begin
				inc( k[ e[a][0] ] );
				a := e[a][1];
			end;
			
			j := e[j][1];
		end;
		
		ans := 0;
		max := 0;
		for j := 1 to n do
			if ( not f[i][j] ) and ( j <> i ) then
			begin
				if ( k[j] = max ) then
					inc( ans )
				else if ( k[j] > max ) then
				begin
					max := k[j];
					ans := 1;
				end;
			end;
			
		writeln( names[i], ' ', ans );
	end;
end.