Program Records;
var bad,del,kol,best,i,n,max,last:longint;
    m:array[0..100010]of longint;

begin
read(n);
last:=0;
max:=0;
for i:=1 to n do
  begin
  read(m[i]);
  if (m[i]<m[i-1]) and ((m[i]<bad) or (bad=0)) then
    bad:=m[i];
  if m[i]>max then
    begin
    last:=max;
    max:=m[i];
    kol:=0;
    end else
    if (m[i]<max) and (m[i]>last) then
      begin
      inc(kol);
      last:=m[i];
      if kol>=best then 
        if (max<del) or (kol>best) then
        begin
        best:=kol;
        del:=max;
        end;
      end;
  end;
if bad=0 then
  bad:=1;
if best=0 then writeln(bad) else
  if best=1 then writeln(min(bad, del)) else
  writeln(del);
end.