Program CodeF_446_c;
var i,j,n,kol1,st,a,b,mo,k:longint;
    m:array[1..2000]of longint;



Function NOD(a,b:longint):longint;
begin
while (a<>0) and (b<>0) do
  begin
  if a>=b then
    a:=a-b else
    b:=b-a;
  end;
NOD:=a+b;
end;


Function Fou(a,b:longint):longint;
var mo:longint;
begin
if a=b then
  Fou:=m[a] else
    begin
    mo:=(a+b)div 2;
    Fou:=Nod(Fou(a,mo), Fou(mo+1, b)); 
    end;

end;


begin
read(n);
for i:=1 to n do
  begin
  read(m[i]);
  if m[i]=1 then inc(kol1);
  end;
if kol1>0 then
  begin
  writeln(n-kol1);
  exit;
  end;
st:=m[1];
for i:=2 to n do
  begin
  st:=NOD(st, m[i]);
  end;
if st<>1 then
  begin
  writeln(-1);
  exit;
  end;
  
a:=1;
b:=n;  
while a+1<>b do
  begin
  k:=0;
  mo:=(a+b)div 2;
  for i:=1 to n-mo+1 do 
    if Fou(i,i+mo-1)=1 then
      k:=1;
  if k=1 then
    b:=mo else
    a:=mo;
  end;
writeln(n-1+(b-1));  

end.