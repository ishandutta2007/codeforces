var
  a: array[1..1000, 1..1000] of boolean;
  use: array[1..1000] of boolean;

  k, n, i, kol, m: longint;
  q : boolean;

begin
read(n);
  q := true;
  kol := 0;
  k := 0;
  m := 0;
  while q do
  begin
    k := (k + 1) mod n;
    m := (m + k) mod n;
    if not use[m] then
    begin
      use[m] := true;
      inc(kol);
    end;
    if not a[m, k] then
      a[m, k] := true
    else
      q := false;

    if kol = n then q := false;
  end;


  if kol = n then writeln('YES') else writeln('NO')

end.