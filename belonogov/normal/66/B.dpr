var
  

rez, a: array[0..1000] of longint;
  i, l, r, n, max: longint;

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  for i := 1 to n do
  begin
    l := i;
    r := i;
    while (a[l] >= a[l - 1]) and (l > 1) do
      dec(l);

    while (a[r] >= a[r + 1]) and (r < n) do
      inc(r);

    rez[i] := r - l + 1;
  end;
  max := rez[1];
  for i := 1 to n do
    if rez[i] > max then max := rez[i];

  writeln(max);

end.