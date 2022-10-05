Program GoT1;
var n,k,konf,Ar,otv,i:longint;


Function Min(a,b:longint):longint;
var c:longint;
begin
c:=a;
if b<c then
  c:=b;
Min:=c;  
end;


begin
read(n,k);

for i:=1 to n do
  begin
  read(konf);
  Ar:=Ar+konf;
  k:=k-min(Ar, 8);
  Ar:=Ar-min(Ar, 8);
  if (k<=0) and (otv=0) then otv:=i;
  end;
  
if otv=0 then write(-1)
  else write(otv);
end.