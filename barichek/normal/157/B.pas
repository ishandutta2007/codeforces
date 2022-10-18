uses math;
var
  a:array[1..10000]of longint;
  n,ans:longint;
  i,j:longint;
begin
  read(n);
  ans:=0;
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
  for i:=1 to n do
    if i mod 2=1 then inc(ans,sqr(a[i]))
    else dec(ans,sqr(a[i]));

  writeln(ans*pi:0:4);
end.