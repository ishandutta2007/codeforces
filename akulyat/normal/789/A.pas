Program CodF_407_1;
var kol:array[1..100000]of int64;
    n,i,skol:longint;
    ot,k:int64;

begin
read(n,k);
for i:=1 to n do 
  begin
    read(skol);
    kol[i]:=skol;
  end;
for i:=1 to n do
  if kol[i] mod k<>0 then
    kol[i]:=((kol[i] div k)+1)*k;

ot:=0;
for i:=1 to n do ot:=ot+kol[i];
ot:=ot div k;    
if ot mod 2=1 then inc(ot);
ot:=ot div 2;
write(ot);
end.