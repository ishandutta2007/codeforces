var
  a: array[1..1000, 1..2] of longint;
  sum, n, m, i, j, t, c, l, r: longint;

begin
  read(n, m);
  for i := 1 to n do
    a[i, 1] := 10000000;

  for i := 1 to m do
  begin
    read(l, r, t, c);
    for j := l to r do
      if a[j, 1] > t then
      begin
        a[j, 1] := t;
        a[j, 2] := c;
      end;
  end;
  sum := 0;
  for i := 1 to n do
    sum := sum + a[i, 2];

  writeln(sum);  

end.