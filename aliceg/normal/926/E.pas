program ideone;
var b : array[1..200005] of longint ;
var n : longint ;
var i, j, jot : longint;
begin
	read(n);
	i := 1;
	for j := 1 to n do begin
		read(b[i]);
		while (i > 1) and (b[i-1] = b[i]) do begin
			b[i - 1] := b[i - 1] + 1;
			i := i - 1;
		end;
		i := i + 1;
	end;
	writeln(i - 1);
	for j := 1 to i - 1 do write(b[j], ' ');
end.