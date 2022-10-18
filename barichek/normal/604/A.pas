uses math;
var
  m,w,x:array[1..5]of longint;
  hs,hu,ans:extended;
  i:longint;
begin
  for i:=1 to 5 do
    read(m[i]);
  for i:=1 to 5 do
    read(w[i]);
  x[1]:=500;
  for i:=2 to 5 do
    x[i]:=x[i-1]+500;
  read(hs,hu);

  for i:=1 to 5 do
    ans:=ans+max(x[i]*3/10,(1-m[i]/250)*x[i]-50*w[i]);
  ans:=ans+hs*100;
  ans:=ans-hu*50;

  writeln(ans:0:0);
end.