program problem8;

type tStr = string[5];
	 tRec = record
				str: tStr;
				f: longInt;
			end;

var	t: array[1..125000] of tRec;
	e: array[ 1..200, 0..600 ] of longInt;
	p: array[1..125000] of longInt;
	m: longInt;

function DFS( u, par, q: longInt ): boolean;
var i: longInt;
begin
	for i := 1 to e[u][0] do
		if ( e[u][i] <> par ) and ( t[ e[u][i] ].f < q ) then
		begin
			t[ e[u][i] ].f := q;
			
			if ( p[ e[u][i] ] = 0 ) or ( DFS( p[ e[u][i] ], e[u][i], q ) ) then
			begin
				p[ e[u][i] ] := u;
				exit( true );
			end;
		end;
	
	exit( false );
end;
	
procedure add( str: tStr; f: longInt );
begin
	inc( m );
	t[m].str := str;
	t[m].f := f;
end;

procedure qsort( l, r: longInt );
var i, j: longInt;
	med: tStr;
	tmp: tRec;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := t[ l + random(r-l+1) ].str;
		while ( i <= j ) do
		begin
			while ( t[i].str < med ) do
				inc( i );
			while ( t[j].str > med ) do
				dec( j );
				
			if ( i <= j ) then
			begin
				tmp  := t[i];
				t[i] := t[j];
				t[j] := tmp;
				
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( l, j );
		qsort( i, r );
	end;
end;

var n, i, j, k, l, q: longInt;
	s: array[1..200] of string[10];
	ans: array[0..200] of longInt;

begin
	assign( input, 'input.txt' );
	reset( input );
	assign( output, 'output.txt' );
	rewrite( output );

	readln( n );
	for i := 1 to n do
		readln( s[i] );
		
	m := 0;
	for i := 1 to n do
		for j := 1 to length(s[i]) do
		begin
			add( s[i][j], i );
		
			for k := (j+1) to length(s[i]) do
			begin
				add( ( s[i][j] + s[i][k] ), i );
			
				for l := (k+1) to length(s[i]) do
				begin
					add( ( s[i][j] + s[i][k] + s[i][l] ), i );
					
					for q := (l+1) to length(s[i]) do
						add( ( s[i][j] + s[i][k] + s[i][l] + s[i][q] ), i );
				end;
			end;
		end;
		
	qsort( 1, m );
	
	for i := 1 to n do
		e[i][0] := 0;
	
	i := 1;
	j := 1;
	while ( j <= m ) do
	begin
		while ( j <= m ) and ( t[j].str = t[i].str ) do
		begin
			inc( e[ t[j].f ][0] );
			e[ t[j].f ][ e[ t[j].f ][0] ] := i;
			
			inc( j );
		end;
			
		if ( j <= m ) then
		begin
			inc( i );
			t[i] := t[j];
		end;
	end;
	m := i;
	
	for i := 1 to m do
		p[i] := 0;
		
	for i := 1 to n do
		if ( not DFS( i, 0, (n+i) ) ) then
		begin
			writeln( '-1' );
			halt;
		end;
		
	for i := 1 to m do
		ans[ p[i] ] := i;
		
	for i := 1 to n do
		writeln( t[ ans[i] ].str );
	
	close( input );
	close( output );
end.