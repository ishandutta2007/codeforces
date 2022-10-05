Program CodeF_446_B;
var i,j,n,kol,last,a,b:longint;
    l,die:array[1..1000010]of longint;


Function Min(a,b:longint):longint;
var c:longint;
begin
c:=a;
if b<c then
  c:=b;
Min:=c;
end;

begin
read(n);
last:=n+1;
for i:=1 to n do
  read(l[i]);
for i:=n downto 1 do
  begin
  {for j:=min(last-1, i-1) downto i-l[i] do
    if (j>0) and (die[j]<>0) then
    begin
    last:=j;
    inc(kol)
    end;}
  
  a:=min(last-1, i-1);
  if a<1 then a:=0;
  b:=i-l[i];
  if b<1 then b:=1;
  if a-b+1>0 then
    kol:=kol+a-b+1;
  if i-l[i]<last then
    last:=i-l[i];
  if last<1 then
    last:=1;
  end;
  
writeln(n-kol);  
  

end.