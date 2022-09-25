program problem7;

type	tRule =	record
					p: ansistring;
					l, r: longInt;
				end;

var	rules: array[ 1..10 ] of tRule;
	next: array[ 0..2000000, 'a'..'z' ] of longInt;
	isWord: array[ 0..2000000 ] of boolean;
	ans, w, ruleCnt: longInt;
	str: ansistring;
	kmp: array[ 1..5000 ] of longInt;
	
function add( const t: ansistring; q: longInt ): longInt;
var	i, len, v, res: longInt;
begin
	res := 0;
	v := 0;
	len := length( t );
	for i := 1 to len do
	begin
		if ( next[v][ t[i] ] = 0 ) then
		begin
			inc( w );
			next[v][ t[i] ] := w;
		end;
		
		v := next[v][ t[i] ];
		
		if ( i >= q ) then
		begin
			if ( not isWord[v] ) then
			begin
				inc( res );
				isWord[v] := true;
			end;
		end;
	end;
			
	exit( res );
end;

function checkMinRule( const t: ansistring; r: longInt ): boolean;
var	i, j, len, lenT, cnt: longInt;
begin
	str := t + '@' + rules[r].p;
	len := length( str );
	lenT := length( t );
	cnt := 0;
	
	kmp[1] := 0;
	for i := 2 to len do
	begin
		j := kmp[i-1];
		while ( j > 0 ) and ( str[i] <> str[j+1] ) do
			j := kmp[j];
			
		if ( str[i] = str[j+1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
			
		if ( kmp[i] = lenT ) then
			inc( cnt );
	end;
	
	exit( ( cnt >= rules[r].l ) );
end;

function checkMaxRule( const t: ansistring; r: longInt ): boolean;
var	i, j, len, lenT, cnt: longInt;
begin
	str := t + '@' + rules[r].p;
	len := length( str );
	lenT := length( t );
	cnt := 0;
	
	kmp[1] := 0;
	for i := 2 to len do
	begin
		j := kmp[i-1];
		while ( j > 0 ) and ( str[i] <> str[j+1] ) do
			j := kmp[j];
			
		if ( str[i] = str[j+1] ) then
			kmp[i] := j + 1
		else
			kmp[i] := 0;
			
		if ( kmp[i] = lenT ) then
			inc( cnt );
	end;
	
	exit( ( cnt <= rules[r].r ) );
end;

function goodMin( const t: ansistring ): boolean;
var	i: longInt;
begin
	for i := 1 to ruleCnt do
		if ( not checkMinRule( t, i ) ) then
			exit( false );
			
	exit( true );
end;

function goodMax( const t: ansistring ): boolean;
var	i: longInt;
begin
	for i := 1 to ruleCnt do
		if ( not checkMaxRule( t, i ) ) then
			exit( false );
			
	exit( true );
end;

var	s, t: ansistring;
	i, j, len, l, r, m, ll, rr: longInt;
	c: char;

begin
	readln( s );
	len := length(s);

	readln( ruleCnt );
	for i := 1 to ruleCnt do
	begin
		rules[i].p := '';
		
		read( c );
		while ( c <> ' ' ) do
		begin
			rules[i].p := rules[i].p + c;
			read( c );
		end;
		
		readln( rules[i].l, rules[i].r );
	end;
	
	ans := 0;
	for i := 1 to len do
	begin
		l := i;
		r := len;
		
		if ( not goodMax( copy( s, i, len - i + 1 ) ) ) or ( not goodMin( copy( s, i, 1 ) ) ) then
			continue;
		
		while ( l < r ) do
		begin
			m := ( l + r ) div 2;
			if ( goodMax( copy( s, i, m - i + 1 ) ) ) then
				r := m
			else
				l := m + 1;
		end;
		
		ll := l;
		
		l := i;
		r := len;
		while ( l < r ) do
		begin
			m := ( l + r + 1 ) div 2;
			if ( goodMin( copy( s, i, m - i + 1 ) ) ) then
				l := m
			else
				r := m - 1;
		end;
		
		rr := l;
		
		if ( ll <= rr ) then
			inc( ans, add( copy( s, i, rr - i + 1 ), ll - i + 1 ) );
	end;
		
	writeln( ans );
end.