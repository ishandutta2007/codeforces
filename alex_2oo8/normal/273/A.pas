program problem1;
uses math;

type	tListRec =	record
						next, x: longInt;
						val: int64;
					end;

var	n, m, l, i, j, w, h, r: longInt;
	list: array[ 1..1000000 ] of tListRec;
	ans: int64;

begin
	readln( n );
	for i := 1 to n do
	begin
		read( list[i].val );
		list[i].next := i + 1;
		list[i].x := i;
	end;
	l := 1;
	r := n;
	
	readln( m );
	for i := 1 to m do
	begin
		readln( w, h );
		if ( w < list[l].x ) then
		begin
			writeln( list[l].val );
			
			inc( r );
			list[r].x := w;
			list[r].val := list[l].val + h;
			list[r].next := l;
			l := r;			
		end
		else
		begin
			j := l;
			ans := list[l].val;
			while ( list[j].x < w ) do
			begin
				j := list[j].next;
				ans := max( ans, list[j].val );
			end;
			
			writeln( ans );
			
			inc( r );
			list[r].val := ans + h;
			list[r].x := w;
			list[r].next := j;
			l := r;
		end;
	end;
end.