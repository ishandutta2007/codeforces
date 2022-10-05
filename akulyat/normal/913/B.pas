Program CodeF_H_2018_B;
var j,i,n:longint;
    //m:array[1..]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    lis:array[0..1000]of boolean;
    kol:array[0..1000]of longint;
    reb:array[0..1000]of array[0..1000]of longint;
    a,kk:longint;
    ans:boolean;
    
begin
read(n);
for i:=2 to n do
  begin
  read(a);
  //ro[i]:=a;
  inc(kol[a]);
  reb[a][kol[a]]:=i;
  end;
for i:=1 to n do lis[i]:=false;  
for i:=1 to n do
  begin
  if kol[i]=0 then
    lis[i]:=true;
  end;
ans:=true;  
for i:=1 to n do
  if lis[i]=false then
    begin
    kk:=0;
    for j:=1 to kol[i] do if lis[reb[i][j]]=true then
      inc(kk);
    if kk<3 then ans:=false;    
    end;
if ans=true then writeln('YES') else
  writeln('NO');



end.