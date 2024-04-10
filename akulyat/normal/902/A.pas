Program AAA;
var a,b:array[0..100]of longint;
    ma,k,m,i:longint;
    ag,add:boolean;
begin
read(k,m);
ag:=true;
for i:=1 to k do
  read(a[i], b[i]);
i:=0;  
ma:=0;
for i:=1 to k do
  begin
  if a[i]<=ma then
    ma:=max(b[i], ma);
  end;
if ma>=m then
  writeln('YES') else
    writeln('NO');
end.