program problem1;

const	s: array[ 1..8 ] of string = ('vaporeon', 'jolteon', 'flareon', 'espeon', 'umbreon', 'leafeon', 'glaceon', 'sylveon');

var	n: longInt;
	t: string;
	i, j: longInt;

begin
	readln( n );
	readln( t );
	
	for i := 1 to 8 do
		if ( length( s[i] ) = n ) then
		begin
			j := 1;
			while ( j <= n ) and ( ( t[j] = '.' ) or ( t[j] = s[i][j] ) ) do
				inc( j );
			
			if ( j > n ) then
			begin
				writeln( s[i] );
				
				break;
			end;
		end;
end.