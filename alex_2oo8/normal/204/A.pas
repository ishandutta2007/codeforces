program problem1;

function calc( r: int64 ): int64;
var	i: longInt;
	res, cnt, rr, a: int64;
begin
	if ( r < 10 ) then
		exit( r );
		
	res := 9;
	a := 11;
	while ( a <= r ) do
	begin
		for i := 1 to 9 do
		begin
			cnt := 0;
			rr := r - ( a * i );
			if ( rr >= (a-1) ) then
				cnt := a div 10
			else if ( rr >= 0 ) then
				cnt := ( rr div 10 ) + 1;
				
			inc( res, cnt );
		end;
		
		a := ( 10 * (a-1) ) + 1;
	end;
	
	exit( res );
end;

var	l, r: int64;

begin
	readln( l, r );
	writeln( calc(r) - calc(l-1) );
end.