var
  a: array[1..100] of longint;
  n, i, k, kol, x: longint;

begin
   read(n, k);
  for i := 1 to n do
  begin
    read(x);
    inc(a[x]);
  end;
  kol := 0;
  while a[k] <> n do
  begin
    inc(kol);
    for i := k - 1 downto 1 do
      if a[i] > 0 then
      begin
        inc(a[i + 1]);
        dec(a[i]);
      end;
  end;

  writeln(kol);


end.