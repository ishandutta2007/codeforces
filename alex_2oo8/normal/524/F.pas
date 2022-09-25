program problem6;
uses math;

var	s, t: ansistring;
	n, i, j, k, cntOpen, cntClose, c, ci, li: longInt;
	m, id, r: array[ 0..1, 1..2000000 ] of longInt;
	sum, mnPref, mnSuff: array[ 0..1000001 ] of longInt;
	bufIn, bufOut: array[ 1..1 shl 16 ] of byte;

begin
	setTextBuf( input, bufIn );
	setTextBuf( output, bufOut );
	
	readln( t );
	
	s := t + t;
	
	n := length( s );
	
	cntOpen := 0;
	cntClose := 0;
	for i := 1 to n do
		if ( s[i] = '(' ) then
			inc( cntOpen )
		else
			inc( cntClose );
	
	r[0][1] := 0;
	r[0][2] := cntOpen;
	
	for i := 1 to n do
		if ( s[i] = '(' ) then
		begin
			id[0][i] := 1;
			inc( r[0][1] );
			m[0][ r[0][1] ] := i;
		end
		else
		begin
			id[0][i] := 2;
			inc( r[0][2] );
			m[0][ r[0][2] ] := i;
		end;
	
	for i := 1 to 21 do
	begin
		ci := i and 1;
		li := ci xor 1;
	
		r[ci][1] := 0;
		for j := 2 to id[li][ m[li][n] ] do
			r[ci][j] := r[li][j - 1];
		
		for j := 1 to n do
			if ( m[li][j] > 1 shl (i - 1) ) then
			begin
				k := m[li][j] - 1 shl (i - 1);
				
				inc( r[ci][ id[li][k] ] );
				m[ci][ r[ci][ id[li][k] ] ] := k;
			end;
		
		for k := max( 1, n - 1 shl (i - 1) + 1 ) to n do
		begin
			inc( r[ci][ id[li][k] ] );
			m[ci][ r[ci][ id[li][k] ] ] := k;
		end;
		
		k := 0;
		for j := 1 to n do
		begin
			if ( j = 1 ) or ( id[li][ m[ci][j] ] <> id[li][ m[ci][j - 1] ] ) or ( m[ci][j - 1] + 1 shl (i - 1) > n ) or ( id[li][ m[ci][j] + 1 shl (i - 1) ] <> id[li][ m[ci][j - 1] + 1 shl (i - 1) ] ) then
				inc( k );
			
			r[ci][k] := j;
			id[ci][ m[ci][j] ] := k;
		end;
	end;
	
	n := n div 2;
	cntOpen := cntOpen div 2;
	cntClose := cntClose div 2;
	
	sum[0] := 0;
	mnPref[0] := 111111;
	for i := 1 to n do
	begin
		if ( s[i] = '(' ) then
			sum[i] := sum[i - 1] + 1
		else
			sum[i] := sum[i - 1] - 1;
		
		mnPref[i] := min( mnPref[i - 1], sum[i] );
	end;
	
	mnSuff[n + 1] := 111111;
	for i := n downto 1 do
		mnSuff[i] := min( mnSuff[i + 1], sum[i] );
	
	if ( cntOpen > cntClose ) then
		c := 0
	else
		c := -( cntClose - cntOpen );
	
	for i := 1 to 2 * n do
		if ( m[1][i] <= n ) then
		begin
			k := m[1][i];
			
			if ( mnSuff[k] - sum[k - 1] < c ) then
				continue;
			
			if ( mnPref[k - 1] + sum[n] - sum[k - 1] < c ) then
				continue;
			
			for j := 1 to cntClose - cntOpen do
				write( '(' );
			
			write( copy( s, k, n - k + 1 ) );
			if ( k > 1 ) then
				write( copy( s, 1, k - 1 ) );
			
			for j := 1 to cntOpen - cntClose do
				write( ')' );
		
			writeln();
			
			break;
		end;
end.