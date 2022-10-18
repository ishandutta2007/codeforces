uses math;
var
  n,a,b,c,x,y,z,d1,d2,d3:longint;
begin
  read(n,a,x,b,y,c,z);
  d1:=a;
  d2:=b;
  d3:=c;
  n:=n-a-b-c;
  while (n<>0) and (d1<>x) do
    begin
      inc(d1);
      dec(n);
    end;
  while (n<>0) and (d2<>y) do
    begin
      inc(d2);
      dec(n);
    end;
  while (n<>0) and (d3<>z) do
    begin
      inc(d3);
      dec(n);
    end;
  writeln(d1,' ',d2,' ',d3);
end.