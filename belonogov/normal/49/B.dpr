uses
  Math;

var
  i, a, b, la, lb, m, r, d: longint;
  a1: array[1..100] of longint;
  b1: array[1..100] of longint;
  sum: array[1..100] of longint;
begin
  read(a, b);
  m := 0;
  la := 0;
  lb := 0;
  d := 0;
  while a > 0 do
  begin
    inc(la);
    a1[la] := a mod 10;
    a := a div 10;
    if a1[la] > m then m := a1[la];
  end;

  while b > 0 do
  begin
    inc(lb);
    b1[lb] := b mod 10;
    b := b div 10;
    if b1[lb] > m then m := b1[lb];
  end;
  r := max(la, lb);
  inc(m);
  for i := 1 to r + 1 do
  begin
    sum[i] := (a1[i] + b1[i] + d) mod m;
    d := (a1[i] + b1[i] + d) div  m;
  end;
  if sum[r + 1] <> 0 then writeln(r + 1) else writeln(r);
end.