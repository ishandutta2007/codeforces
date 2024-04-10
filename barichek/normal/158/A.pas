uses math;
var
  a:array[1..10000]of longint;
  i,n,k,ans:longint;
begin
  read(n,k);
  ans:=0;
  for i:=1 to n do
    read(a[i]);


  for i:=1 to n do
    if (a[i]>=a[k]) and (a[i]>0) then inc(ans);

  writeln(ans);
end.