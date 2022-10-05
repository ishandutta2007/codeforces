Program CodeF_Edu35_r_C;
var last,i,n,a,b,c,x1,x2,x3:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    st,g:boolean;

begin
read(a,b,c);
x1:=0;
x2:=1-b;
g:=true;
st:=false;
for i:=2 to 10000 do
  begin
  if (i mod a<>0) and (i mod b<>1) then
    begin
    last:=x3;
    x3:=i mod c;
    if (st=true) and (last<>x3) then
      g:=false;
    st:=true;
    end;
  end;
if g=true then
  begin
  writeln('YES');
  exit;
  end;

x2:=1-c;
g:=true;
st:=false;
for i:=2 to 10000 do
  begin
  if (i mod a<>0) and (i mod c<>1) then
    begin
    last:=x3;
    x3:=i mod b;
    if (st=true) and (last<>x3) then
      g:=false;
    st:=true;
    end;
  end;
if g=true then
  begin
  writeln('YES');
  exit;
  end;
writeln('NO');


end.