Program Eartth;
var z,i,n:longint;
   c:char;
   
   
begin
read(n);
z:=20000;
for i:=1 to n do
  begin
  readln(n, c, c);
  if (c<>'N') and (z=0) then
    begin
    writeln('NO');
    exit;
    end;
  if (c<>'S') and (z=20000) then
    begin
    writeln('NO');
    exit;
    end;
  if c='N' then z:=z+n;  
  if c='S' then z:=z-n;
  if (z<0) or (z>20000) then 
    begin
    writeln('NO');
    exit;
    end;
  
  end;
if z<>20000 then
  begin
  writeln('NO');
  exit;
  end;
   
writeln('YES');   




end.