uses math;
var
  a,c:array[1..1000]of longint;
  b:array[1..1000,1..1000]of longint;
  n,mina:longint;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=1 to a[i] do
      read(b[i,j]);
  for i:=1 to n do
    begin
      c[i]:=0;
      for j:=1 to a[i] do
        inc(c[i],b[i,j]);
    end;
  for i:=1 to n do
    c[i]:=c[i]*5+15*(a[i]);

  mina:=c[1];
  for i:=1 to n do
    mina:=min(mina,c[i]);
  writeln(mina);
end.