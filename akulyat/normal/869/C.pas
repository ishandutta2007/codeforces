Program CodeF_439_C;
const big=998244353;  //998244353
var jo,para,ka,kb,kc,kol:int64;
   shag,a,b,c,a1,b1,c1:longint;


begin
read(a,b,c);
a1:=a;
b1:=b;
c1:=c;

ka:=1;
a1:=a;
b1:=b;
para:=1;
shag:=1;
while (a1>0) and (b1>0) do
  begin
  jo:=para*a1*b1;
  while jo  mod shag<>0 do
    jo:=jo+big;
  para:=( jo div shag)mod big;
  ka:=(ka+para)mod big;
  inc(shag);
  dec(a1);
  dec(b1);
  end;

kb:=1;
c1:=c;
b1:=b;
para:=1;
shag:=1;
while (c1>0) and (b1>0) do
  begin 
  jo:=para*b1*c1;
  while jo  mod shag<>0 do
    jo:=jo+big;
  para:=( jo div shag)mod big;
  kb:=(kb+para)mod big;
  inc(shag);
  dec(b1);
  dec(c1);
  end;

kc:=1;
a1:=a;
c1:=c;
para:=1;
shag:=1;
while (a1>0) and (c1>0) do
  begin
  jo:=para*a1*c1;
  while jo  mod shag<>0 do
    jo:=jo+big;
  para:=( jo div shag)mod big;
  kc:=(kc+para)mod big;
  inc(shag);
  dec(a1);
  dec(c1);
  end;
  
  
writeln( (((ka*kb)mod big)*kc)mod big );

end.