program probllem1;
uses math;

function checkWin( hpy, atky, defy, hpm, atkm, defm: longInt ): boolean;
var	dy, dm: longInt;
begin
	dy := max( 0, atkm - defy );
	dm := max( 0, atky - defm );
	
	if ( dm = 0 ) then
		exit( false )
	else if ( dy = 0 ) then
		exit( true )
	else
		exit( ( hpy + dy - 1 ) div dy > ( hpm + dm - 1 ) div dm );
end;

var	hpy, atky, defy, hpm, atkm, defm, a, d, h, i, j, k, ans, curr, l, r: longInt;

begin
	readln( hpy, atky, defy, hpm, atkm, defm, h, a, d );
	
	ans := max( 0, atkm - defy ) * d + max( 0, defm + 1 - atky ) * a;
	
	for j := 0 to ans do
	begin
		if ( a * j >= ans ) then
			break;
		
		for k := 0 to ans do
		begin
			if ( a * j + d * k >= ans ) then
				break;
			
			l := 0;
			r := ans;
			while ( l < r ) do
			begin
				i := ( l + r ) div 2;
				
				if ( checkWin( hpy + i, atky + j, defy + k, hpm, atkm, defm ) ) then
					r := i
				else
					l := i + 1;
			end;
			
			i := l;
			curr := h * i + a * j + d * k;
			if ( checkWin( hpy + i, atky + j, defy + k, hpm, atkm, defm ) ) and ( curr < ans ) then
				ans := curr;
		end;
	end;
	
	writeln( ans );
end.