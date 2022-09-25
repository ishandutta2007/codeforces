program problem7;

var	p: array[ 1..6 ] of longInt;
	n: longInt;
	ans, cnt: int64;

procedure solve( k: longInt );
var	i, j, q, r: longInt;
begin
	if ( k = 0 ) then
	begin
		inc( cnt, 1 );
		for i := 1 to n do
			for j := i + 1 to n do
				if ( p[i] > p[j] ) then
					inc( ans, 1 );
		
		exit();
	end;
	
	for i := 1 to n do
		for j := i to n do
		begin
			q := i;
			r := j;
			while ( q < r ) do
			begin
				p[q] := p[q] xor p[r];
				p[r] := p[q] xor p[r];
				p[q] := p[q] xor p[r];
				
				inc( q );
				dec( r );
			end;
		
			solve( k - 1 );
			
			q := i;
			r := j;
			while ( q < r ) do
			begin
				p[q] := p[q] xor p[r];
				p[r] := p[q] xor p[r];
				p[q] := p[q] xor p[r];
				
				inc( q );
				dec( r );
			end;
		end;
end;

var	k, i: longInt;

begin
	readln( n, k );
	for i := 1 to n do
		read( p[i] );
	
	ans := 0;
	cnt := 0;
	
	solve( k );
	
	writeln( ( ans / cnt ):0:15 );
end.