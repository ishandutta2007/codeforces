Program CodeF_454_B;
var x,y,i,j,i1,j1,n:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    p:array[0..8]of array[0..8]of longint;
    s:string;
    mogu:boolean;
    
    
begin
i1:=-1;
for i:=1 to 11 do
  begin
  readln(s);
  if length(s)=11 then
    begin
    inc(i1);
    j1:=-1;
    for j:=1 to 11 do
      begin
      if s[j]<>' ' then inc(j1);
      if s[j]='o' then
        begin
        p[i1][j1]:=1;
        end;
      if s[j]='x' then
        begin
        p[i1][j1]:=2;
        end;        
      end;
    end;  
  end;
read(x, y);
x:=(x-1) mod 3;
y:=(y-1) mod 3;
mogu:=false;
for i:=0 to 8 do
  for j:=0 to 8 do
    if (i div 3=x) and (j div 3=y) then
    begin
    if p[i][j]=0 then
      mogu:=true;
    end;

if mogu=true then
  for i:=0 to 8 do
    for j:=0 to 8 do
      begin
      if p[i][j]=0 then
         if (i div 3=x) and (j div 3=y) then
        p[i][j]:=3;
      end else
  begin
  for i:=0 to 8 do
    for j:=0 to 8 do
      if p[i][j]=0 then
        p[i][j]:=3;
  end;

for i:=0 to 8 do
  begin
  if (i mod 3=0) and (i<>0) then
    writeln;
  for j:=0 to 8 do
    begin
    if (j mod 3=0) and (j<>0) then
      write(' ');
    if p[i][j]=0 then write('.');  
    if p[i][j]=1 then write('o');
    if p[i][j]=2 then write('x');
    if p[i][j]=3 then write('!');
    end;
    writeln;  
  end;

end.