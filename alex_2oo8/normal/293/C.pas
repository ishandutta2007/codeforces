program problem3;

function cnt( const a, b: longInt; const c: qWord ): longInt;
begin
	if ( a = b ) then
	begin
		if ( a = c ) then
			exit( 1 )
		else
			exit( 3 );
	end
	else if ( a = c ) or ( b = c ) then
		exit( 3 )
	else
		exit( 6 );
end;

var	n, c, D, sqrtD, aa, bb: qWord;
	ans, k, a, b, i: longInt;

begin
	readln( n );
	
	if ( n mod 3 > 0 ) then
	begin
		writeln( 0 );
		halt;
	end;
	
	n := n div 3;
	// (a+b)(a+c)(b+c)=n
	// a+b = k
	
	ans := 0;
	k := 2;
	while ( ( k * qWord(k) * k ) <= n ) do
	begin
		if ( n mod k = 0 ) then
		begin
			for a := 1 to (k-1) do
			begin
				b := k - a;
				if ( b < a ) then
					break;
					
				aa := a;
				bb := b;
				c := 0;
// c^2(a+b) + c(a+b)^2 + a^2b + ab^2 - n = 0				
				D := sqr( sqr( aa + bb ) ) - 4 * (aa+bb) * ( sqr(aa) * bb + sqr(bb) * aa - n );

				sqrtD := trunc( sqrt(D) );
				for i := -2 to 2 do
					if ( sqrtD + i > 0 ) and ( sqr( sqrtD + i ) = D ) then
					begin
						D := sqrtD + i - sqr(aa+bb);
						if ( D mod ( 2 * (aa+bb) ) = 0 ) then
							c := D div ( 2 * (aa+bb) );
							
						break;
					end;
				
				if ( c > 0 ) and ( (a+b) <= (a+c) ) and ( (a+b) <= (b+c) ) then
					inc( ans, cnt( a, b, c ) );
			end;
		end;
	
		inc( k );
	end;
	
	writeln( ans );
end.