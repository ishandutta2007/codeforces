program problem5;

const	md =	1000000007;

type	tDpArr = array[ 0..1 shl 7 ] of longInt;

var	g, h: array[ 0..7, 0..1 shl 7 ] of longInt;

procedure calc( var prev, next: tDpArr; d: longInt );
var	i, j, p, res: longInt;
begin
	for i := 0 to (1 shl d) - 1 do
	begin
		g[0][i] := 0;
		h[0][i] := prev[i];
	end;
	
	for j := 1 to d do
	begin
		p := 1 shl (j - 1);
		for i := 0 to (1 shl d) - 1 do
		begin
			res := g[j - 1][i] + g[j - 1][i xor p];
			if ( res >= md ) then
				dec( res, md );
			
			inc( res, h[j - 1][i xor p] );
			if ( res >= md ) then
				dec( res, md );
			
			if ( i and p > 0 ) then
				h[j][i] := res;

			inc( res, h[j - 1][i] );
			if ( res >= md ) then
				dec( res, md );
			
			g[j][i] := res;
			if ( i and p = 0 ) then
				h[j][i] := res;
		end;
	end;
	
	for i := 0 to (1 shl d) - 1 do
		next[i] := h[d][i];
end;

var	i, j, w, p: longInt;
	f: array[ 0..1 ] of tDpArr;

begin
	fillchar( f[0], sizeOf(f[0]), 0 );
	
	f[0][1] := 1;
	p := 0;
	for i := 1 to 7 do
	begin
		read( w );
		
		for j := 1 to w do
		begin
			calc( f[p], f[1 - p], i );
			
			p := 1 - p;
		end;
		
		if ( i < 7 ) then
		begin
			for j := 0 to (1 shl i) - 1 do
			begin
				f[p][ (1 shl i) + j ] := f[p][j];
				f[p][j] := 0;
			end;
		end;
	end;
	
	writeln( f[p][ (1 shl 7) - 1 ] );
end.