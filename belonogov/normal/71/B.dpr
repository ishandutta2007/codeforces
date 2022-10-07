uses
  SysUtils;

var
  a: array[1..10000] of longint;
  i, n, k, t, x: longint;

begin
  read(n, k, t);
  x := trunc(n * (t / 100));
  for i := 1 to x do
    a[i] := k;

  a[x + 1] := trunc((t * n * k - (x * k) * 100) / 100);

  for i := 1 to n do
    write(a[i], ' ');

end.