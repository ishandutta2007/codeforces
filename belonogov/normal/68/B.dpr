var
  a: array[1..100000] of longint;
  i, n, k: longint;
  l, r: extended;

function prov(d: extended): boolean;
var
  up, down: extended;
  i: longint;
begin
  up := 0;
  down := 0;
  for  i := 1 to n do
  begin
    if a[i] > d then up := up + a[i] - d;
    if a[i] < d then down := down + d - a[i];
  end;
  if (up * (100 - k)) / 100  >= down then      
    prov := true
  else
    prov := false;


end;

begin
  read(n, k);
  for i := 1 to n do
    read(a[i]);

  l := a[1];
  for i := 1 to n do
    if a[i] < l then l := a[i];

  r := a[1];
  for i := 1 to n do
    if a[i] > r then r := a[i];


  while r - l > 0.0000001 do
  begin
    if prov((r + l) / 2) then
      l := (l + r) / 2
    else
      r := (l + r) / 2;
  end;

  writeln(l:0:6);

end.