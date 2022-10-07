var
  a: array[1..1000] of longint;
  n, m: int64;
  i, x, kol, max: longint;

begin
  read(n);
  for i := 1 to n do
  begin
    read(x);
    inc(a[x]);
  end;
  kol := 0;
  max := 0;
  for i := 1 to 1000 do
  begin
    if a[i] <> 0 then inc(kol);
    if a[i] > max then max := a[i];
  end;
  write(max, ' ', kol);

end.