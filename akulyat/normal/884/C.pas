Program Underground;
var kol,col,p:array[0..100100]of int64;
   otv:biginteger;
   i:longint;
   n,tc,j,skol,spec,nm,nm2,max,max2:int64;
begin
read(n);
for i:=1 to n do
  read(p[i]);
  
for i:=1 to n do
  begin
  if col[i]=0 then
    begin
    skol:=0;
    inc(tc);
    col[i]:=tc;
    j:=i;
    inc(skol);
    while (col[p[j]]=0) do
      begin
      col[p[j]]:=tc;
      j:=p[j];
      inc(skol);
      end;
    kol[tc]:=skol;  
    end;
  end;
if tc<>1 then
begin  
for i:=1 to tc do
  if kol[i]>max then
    begin
    nm:=i;
    max:=kol[i];
    end;    
for i:=1 to tc do
  if (kol[i]>max2) and (i<>nm) then
    begin
    nm2:=i;
    max2:=kol[i];
    end;
spec:=max+max2;

for i:=1 to n do
  if (i<>nm) and (i<>nm2) then
  begin
  otv:=otv+(kol[i]*(kol[i]));
  end;
otv:=otv+spec*(spec);
writeln(otv);  
end else
begin
otv:=n*n;
writeln(otv);
end;

end.