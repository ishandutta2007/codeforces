program problem1;

const	l: array[ 1..5 ] of char = ( 'R', 'G', 'B', 'Y', 'W' );

var	a: array[ #0..#255, #0..#255 ] of boolean;
	b, used: array[ #0..#255 ] of boolean;
	ans: longInt;

procedure dfs( x, cur: longInt );
var	i, j: longInt;
	ok: boolean;
	c1, c2, c3, c4: char;
begin
	if ( x = 11 ) then
	begin
		if ( cur < ans ) then
		begin
			ok := true;
			for i := 1 to 5 do
				for c2 := '1' to '5' do
					for j := 1 to 5 do
						for c4 := '1' to '5' do
						begin
							c1 := l[i];
							c3 := l[j];
							
							if ( a[c1][c2] ) and ( a[c3][c4] ) then
							if ( c1 <> c3 ) or ( c2 <> c4 ) then
							begin
								if ( c1 = c3 ) or ( ( not used[c1] ) and ( not used[c3] ) ) then
								begin
									if ( c2 = c4 ) or ( ( not used[c2] ) and ( not used[c4] ) ) then
										ok := false;
								end;
							end;
						end;
			
			if ( ok ) then
				ans := cur;
		end;
	
		exit();
	end;
	
	if ( x < 6 ) then
	begin
		used[ l[x] ] := false;
		
		dfs( x + 1, cur );
		
		used[ l[x] ] := true;
		
		dfs( x + 1, cur + 1 );
	end
	else
	begin
		used[ chr( ord('0') + x - 5 ) ] := false;
		
		dfs( x + 1, cur );
		
		used[ chr( ord('0') + x - 5 ) ] := true;
		
		dfs( x + 1, cur + 1 );
	end;
end;

var	n, i: longInt;
	c1, c2, c3: char;

begin
	fillchar( a, sizeOf(a), 0 );

	readln( n );
	for i := 1 to n do
	begin
		read( c1, c2, c3 );
		
		a[c1][c2] := true;
		b[c1] := true;
		b[c2] := true;
	end;
	
	ans := 10;
	
	dfs( 1, 0 );
	
	writeln( ans );
end.