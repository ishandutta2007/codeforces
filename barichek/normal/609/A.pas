uses math;
var
  a:array[1..100000]of longint;
  n,m:longint;
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

  j:=0;
  for i:=1 to n do
    begin
      inc(j);
      dec(m,a[i]);
      if m<=0 then break;
    end;

  writeln(j);
end.