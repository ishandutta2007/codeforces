uses math;
var
  a,b:array[1..10000]of longint;
  n,ans:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i],b[i]);

  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j) and (a[i]=b[j]) then inc(ans);
  writeln(ans);
end.