uses math;
var
  a:array[1..10000]of longint;
  n,c,maxr,ans:longint;
  i,j:longint;
begin
  read(n,c);
  for i:=1 to n do
    read(a[i]);
  maxr:=a[1]-a[2];
  for i:=2 to n-1 do
    maxr:=max(maxr,a[i]-a[i+1]);
  if maxr-c<=0 then begin writeln(0); halt; end;
  write(maxr-c);
end.