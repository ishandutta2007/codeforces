program problem6;

type	tArr =	array[ 1..1000000 ] of longInt;

var	paired: array[ 'a'..'z', 'a'..'z' ] of boolean;
	paired_cnt: array[ 'a'..'z' ] of longInt;

function addPair( p, q: char ): boolean;
begin
	if ( paired[p][q] ) then
		exit( true );
	
	paired[p][q] := true;
	paired[q][p] := true;
	
	inc( paired_cnt[p] );
	if ( p <> q ) then
		inc( paired_cnt[q] );
	
	exit( paired_cnt[p] + paired_cnt[q] = 2 );
end;

procedure remPair( p, q: char );
begin
	if ( not paired[p][q] ) then
		exit();
	
	paired[p][q] := false;
	paired[q][p] := false;
	
	dec( paired_cnt[p] );
	if ( p <> q ) then
		dec( paired_cnt[q] );
end;

procedure generate( const s: ansistring; c: char; var res: tArr; var resN: longInt );
const	ololo: longInt = 1234567;
var	i, last, len: longInt;
begin
	last := -1;
	len := length(s);
	for i := 1 to len do
		if ( s[i] = c ) then
		begin
			if ( last > -1 ) then
			begin
				inc( resN );
				res[resN] := i - last;
			end;
			
			last := i;
		end;
	
	if ( last > -1 ) then
	begin
		inc( resN );
		res[resN] := ololo;
		inc( ololo );
	end;
end;

procedure calc_kmp( const str: tArr; const len: longInt; var kmp: tArr );
var	i, j: longInt;
begin
	kmp[1] := 0;
	for i := 2 to len do
	begin
		j := kmp[i - 1];
		while ( j > 0 ) and ( str[i] <> str[j + 1] ) do
			j := kmp[j];
		
		if ( str[i] = str[j + 1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
	end;
end;

var	n, m, i, j, str_len, temp_len, offset, ans: longInt;
	str, where, temp, kmp, ans_arr: tArr;
	match: array[ 'a'..'z', 1..1000000 ] of boolean;
	first: array[ 'a'..'z' ] of longInt;
	s, t: ansistring;
	ok: boolean;
	c: char;

begin
	readln( n, m );
	readln( s );
	readln( t );
	
	str_len := 0;
	for c := 'a' to 'z' do
	begin
		j := str_len + 1;
		generate( s, c, str, str_len );
		
		for i := 1 to n do
			if ( s[i] = c ) then
			begin
				where[i] := j;
				inc( j );
			end;
	end;
	
	for c := 'a' to 'z' do
		if ( pos( c, t ) > 0 ) then
		begin
			first[c] := pos( c, t );
		
			temp_len := 0;
			generate( t, c, temp, temp_len );
			offset := temp_len;
			for i := 1 to str_len do
			begin
				inc( temp_len );
				temp[temp_len] := str[i];
			end;
			
			calc_kmp( temp, temp_len, kmp );
			
			for i := 1 to n do
				match[c][i] := ( where[i] + 2 * offset - 2 <= temp_len ) and ( kmp[ where[i] + 2 * offset - 2 ] = offset - 1 );
		end
		else
			first[c] := -1;
	
	ans := 0;
	for i := 1 to n - m + 1 do
	begin
		ok := true;
		for c := 'a' to 'z' do
			if ( first[c] > -1 ) then
			begin
				ok := ok and match[c][ i + first[c] - 1 ];
				ok := ok and addPair( c, s[i + first[c] - 1] );
			end;
		
		if ( ok ) then
		begin
			inc( ans );
			ans_arr[ans] := i;
		end;
		
		for c := 'a' to 'z' do
			if ( first[c] > -1 ) then
				remPair( c, s[i + first[c] - 1] );
	end;
	
	writeln( ans );
	for i := 1 to ans do
		write( ans_arr[i], ' ' );
	
	writeln();
end.