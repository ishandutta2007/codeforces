program problem1;
uses math;

function f( minSum, maxSum, maxB, maxC: longInt ): int64;
var	a, h, minSum_save: longInt;
	res: int64;
begin
	minSum_save := minSum;

	res := 0;
	for a := 0 to maxSum do
	begin
		inc( minSum, a );
		dec( maxSum, a );
		inc( maxB, a );
		inc( maxC, a );
		
		if ( minSum < 0 ) then
			minSum := 0;
		
		if ( minSum <= maxSum ) and ( maxB + maxC >= minSum ) and ( maxB >= 0 ) and ( maxC >= 0 ) then
		begin
			inc( res, ( maxSum + 1 ) * int64( maxSum + 2 ) div 2 );
			dec( res, minSum * int64( minSum + 1 ) div 2 );
			
			if ( maxB < maxSum ) then
			begin
				h := maxSum - max( minSum, maxB );
				dec( res, h * int64( h + 1 ) div 2 );
				
				if ( maxB < minSum ) then
					dec( res, int64( maxSum - minSum + 1 ) * ( minSum - maxB ) );
			end;
			
			if ( maxC < maxSum ) then
			begin
				h := maxSum - max( minSum, maxC );
				dec( res, h * int64( h + 1 ) div 2 );
				
				if ( maxC < minSum ) then
					dec( res, int64( maxSum - minSum + 1 ) * ( minSum - maxC ) );
			end;
			
			if ( maxB + maxC < maxSum ) then
			begin
				h := maxSum - maxB - maxC;
				
				inc( res, h * int64( h - 1 ) div 2 );
			end;
		end;
		
		minSum := minSum_save;
		inc( maxSum, a );
		dec( maxB, a );
		dec( maxC, a );
	end;
	
	exit( res );
end;

var	a, b, c, l: longInt;
	ans: int64;

begin
	readln( a, b, c, l );
	
	ans := f( a - b - c + 1, l, a - b, a - c );
	ans := ans + f( b - a - c + 1, l, b - a - 1, b - c );
	ans := ans + f( c - a - b + 1, l, c - a - 1, c - b - 1 );
	
	writeln( ans );
end.