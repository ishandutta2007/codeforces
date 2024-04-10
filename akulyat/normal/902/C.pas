Program CCC;
var k,p:array[0..200010]of longint;
    good,he,ch,sum,kol,n,i,j:longint;

begin
read(n);
for i:=1 to n+1 do 
  begin
  read(k[i]);
  if (k[i]<>1) and(k[i-1]<>1) then
    good:=i;
  sum:=sum+k[i];  
  end;

if good=0 then
  begin
  writeln('perfect');
  exit;
  end;
writeln('ambiguous');
he:=0;
for i:=1 to n+1 do
  begin
  if i<>good then
    for j:=1 to k[i] do
      write(he, ' ') else
    begin
    for j:=1 to k[i]-1 do
      write(he, ' ');
    write(he-1, ' ');  
    end;
  he:=he+k[i];
  end;

he:=0;  
writeln;  
for i:=1 to n+1 do
  begin
    for j:=1 to k[i] do
      write(he, ' ');
  he:=he+k[i];
  end;

{for i:=1 to n+1 do
  begin
  he:=he+k[i-1];
  for j:=1 to k[i] do
    begin
    p[he+j]:=he;
    end;
  end;  
for i:=1 to sum do
  begin
  write(p[i], ' ');
  end;
writeln;  
 
he:=0; 
for i:=1 to n+1 do
  begin
  he:=he+k[i-1];
  for j:=1 to k[i] do
    begin
    if (ch<>0) or (k[i-1]<=1) then
      p[he+j]:=he else
      begin
      p[he+j]:=he-1;
      ch:=1;
      end;
    end;
  end;  
for i:=1 to sum do
  begin
  write(p[i], ' ');
  end;
writeln;}
end.