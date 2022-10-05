Program Kayak;
var i,j,vrem,c,a,b,n,gotv,otv:longint;
    m,ar:array[0..101]of longint;
begin

gotv:=25000;
read(n);
for i:=1 to 2*n do
read(m[i]);

for j:=1 to 2*n do
for i:=1 to 2*n-1 do
  if m[i]>m[i+1] then
    begin
    c:=m[i];
    m[i]:=m[i+1];
    m[i+1]:=c;
    end;
{for i:=1 to 2*n do write(m[i], ' ');    
writeln;}
    
for a:=1 to 2*n-1 do
for b:=a+1 to 2*n do
  begin
  for i:=1 to 2*n do ar[i]:=m[i]; 
  for i:=a downto 2 do
    begin
    c:=ar[i];
    ar[i]:=ar[i-1];
    ar[i-1]:=c;
    end;
  for i:=b to 2*n-1 do
    begin
    c:=ar[i];
    ar[i]:=ar[i+1];
    ar[i+1]:=c;
    end;  
  {for i:=1 to 2*n do write(ar[i], ' ');    
  writeln;}  
  for i:=2 to 2*n-2 do
  if i mod 2=0 then otv:=otv+abs(ar[i]-ar[i+1]);
  if otv<gotv then
    gotv:=otv;
    otv:=0;
  end;
  
  
writeln(gotv);  
end.