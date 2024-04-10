Program Rekurs;
const gr=150;
var need:array[0..1]of array[-gr..gr]of array[-gr..gr]of longint;
    nap:array[0..1]of array[-gr..gr]of array[-gr..gr]of array[0..7]of longint;
    was:array[-gr..gr]of array[-gr..gr]of longint;
    youdid,i,j,u,kol,n:longint;
    l1,l2:byte;
    t:array[1..30]of longint;
    
Procedure Dodo(i,j,u,t:longint; l1,l2:byte; ww:longint);
var i1,a,j1:longint;

begin
i1:=i;
j1:=j;
for a:=1 to t do
  begin
  if u=0 then begin inc(i1);   end;      
  if u=1 then begin inc(j1); inc(i1);  end;
  if u=2 then begin inc(j1);  end;
  if u=3 then begin inc(j1); dec(i1);  end;
  if u=4 then begin dec(i1);  end;
  if u=5 then begin dec(j1); dec(i1);  end;
  if u=6 then begin dec(j1);   end;
  if u=7 then begin dec(j1); inc(i1);  end;
  was[i1][j1]:=1;
  end;
need[l2][i1][j1]:=ww+1;
nap[l2][i1][j1][(u+1) mod 8]:=1;
nap[l2][i1][j1][(u-1+8) mod 8]:=1;
end;


begin
read(n);
for i:=1 to n do
  begin
  read(t[i]);
  end;

youdid:=0;
need[0][0][-1]:=1;
nap[0][0][-1][0]:=1;
//was[0][0]:=1;
l1:=1;
l2:=0;
while youdid<n do
  begin
  inc(youdid);
  l1:=l1 xor 1;
  l2:=l2 xor 1;
  
  for i:=-gr to gr do
    for j:=-gr to gr do
      begin
      for u:=0 to 7 do
        begin
        if (need[l1][i][j]=youdid) and (nap[l1][i][j][u]=1) then
          begin
          Dodo(i,j,u,t[youdid],l1,l2,youdid);
          nap[l1][i][j][u]:=0;
          end;
        end;
      end;
  end;

for i:=-gr to gr do
   for j:=-gr to gr do
     if was[i][j]=1 then inc(kol);
writeln(kol);     




end.