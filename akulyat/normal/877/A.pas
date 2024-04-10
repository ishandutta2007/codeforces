Program CodeF_A;
var gf:integer;
   s,d:string;
   i,j,l:integer; 



begin
read(s);
l:=length(s);
gf:=0;
for i:=1 to l-3 do
  begin
  d:='';
  for j:=i to i+3 do
    d:=d+s[j];
  if d='Olya' then inc(gf);
  end;
  
for i:=1 to l-2 do
  begin
  d:='';
  for j:=i to i+2 do
    d:=d+s[j];
  if d='Ann' then inc(gf);
  end;
  
for i:=1 to l-4 do
  begin
  d:='';
  for j:=i to i+4 do
    d:=d+s[j];
  if (d='Danil') or (d='Slava') then inc(gf);
  end;
  
for i:=1 to l-5 do
  begin
  d:='';
  for j:=i to i+5 do
    d:=d+s[j];
  if d='Nikita' then inc(gf);
  end;
  
if gf=1 then write('YES') else
  write('NO');  
  




end.