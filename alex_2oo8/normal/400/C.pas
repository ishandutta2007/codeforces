program problem3;

procedure cw( var x, y, n, m: longInt );
var	tx, ty, tn, tm: longInt;
begin
	tx := m + 1 - y;
	ty := x;
	tn := m;
	tm := n;
	
	x := tx;
	y := ty;
	n := tn;
	m := tm;
end;

procedure hf( var x, y, n, m: longInt );
begin
	x := n + 1 - x;
end;

var	p, n, m, x, y, z, i, j, xx, yy, nn, mm: longInt;

begin
	readln( m, n, x, y, z, p );
	
	x := x mod 4;
	y := y mod 2;
	z := z mod 4;
	
	for i := 1 to p do
	begin
		readln( yy, xx );
		
		nn := n;
		mm := m;
		
		for j := 1 to x do
			cw( xx, yy, nn, mm );
			
		for j := 1 to y do
			hf( xx, yy, nn, mm );
			
		for j := 1 to 3 * z do
			cw( xx, yy, nn, mm );
			
		writeln( yy, ' ', xx );
	end;
end.