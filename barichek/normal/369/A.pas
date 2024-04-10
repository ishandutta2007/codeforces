uses math;
var
  a:array[1..10000]of longint;
  n,m1,m2,ans:longint;
  i:longint;
begin
  read(n,m1,m2);
  ans:=0;
  for i:=1 to n do
    read(a[i]);

  for i:=1 to n do
    if a[i]=1 then
      begin
        if m1=0 then inc(ans)
        else dec(m1);
      end
    else
      begin
        if (m2=0) and (m1=0) then inc(ans)
        else if m2>0 then dec(m2)
        else dec(m1);
      end;
  writeln(ans);
end.