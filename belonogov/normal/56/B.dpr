var
  a: array[-4..1004] of longint;
  i, j, n, i1: longint;
  check, q: boolean;

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  q := false;


  i := 2;
  if a[1] <> 1 then
    i := 1
  else
    while (a[i] = a[i - 1] + 1) and (i <= n) do
      inc(i);

  if  i > n  then q := true;

  j := n - 1;
  if a[n] <> n then
    j := n
  else
    while (a[j] = a[j + 1] - 1) and (j >= 1) do
      dec(j);

  if j < 1 then q := true;

  check := true;
  for i1 := i to j do
    if i1 <> a[j - i1 + i] then check := false;

  if (check) and (not q) then
    writeln(i, ' ', j)
  else
    writeln(0, ' ', 0);

end.