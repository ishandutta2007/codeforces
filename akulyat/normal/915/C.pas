Program Normal;
var ans,a,b,a1,b1:int64;
    i,j,l1,l2:longint;
    pb,kol:array[0..30]of longint;
    
Function Lel(a:int64):longint;
var i:longint;
begin
i:=0;
while a>0 do
  begin
  inc(i);
  a:=a div 10;
  end;
Lel:=i;
end;


Procedure Create;
var i:longint;
begin
ans:=0;
for i:=9 downto 0 do
  begin
  while kol[i]>0 do
    begin
    ans:=ans*10+i;
    dec(kol[i]);
    end;
  end;
end;


Function sear(a:longint):longint;
var ll:longint;
    bb:int64;
begin
ll:=l2; 
bb:=b;
while ll>a do 
  begin
  bb:=bb div 10;
  dec(ll);
  end;
sear:=bb mod 10;
end;

Procedure tr(i:longint);
var ma,a:int64;
    j:longint;
    kol1:array[0..9]of longint;  
begin
for j:=0 to 9 do
  begin
  kol1[j]:=kol[j];
  end;
for j:=1 to i do
  begin
  ma:=ma*10+pb[j];
  dec(kol1[pb[j]]);
  if kol1[pb[j]]<0 then
   exit;
  end;
for j:=sear(i+1)-1 downto 0 do
  if kol1[j]>0 then
    begin
    dec(kol1[j]);
    ma:=ma*10+j;
    break;
    end;
    
for j:=9 downto 0 do
  begin
  while kol1[j]>0 do
    begin
    ma:=ma*10+j;
    dec(kol1[j]);
    end;
  end;
//writeln(ma);
if (ma>ans) and (ma<=b) then
  ans:=ma;
end;


begin
read(a,b);
l1:=Lel(a);
l2:=Lel(b);


a1:=a;
while a1>0 do
  begin
  inc(kol[a1 mod 10]);
  a1:=a1 div 10;
  end;

b1:=b;
j:=l2;
while b1>0 do
  begin
  pb[j]:=b1 mod 10;
  b1:=b1 div 10;
  dec(j);
  end;
  
if l1=l2 then   
  begin
  for i:=0 to l1 do
    tr(i);
  end else
  create;
//writeln;  
writeln(ans);
end.