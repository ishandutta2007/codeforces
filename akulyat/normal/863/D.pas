Program Cesar;
var de,s,e,mas:array[1..200000]of longint;
    p,n,q,i,j:longint;
    m:byte;
    
begin
read(n,q,m);
for i:=1 to n do read(mas[i]);
for i:=q downto 1 do 
  begin
  read(de[i], s[i], e[i]);
  end;

//for i:=1 to q do 
//writeln(de[i], ' ', s[i], ' ', e[i]);
for i:=1 to m do
  begin
  read(p);
  //writeln(p);
  for j:=1 to q do
  if (p<=e[j]) and (p>=s[j]) then
  begin
  if (de[j]=2)  then p:=e[j]-(p-s[j]) else
  if p=s[j] then p:=e[j] else
     p:=p-1;
  //writeln(p);   
  end;
  write(mas[p], ' ');
  end;





end.