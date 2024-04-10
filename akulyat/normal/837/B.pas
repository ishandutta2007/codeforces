Program Flags;
var flag,itog:boolean;
   pol:array[0..100]of array[0..100]of byte;
   n,m,i,j:longint;
   b:char;
   s:string;
begin
readln(n,m);
for i:=0 to n-1 do
  begin
  readln(s);
  for j:=0 to m-1 do
    begin
    b:=s[j+1];
    if b='R' then pol[i][j]:=1;
    if b='G' then pol[i][j]:=2;
    if b='B' then pol[i][j]:=3;    
    end; 
  end;
  
if n mod 3=0 then
  begin
  flag:=true;
  for i:=0 to n-1 do
    for j:=0 to m-1 do
      if pol[i][j]<>pol[(i div (n div 3))*(n div 3)][0] then
        flag:=false;
  if (pol[0][0]<>pol[n div 3][0]) and (pol[0][0]<>pol[2*(n div 3)][0]) and (pol[2*(n div 3)][0]<>pol[n div 3][0]) and (flag=true) then 
    itog:=true;
  end;
if m mod 3=0 then
  begin
  flag:=true;
  for i:=0 to n-1 do
    for j:=0 to m-1 do
      if pol[i][j]<>pol[0][(j div (m div 3))*(m div 3)] then
        flag:=false;
  if (pol[0][0]<>pol[0][m div 3]) and (pol[0][0]<>pol[0][2*(m div 3)]) and (pol[0][2*(m div 3)]<>pol[0][m div 3]) and (flag=true) then
    itog:=true;
  end;  
if itog=true then write('YES') else
  write('NO');  
end.