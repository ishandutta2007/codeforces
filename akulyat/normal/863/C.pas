Program KNB;
var r:array[1..20]of array[1..2]of longint;
    n:int64; 
    kus,kad:array[1..2]of int64;
    i,s,e,j,k:byte;
    est:boolean;
    A,B:array[1..3]of array[1..3]of byte;
    
Function Best(i:longint):byte;  // 1-Alice; 2-Bob; 0-Draw;
var a:byte;
begin
a:=0;
if ((r[i][1]=1) and (r[i][2]=3)) or ((r[i][1]=2) and (r[i][2]=1)) or ((r[i][1]=3) and (r[i][2]=2)) then a:=1;
if ((r[i][1]=2) and (r[i][2]=3)) or ((r[i][1]=3) and (r[i][2]=1)) or ((r[i][1]=1) and (r[i][2]=2)) then a:=2;
Best:=a;
end;



begin
read(n, r[1][1], r[1][2]);
for i:=1 to 3 do
  for j:=1 to 3 do
    read(A[i][j]);
for i:=1 to 3 do
  for j:=1 to 3 do
    read(B[i][j]);
for i:=2 to 10 do
  begin
  //writeln(r[i-1][1],' ', r[i-1][2]);
  r[i][1]:=A[r[i-1][1]][r[i-1][2]];
  r[i][2]:=B[r[i-1][1]][r[i-1][2]];  
  end;
est:=false;
k:=10;
if n<k then k:=n;
for i:=2 to k do
  if est=false then
    for j:=i-1 downto 1 do
      if (r[i][1]=r[j][1]) and (r[i][2]=r[j][2]) then
        begin
        s:=j;
        e:=i-1;
        est:=true;
        end;
if s=0 then
  begin
  s:=n+1;
  e:=0;
  end;
for i:=1 to s-1 do
    if best(i)<>0 then inc(kad[best(i)]);
{writeln('First ten');
for i:=1 to 10 do writeln(r[i][1], r[i][2]);
writeln('Answer');} 
    
    
    
n:=n-s+1;

for i:=s to e do
    if best(i)<>0 then inc(kus[best(i)]);
    
for i:=1 to 2 do
  kus[i]:=kus[i]*(n div (e-s+1));
  
for i:=s to s+(n mod (e-s+1))-1 do
  if best(i)<>0 then inc(kus[best(i)]);

for i:=1 to 2 do
  kus[i]:=kus[i]+kad[i];  

for i:=1 to 2 do
  write(kus[i],' ');  
  
end.