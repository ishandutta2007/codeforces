program problem3;

var	isPrime: array[ 1..20000 ] of boolean;
	a, p, dsu: array[ 1..200 ] of longInt;
	vis: array[ 1..200 ] of boolean;
	n: longInt;
	
function dsu_get( v: longInt ): longInt;
begin
	if ( dsu[v] <> v ) then
		dsu[v] := dsu_get( dsu[v] );
	
	exit( dsu[v] );
end;

procedure dsu_merge( u, v: longInt );
begin
	u := dsu_get(u);
	v := dsu_get(v);
	
	dsu[v] := u;
end;

function dfs( v: longInt ): boolean;
var	i: longInt;
begin
	if ( vis[v] ) then
		exit( false );
	
	vis[v] := true;
	for i := 1 to n do
		if ( isPrime[ a[i] + a[v] ] ) and ( p[v] <> i ) and ( ( p[i] = 0 ) or ( dfs( p[i] ) ) ) then
		begin
			p[i] := v;
			
			exit( true );
		end;
	
	exit( false );
end;

var	m, i, j, k: longInt;

begin
	fillchar( isPrime, sizeOf(isPrime), 1 );

	isPrime[1] := false;
	for i := 2 to 20000 do
		for j := 2 to 20000 div i do
			isPrime[i * j] := false;
	
	readln( n );
	for i := 1 to n do
		read( a[i] );
	
	for i := 1 to n do
	begin
		fillchar( vis, sizeOf(vis), 0 );
	
		if ( not dfs( i ) ) then
		begin
			writeln( 'Impossible' );
			
			halt;
		end;
	end;
	
	for i := 1 to n do
		dsu[i] := i;
	
	for i := 1 to n do
		dsu_merge( i, p[i] );
	
	m := 0;
	for i := 1 to n do
		if ( dsu_get(i) = i ) then
			inc( m );
	
	writeln( m );
	for i := 1 to n do
		if ( dsu_get(i) = i ) then
		begin
			k := 0;
			for j := 1 to n do
				if ( dsu_get(j) = i ) then
					inc( k );
			
			write( k, ' ', i );
		
			j := p[i];
			while ( j <> i ) do
			begin
				write( ' ', j );
			
				j := p[j];
			end;
			writeln();
		end;
end.