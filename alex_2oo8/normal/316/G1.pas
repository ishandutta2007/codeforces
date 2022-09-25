program problem7;

type	tRule =	record
					p: ansistring;
					l, r: longInt;
				end;

var	rules: array[ 1..10 ] of tRule;
	next: array[ 0..100000, 'a'..'z' ] of longInt;
	isWord: array[ 0..100000 ] of boolean;
	ans, w, ruleCnt: longInt;
	str: ansistring;
	kmp: array[ 1..1000 ] of longInt;
	
function check( const t: ansistring ): boolean;
var	i, len, v: longInt;
begin
	v := 0;
	len := length( t );
	for i := 1 to len do
		if ( next[v][ t[i] ] = 0 ) then
			exit( false )
		else
			v := next[v][ t[i] ];
			
	exit( isWord[v] );
end;

procedure add( const t: ansistring );
var	i, len, v: longInt;
begin
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
	end;
	
	isWord[v] := true;
end;

function checkRule( const t: ansistring; r: longInt ): boolean;
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
	
	exit( ( cnt >= rules[r].l ) and ( cnt <= rules[r].r ) );
end;

function good( const t: ansistring ): boolean;
var	i: longInt;
begin
	for i := 1 to ruleCnt do
		if ( not checkRule( t, i ) ) then
			exit( false );
			
	exit( true );
end;

var	s, t: ansistring;
	i, j, len: longInt;
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
		for j := i to len do
		begin
			t := copy( s, i, j - i + 1 );
			
			if ( not check( t ) ) and ( good( t ) ) then
			begin
				add( t );
				
				inc( ans );
			end;
		end;
		
	writeln( ans );
end.