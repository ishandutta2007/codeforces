Program CodeF_418_B;
const g=1000;
var nom,ots:array[1..2]of longint;
    a,b,otv,nal:array[1..g]of longint;
    s,d,i,an,bn,n:longint;
    
begin
read(n);
for i:=1 to n do
  read(a[i]);
s:=0;
for i:=1 to n do
  begin
    read(b[i]);
    if a[i]<>b[i] then
      begin
        inc(s);
        nom[s]:=i;
      end         else
        nal[a[i]]:=1;
  end;  

d:=0;  
for i:=1 to n do 
  if nal[i]=0 then
    begin
      inc(d);
      ots[d]:=i;
    end;  

if s=2 then
  begin
    for i:=1 to n do
      if (i<>nom[1]) and (i<>nom[2]) then
        otv[i]:=a[i] else 
          if i=nom[1] then otv[i]:=ots[1]
            else otv[i]:=ots[2];
    for i:=1 to n do
      begin
        if otv[i]<>a[i] then inc(an);
        if otv[i]<>b[i] then inc(bn);
      end;
    if (an<>1) or (bn<>1) then 
      begin
        otv[nom[2]]:=otv[nom[1]]+otv[nom[2]];
        otv[nom[1]]:=otv[nom[2]]-otv[nom[1]];
        otv[nom[2]]:=otv[nom[2]]-otv[nom[1]];
      end;
  end;
if s=1 then
  begin
    for i:=1 to n do
      if i<>nom[1] then otv[i]:=a[i]
                   else otv[i]:=ots[1];
  end;
  
for i:=1 to n do
  write(otv[i], ' ');  
end.