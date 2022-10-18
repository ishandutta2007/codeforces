uses math;
var
  a,b:array[1..10000]of longint;
  n,maxia,maxib,minia,minib:int64;
  i:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i],b[i]);

  maxia:=a[1];
  minia:=a[1];
  for i:=1 to n do
    begin
      maxia:=max(maxia,a[i]);
      minia:=min(minia,a[i]);
    end;

  maxib:=b[1];
  minib:=b[1];
  for i:=1 to n do
    begin
      maxib:=max(maxib,b[i]);
      minib:=min(minib,b[i]);
    end;

  maxia:=max(abs(maxia-minia),abs(maxib-minib));
  writeln(maxia*maxia);
end.