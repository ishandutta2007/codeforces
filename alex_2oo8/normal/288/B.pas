program problem2;

const md =	1000000007;

function pow( a, p: longInt ): qWord;
var	res: qWord;
begin
	res := 1;
	while ( p > 0 ) do
	begin
		if ( odd(p) ) then
			res := ( res * a ) mod md;
			
		a := ( qWord(a) * a ) mod md;
		p := p div 2;
	end;
	
	exit( res );
end;

var	n, k, ans: longInt;

begin
	readln( n, k );
	
	ans := ( pow( k, k - 1 ) * pow( n - k, n - k ) ) mod md;
	
	writeln( ans );
end.