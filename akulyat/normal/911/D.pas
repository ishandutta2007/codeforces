Program CodeF_Edu35_r_D;
var i,j,n,mk,pa,r,l:longint;
    inv,m:array[1..1501]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    ans:array[0..200020]of byte;

begin
read(n);
for i:=1 to n do
  begin
  read(m[i]);
  end;

for i:=2 to n do
  begin
  inv[i]:=inv[i-1];
  for j:=1 to i-1 do
    if m[j]>m[i] then inc(inv[i]);
  end;
ans[0]:=(inv[n] mod 2);  
  

read(mk);
for i:=1 to mk do
  begin
  read(r, l);
  pa:=((l-r+1)*(l-r))div 2;
  if pa mod 2=1 then
    ans[i]:=(ans[i-1] xor 1) else
    ans[i]:=ans[i-1];
  end;

for i:=1 to mk do
  begin
  if ans[i]=1 then writeln('odd') else
    writeln('even');
  end;




end.