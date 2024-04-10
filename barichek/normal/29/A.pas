uses math;
var
  a,b:array[1..10000]of longint;
  n:int64;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i],b[i]);

  for i:=1 to n do
    for j:=1 to n do
      if (a[j]+b[j]=a[i]) and (a[i]+b[i]=a[j]) then begin writeln('YES'); halt; end;

  writeln('NO');
end.