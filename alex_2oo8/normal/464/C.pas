program problem3;

const	md =	1000000007;

type	tRec =	record
					d: char;
					t: ansistring;
				end;

var	n, i, j, o, v, len: longInt;
	s: ansistring;
	c: char;
	offset, val: array[ '0'..'9' ] of longInt;
	a: array[ 0..100000 ] of tRec;

begin
	for c := '0' to '9' do
	begin
		offset[c] := 10;
		val[c] := ord( c ) - ord( '0' );
	end;
	
	readln( s );
	readln( n );
	for i := 1 to n do
		readln( a[i].d, c, c, a[i].t );
	
	a[0].d := '0';
	a[0].t := s;
	
	for i := n downto 0 do
	begin
		o := 1;
		v := 0;
		len := length( a[i].t );
		for j := len downto 1 do
		begin
			v := ( v + int64(o) * val[ a[i].t[j] ] ) mod md;
			o := ( int64(o) * offset[ a[i].t[j] ] ) mod md;
		end;
		
		val[ a[i].d ] := v;
		offset[ a[i].d ] := o;
	end;
	
	writeln( val['0'] );
end.