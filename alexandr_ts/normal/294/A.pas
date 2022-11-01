var a:array[1..10000]of longint;
    x,y,m,i,j,n:longint;
begin
read(n);
for i:=1 to n do
  read(a[i]);
read(m);
for i:=1 to m do
  begin
    read(x,y);
    if x=1 then
      begin
        a[x+1]:=a[x+1]+a[x]-y;
        a[x]:=0;
      end;
    if x=n then
      begin
        a[x-1]:=a[x-1]+y-1;
        a[x]:=0;
      end;
    if (x>1)and(x<n) then
      begin
        a[x-1]:=a[x-1]+y-1;
        a[x+1]:=a[x+1]+a[x]-y;
        a[x]:=0;
      end;
  end;
for i:=1 to n do
  writeln(a[i]);
end.