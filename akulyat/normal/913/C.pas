Program CodeF_H_2018_C;
var i,j,u,n,l:longint;
    mas,c:array[0..100]of longint;
    ideal:array[0..100]of int64; 
    //reb:array[1..1]of array[1..2]of longint;
    ans:int64;
    p:array[0..100]of array[0..100]of int64;

Function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;


begin
read(n,l);
u:=0;
while l>0 do
  begin
  mas[u]:=l mod 2;
  l:=l div 2;
  inc(u);
  end;

for i:=0 to n-1 do
  begin
  read(c[i]);
  p[i][i]:=c[i];
  for j:=i+1 to max(u, n) do
    begin
    p[i][j]:=p[i][j-1]*2;
    end;
  end;
for j:=0 to max(u, n) do
  begin
  ideal[j]:=p[0][j];
  for i:=0 to n-1 do
    if  (p[i][j]<ideal[j])  then 
      if (p[i][j]<>0) then
        ideal[j]:=p[i][j];
  end;
for j:=max(u, n) downto 1 do
  if (ideal[j]<>0) and (ideal[j]<ideal[j-1]) then
    ideal[j-1]:=ideal[j];

ans:=0;  
for j:=0 to u do
  if mas[j]=1 then
    ans:=ans+ideal[j] else
    if (ideal[j]<ans) and (ideal[j]<>0) then
      ans:=ideal[j];

//for j:=0 to u do
//  if mas[j]=1 then
//    begin
//    ans:=ans+ideal[j];
//    end;
for j:=u to max(u, n) do
  if (ideal[j]<>0) and (ideal[j]<ans) then
    ans:=ideal[j];    
    
    
    
//write('Chislo: ');
//for j:=0 to u-1 do
//  write(mas[j], ' ');  
//writeln;  
//write('Ideal: ');
//for j:=0 to u do
//  write(ideal[j], ' ');
//writeln;  

writeln(ans);


end.