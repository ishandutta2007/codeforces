Program CodeF_E33_r_A;
var i,n,a,b,c,d:longint;
    m:array[1..1010]of longint;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n);
for i:=1 to n do
  begin
  readln(m[i]);
  end;
a:=1;
b:=2;
c:=3;
for i:=1 to n do
  begin
  if (m[i]<>a) and (m[i]<>b) then
    begin
    writeln('NO');
    exit;
    end;
  if m[i]=a then
    begin
    d:=b;
    b:=c;
    c:=d;
    end else
    begin
    d:=a;
    a:=c;
    c:=d;
    end    
  end;
writeln('YES');




end.