uses math;
var
  x,y:array[1..1000]of longint;
  n,bx,m,by,a,b:int64;
  i:longint;
begin
  read(n,bx);
  for i:=1 to n do
    read(x[i]);
  read(m,by);
  for i:=1 to m do
    read(y[i]);

  a:=0;
  b:=0;
  for i:=1 to n do
    a:=a*bx+x[i];
  for i:=1 to m do
    b:=b*by+y[i];

  if a=b then writeln('=')
  else if a<b then writeln('<')
  else writeln('>');
end.