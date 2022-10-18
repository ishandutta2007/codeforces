uses math;
var
  a:array[1..10000]of longint;
  n,m,ans:int64;
  i,j:longint;
begin
  read(n,m);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n-1 do
  for j:=i+1 to n do
  if a[i]<a[j] then
    begin
      a[i]:=a[i]+a[j];
      a[j]:=a[i]-a[j];
      a[i]:=a[i]-a[j];
    end;

  for i:=1 to n div 2 do
    begin
      a[i]:=a[i]+a[n-i+1];
      a[n-i+1]:=a[i]-a[n-i+1];
      a[i]:=a[i]-a[n-i+1];
    end;

  ans:=0;
  for i:=1 to m do
    begin
      if a[i]>=0 then break;
      dec(ans,a[i]);
    end;

  writeln(ans);
end.