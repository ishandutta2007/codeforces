uses math;
var
  a:array[1..1000]of longint;
  n,d,ans:int64;
  i,j:longint;
begin
  read(n,d);
  ans:=0;
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n do
    for j:=1 to n do
      if (i<>j) and (abs(a[i]-a[j])<=d) then inc(ans);

  writeln(ans);
end.