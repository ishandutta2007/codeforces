uses math;
var
  a,b:array[1..1000]of longint;
  n,ans:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  for i:=1 to 100000*n do
    for j:=1 to n do
      if i mod a[j]=b[j] then
        begin
          inc(ans);
          break;
        end;
  writeln(ans/(100000*n):0:5);
end.