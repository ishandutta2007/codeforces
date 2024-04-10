var
  sum, min, k, kol, i, n: longint;

begin
  read(n);
  sum := 0;
  min := -1;
  kol := 0;
  for i := 1 to n do
  begin
    read(k);
    inc(sum, k);
    if k mod 2 = 1 then inc(kol);
    if (k mod 2 = 1) and ((k < min) or (min = -1)) then min := k;
  end;

  if kol mod 2 = 1 then
    writeln(sum);

  if (kol <> 0) and (kol mod 2 = 0) then
    writeln(sum - min);

  if kol = 0 then
    writeln(0);


end.