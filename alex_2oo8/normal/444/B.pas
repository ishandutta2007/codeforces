program problem2;
uses math;

var	n, d: longInt;
	a, b: array[ 0..100000 ] of longInt;
	x: int64;

procedure swap( var x, y: longInt );
var	c: longInt;
begin
	c := x;
	x := y;
	y := c;
end;
	
function getNextX(): longInt;
begin
    x := (x * 37 + 10007) mod 1000000007;
	
    exit( x );
end;

procedure initAB();
var	i: longInt;
begin
	for i := 0 to n - 1 do
        a[i] := i + 1;

	for i := 0 to n - 1 do
        swap(a[i], a[getNextX() mod (i + 1)]);

	for i := 0 to n - 1 do
	begin
        if (i < d) then
            b[i] := 1
        else
            b[i] := 0;
    end;
	
	for i := 0 to n - 1 do
        swap(b[i], b[getNextX() mod (i + 1)]);
end;

var	i, ans, j: longInt;
	ones, inv_perm: array[ 0..100000 ] of longInt;

begin
	readln( n, d, x );
	
	initAB();
	
	if ( d < 1000 ) then
	begin
		d := 0;
		for i := 0 to n - 1 do
			if ( b[i] = 1 ) then
			begin
				inc( d );
				ones[d] := i;
			end;
	
		for i := 0 to n - 1 do
		begin
			ans := 0;
			for j := 1 to d do
				if ( ones[j] <= i ) then
					ans := max( ans, a[ i - ones[j] ] );
			
			writeln( ans );
		end;
	end
	else
	begin
		for i := 0 to n - 1 do
			inv_perm[ a[i] ] := i;
		
		for i := 0 to n - 1 do
		begin
			j := n;
			while ( j > 0 ) and ( ( inv_perm[j] > i ) or ( b[ i - inv_perm[j] ] = 0 ) ) do
				dec( j );
			
			writeln( j );
		end;
	end;
end.