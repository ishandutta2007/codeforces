program problem5;

type	tRec =	record
					sum, ans: int64;
					l, r, cnt, lSon, rSon, mid: longInt;
				end;
				
var	t: array[ 0..6000000 ] of tRec;
	w: longInt;
	
function new( l, r: longInt ): longInt;
begin
	inc( w );
	t[w].l := l;
	t[w].r := r;
	t[w].mid := l + ( ( r - int64(l) ) div 2 );
	t[w].lSon := 0;
	t[w].rSon := 0;
	t[w].sum := 0;
	t[w].ans := 0;
	
	exit( w );
end;

procedure update( s, x, d: longInt );
begin
	if ( t[s].l = t[s].r ) then
	begin
		inc( t[s].cnt, d );
		inc( t[s].sum, ( d * int64(x) ) );
		
		exit();
	end;
	
	if ( x <= t[s].mid ) then
	begin
		if ( t[s].lSon = 0 ) then
			t[s].lSon := new( t[s].l, t[s].mid );
			
		update( t[s].lSon, x, d );
	end
	else
	begin
		if ( t[s].rSon = 0 ) then
			t[s].rSon := new( t[s].mid + 1, t[s].r );
			
		update( t[s].rSon, x, d );
	end;
	
	t[s].sum := t[ t[s].lSon ].sum + t[ t[s].rSon ].sum;
	t[s].cnt := t[ t[s].lSon ].cnt + t[ t[s].rSon ].cnt;
	t[s].ans := t[ t[s].lSon ].ans + t[ t[s].rSon ].ans + ( t[ t[s].lSon ].cnt * t[ t[s].rSon ].sum ) - ( t[ t[s].rSon ].cnt * t[ t[s].lSon ].sum );
end;

function calc( s, l, r, cntLeft: longInt; sumLeft: int64; var cnt: longInt; var sum: int64 ): int64;
var	cnt1: longInt;
	sum1, res: int64;
begin
	if ( t[s].l >= l ) and ( t[s].r <= r ) then
	begin
		cnt := t[s].cnt;
		sum := t[s].sum;
		
		exit( t[s].ans + ( cntLeft * sum ) - ( cnt * sumLeft ) );
	end;
	
	res := 0;
	cnt := 0;
	sum := 0;
	if ( t[s].lSon > 0 ) and ( l <= t[ t[s].lSon ].r ) then
	begin
		inc( res, calc( t[s].lSon, l, r, cntLeft, sumLeft, cnt1, sum1 ) );
		inc( cnt, cnt1 );
		inc( sum, sum1 );
	end;
	
	if ( t[s].rSon > 0 ) and ( r >= t[ t[s].rSon ].l ) then
	begin
		inc( res, calc( t[s].rSon, l, r, cntLeft + cnt, sumLeft + sum, cnt1, sum1 ) );
		inc( cnt, cnt1 );
		inc( sum, sum1 );
	end;
	
	exit( res );
end;

var	n, m, i, aaa, l, r, tt: longInt;
	bbb: int64;
	x: array[ 1..100000 ] of longInt;

begin
	w := 0;
	new( -1500000000, 1500000000 );

	readln( n );
	for i := 1 to n do
	begin
		read( x[i] );
		
		update( 1, x[i], +1 );
	end;
	
	readln( m );
	for i := 1 to m do
	begin
		readln( tt, l, r );
		if ( tt = 1 ) then
		begin
			update( 1, x[l], -1 );
			inc( x[l], r );
			update( 1, x[l], +1 );
		end
		else
			writeln( calc( 1, l, r, 0, 0, aaa, bbb ) );
	end;
end.