uses math;
var
  a:array[1..10000]of string;
  n,m:int64;
  i,j:longint;
begin
  readln(n,m);
  for i:=1 to n do
    readln(a[i]);

  for i:=1 to n do
    for j:=2 to m do
      if a[i][j]<>a[i][j-1] then begin writeln('NO'); halt; end;

  for i:=2 to n do
    if a[i][1]=a[i-1][1] then begin writeln('NO'); halt; end;

  writeln('YES');
end.