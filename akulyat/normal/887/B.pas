Program Varvar;
var  a,nal:array[0..10000]of longint;
     n,i,j,u,kol:longint;


begin
read(n);
kol:=6*n;
for i:=0 to kol-1 do
  read(a[i]);
  
for i:=0 to kol-1 do
  begin
  nal[a[i]]:=1;
  end;
  
for i:=0 to kol-1 do
  for j:=0 to kol-1 do
    if (i div 6)<>(j div 6) then
      nal[a[i]*10+a[j]]:=1;

for i:=0 to kol-1 do
  for j:=0 to kol-1 do
    for u:=0 to kol-1 do
    if ((i div 6)<>(j div 6)) and ((u div 6)<>(j div 6)) and ((i div 6)<>(u div 6)) then
      nal[a[i]*100+a[j]*10+a[u]]:=1;

for i:=1 to 999 do 
  if nal[i]=0 then
    begin
    writeln(i-1);
    exit;
    end;







end.