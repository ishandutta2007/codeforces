Program CodeF_C;
var  s,e,i,n:longint;


begin
read(n);
writeln(n+(n div 2));
for i:=(n-(n mod 2)) downto 2 do
  if (i mod 2)=0 then
  begin
  write(i, ' ');
  end;
for i:=2 to (n-(n mod 2)) do
  if (i mod 2=0) then
    write(i-1,' ');
if n mod 2=1 then write(n, ' ');

for i:=2 to (n-(n mod 2)) do
  if (i mod 2)=0 then 
  write(i, ' ');




end.