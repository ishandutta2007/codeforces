program problem3;

type	tEdge =	record
					v, next, x: longInt;
				end;

var	first, u, v, ans: array[ 1..200000 ] of longInt;
	e: array[ 1..500000 ] of tEdge;
	vis, ok: array[ 0..200000 ] of boolean;

procedure addEdge( u, v, x: longInt );
const	ee: longInt = 0;
begin
	inc( ee );
	e[ee].v := v;
	e[ee].x := x;
	e[ee].next := first[u];
	first[u] := ee;
end;

function setValue( x, w: longInt ): boolean;
begin
	if ( ans[x] <> -1 ) then
		exit( false );

	if ( u[x] = w ) or ( v[x] = w ) then
		ans[x] := 1
	else
		ans[x] := 0;
	
	exit( true );
end;

function dfs( v, x: longInt ): boolean;
var	i: longInt;
begin
	if ( vis[v] ) then
		exit( true );
	
	vis[v] := true;
	i := first[v];
	while ( i > 0 ) do
	begin
		if ( e[i].x <> x ) then
		begin
			if ( dfs( e[i].v, e[i].x ) ) then
				ok[v] := ok[v] or setValue( e[i].x, v );
		end;
	
		i := e[i].next;
	end;
	
	if ( ok[v] ) then
		exit( true );
	
	if ( x <> 0 ) then
	begin
		setValue( x, v );
		ok[v] := true;
	end;
	
	exit( false );
end;

var	n, m, i, j, k, x, y: longInt;

begin
	readln( n, m );
	for i := 1 to n do
	begin
		read( k );
		for j := 1 to k do
		begin
			read( x );
			
			y := 1;
			if ( x < 0 ) then
			begin
				x := -x;
				y := -1;
			end;
			
			if ( u[x] = 0 ) then
				u[x] := y * i
			else
				v[x] := y * i;
		end;
	end;
	
	fillchar( ok, sizeOf(ok), false );
	fillchar( vis, sizeOf(vis), false );
	
	for i := 1 to m do
		ans[i] := -1;
	
	for i := 1 to m do
		if ( u[i] * int64( v[i] ) < 0 ) then
		begin
			addEdge( abs( u[i] ), abs( v[i] ), i );
			addEdge( abs( v[i] ), abs( u[i] ), i );
		end
		else
		begin
			if ( u[i] < 0 ) then
				ans[i] := 0
			else
				ans[i] := 1;
			
			ok[ abs( u[i] ) ] := true;
			ok[ abs( v[i] ) ] := true;
		end;
	
	for i := 1 to n do
		if ( not vis[i] ) then
			dfs( i, 0 );
	
	for i := 1 to n do
		if ( not ok[i] ) then
		begin
			writeln( 'NO' );
			
			halt;
		end;
	
	writeln( 'YES' );
	for i := 1 to m do
	begin
		if ( ans[i] = -1 ) then
			ans[i] := 0;
	
		write( ans[i] );
	end;
	
	writeln();
end.