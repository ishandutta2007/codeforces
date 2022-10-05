Program Points;
var n,k,x,y,i:longint;

begin
read(n);
k:=0;
for i:=1 to n do
  begin
  read(x,y);
  if x>0 then
    inc(k);
  end;
if (k<=1) or (n-k<=1) then
  writeln('Yes') else
    writeln('No');


end.