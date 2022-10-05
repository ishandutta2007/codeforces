Program CodeF_GB_2017_C;
var i,j,n,r:longint;
    x:array[1..1000]of longint;
    y:array[1..1000]of real;
    //reb:array[1..1]of array[1..2]of longint;
    pot:real;

begin
read(n,r);
for i:=1 to n do
  begin
  read(x[i]);
  end;
for i:=1 to n do
  begin
  y[i]:=r;
  for j:=1 to i-1 do
    if abs(x[i]-x[j])<=2*r then
      begin
      pot:=y[j]+sqrt(sqr(2*r)-sqr(x[i]-x[j]));
      if pot>y[i] then
        y[i]:=pot;
      end;
  end;
for i:=1 to n do
  begin
  write(y[i], ' ');
  end;




end.