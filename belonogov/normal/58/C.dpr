var
  a: array[-100000..200000] of longint;
  n, i, k, max: longint;

begin
 read(n);
  for i := 1 to n do
  begin
    read(k);
    if i <= n div 2 then inc(a[k - i + 1]);
    if i > n div 2 then inc(a[k - n + i]);
  end;
  max := 0;
  for i := 1 to 200000 do
    if a[i] > max then max := a[i];

  writeln(n - max);  

end.