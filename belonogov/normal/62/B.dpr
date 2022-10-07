var
  a: array[1..30, 0..100000] of longint;
  b: array[1..100000] of string;
  n, k, i, j, x, d: longint;
  f: int64;
  s: string;

function min(x, y: longint): longint;
begin
  if x > y then min := y
  else
    min := x;

end;

function bin(k, i: longint): longint;
var
  l, r: longint;

begin
  l := 0;
  r := a[k, 0];
  while l < r - 1 do
    if a[k, (r + l) div 2] < i then
      l := (r + l) div 2
    else
      r := (r + l) div 2;

  bin := r;
end;

begin
 readln(n, k);
  readln(s);
  for i := 1 to n do
    readln(b[i]);

  x := length(s);
  for i := 1 to x do
  begin
    k := ord(s[i]) - ord('a') + 1;
    inc(a[k, 0]);
    a[k, a[k, 0]] := i;
  end;
  {//////////////////////}
  for i := 1 to n do
  begin
    x := length(b[i]);
    f := 0;
    for j := 1 to x do
    begin
      d := ord(b[i, j]) - ord('a') + 1;
      if a[d, 0] = 0 then
        inc(f, x)
      else
      begin
        k := bin(d, j);
        if k > 1 then
          f := f + min(abs(a[d, k] - j), abs(a[d, k - 1] - j))
        else
          f := f + abs(a[d, k] - j);
      end;

    end;
    writeln(f);
  end;

end.