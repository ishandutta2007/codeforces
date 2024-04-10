Program CodeF_439_A;
var  kol,i,j,n:longint;
     nal:array[0..10000000]of longint;
    a,b:array[0..2100]of longint;
    f:text;
    
Function Xoo(a,b:longint):longint;
var a1,b1,st,c:longint;
begin
st:=1;
a1:=a;
b1:=b;
c:=0;
while (a1>0) or (b1>0) do
  begin
  c:=c+(((a1 mod 2)+(b1 mod 2))mod 2)*st;
  st:=st*2;
  a1:=a1 div 2;
  b1:=b1 div 2;
  end;
Xoo:=c;
end;

    
begin
//assign(f, 'aaaa');
//reset(f);
read(n);
for i:=1 to  n do
  begin
  read(a[i]);
  nal[a[i]]:=1;
  end;
  
for i:=1 to  n do
  begin
  read(b[i]);
  nal[b[i]]:=1;
  end;
//close(f);  
  
for i:=1 to n do
  for j:=1 to n do
  if nal[xoo(a[i], b[j])]=1 then kol:=(kol+1) mod 2;
  
if kol mod 2=1 then writeln('Koyomi') else
          writeln('Karen');    
  
end.