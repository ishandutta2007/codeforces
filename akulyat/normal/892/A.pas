Program CodeF_446_A;
var i,j,n,a1,a2,kol,c:longint;
    vm,ost:array[1..100100]of longint;
    sum:int64;

begin
read(n);
for i:=1 to n do
  begin
    read(ost[i]);
    sum:=sum+ost[i];
  end;
read(vm[1]);
a1:=vm[1];
read(vm[2]);
a2:=vm[2];
if a2>a1 then
  begin
  c:=a1;
  a1:=a2;
  a2:=c;
  end;
  
for i:=3 to n do
  begin
    read(vm[i]);
    if vm[i]>a1 then
      begin
      a2:=a1;
      a1:=vm[i];
      end else
      if vm[i]>a2 then
        a2:=vm[i];
  end;  

if a1+a2>=sum then
  writeln('YES') else
    writeln('NO');
  

end.