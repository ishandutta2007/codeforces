Program CodeF_418_A;
var p,v:array[1..100]of longint;
    i,n,a,nel:longint;

begin
read(n,a);
for i:=1 to n do
  read(p[i]);
for i:=1 to a do
  read(v[i]);  
if a>1 then write('Yes')
  else
    begin
      for i:=1 to n do
        if p[i]=0 then p[i]:=v[1];
      for i:=1 to n-1 do
        if p[i]>p[i+1] then nel:=1;
        if nel=1 then write('Yes')
          else write('No');
    end;





end.