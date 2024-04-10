Program Startuem;
var a,n,b,ch,i,kol:longint;
    k:array[1..100]of longint;

begin
read(n);
for i:=1 to n do
  begin
  read(ch);
  inc(k[ch]);
  if k[ch]=1 then inc(kol);
  if (ch=a) or (a=0) then 
    a:=ch else
    b:=ch;
  end;
if (kol=2) and (k[a]=n div 2) then
  begin
  writeln('YES');
  write(a, ' ', b);
  end else
  write('NO');


end.