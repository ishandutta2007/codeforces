{$O-}

var
  a: array[1..200001] of longint;
  n, i, j: longint;
  r, l, k: extended;

procedure qsort(l, r: longint);
var
  i, j, m, q: longint;
begin
  i := l;
  j := r;
  m := a[(l + r) div 2];
  while i <= j do
  begin
    while a[i] < m do
      inc(i);
    while a[j] > m do
      dec(j);
    if i <= j then
    begin
      q := a[i];
      a[i] := a[j];
      a[j] := q;
      inc(i);
      dec(j);
    end;
  end;
  if l < j then  qsort(l, j);
  if i < r then  qsort(i, r);
end;

function prov(k: extended): boolean;
var
  i, j: longint;
begin
  i := 1;
  j := 2;
  while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);
  i := j;
  while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);

  i := j;
  while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);

  if j > n then
    prov := true
  else
    prov  := false;


end;

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  qsort(1, n);
  l := 0;
  r := (a[n] - a[1]) / 2;
  while r - l > 0.000001 do
    if prov((r + l) / 2) then
      r := (r + l) / 2
    else
      l := (r + l) / 2;

  writeln(r:0:9);
  i := 1;
  j := 2;
  k := r;
  while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);
  write((a[j - 1] + a[i]) / 2:0:9, ' ');
  i := j;

  while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);
  write((a[j - 1] + a[i]) / 2:0:9, ' ');
  i := j;

 while (a[i] + 2 * k >= a[j]) and (j <= n) do
    inc(j);
  write((a[j - 1] + a[i]) / 2:0:9, ' ');
 
end.