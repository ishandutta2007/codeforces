Program Position;
var a,b,c,i,k:longint;


begin
read(a,b,c);
i:=0;
k:=-1;
while (i<=b+10) and (k<>c) do
  begin
  k:=a*10 div b;
  a:=a*10 mod b;
  inc(i);
  end;
if k<>c then
  i:=-1;
writeln(i);  
  






end.