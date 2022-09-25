program problem2;

function f( s: ansistring ): ansistring;
var	p, q: ansistring;
	l: longInt;
begin
	l := length(s);
	
	if ( odd(l) ) then
		exit( s );
	
	p := f( copy( s, 1, l div 2 ) );
	q := f( copy( s, l div 2 + 1, l div 2 ) );
	
	if ( p < q ) then
		exit( p + q )
	else
		exit( q + p );
end;

var	s, t: ansistring;

begin
	readln( s );
	readln( t );
	
	if ( f(s) = f(t) ) then
		writeln( 'YES' )
	else
		writeln( 'NO' );
end.