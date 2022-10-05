Program Da_Dan;
var i,j:byte;
    otv:boolean;
    pol:array[1..10]of array[1..10]of char;
    
Function Gl(c,b:byte):boolean;
var a,t,k,n:byte;
begin
t:=0;
k:=0;
n:=0;
for a:=c to c+4 do
  begin
  if pol[a][b]='.' then inc(t);
  if pol[a][b]='O' then inc(n);
  if pol[a][b]='X' then inc(k);    
  end;
if (t=1) and (k=4) then
  Gl:=true else
  GL:=false;
   
end;

Function Sh(a,c:byte):boolean;
var b,t,k,n:byte;
begin
t:=0;
k:=0;
n:=0;
for b:=c to c+4 do
  begin
  if pol[a][b]='.' then inc(t);
  if pol[a][b]='O' then inc(n);
  if pol[a][b]='X' then inc(k);    
  end;
if (t=1) and (k=4) then
  Sh:=true else
  Sh:=false;
end;

Function Dg(a,b:byte):boolean;
var i,t,k,n:byte;
begin
t:=0;
k:=0;
n:=0;
for i:=0 to 4 do
  begin
  if pol[a+i][b+i]='.' then inc(t);
  if pol[a+i][b+i]='O' then inc(n);
  if pol[a+i][b+i]='X' then inc(k);    
  end;
if (t=1) and (k=4) then
  Dg:=true else
  Dg:=false;
end;

Function Dg1(a,b:byte):boolean;
var i,t,k,n:byte;
begin
t:=0;
k:=0;
n:=0;
for i:=0 to 4 do
  begin
  if pol[a-i][b+i]='.' then inc(t);
  if pol[a-i][b+i]='O' then inc(n);
  if pol[a-i][b+i]='X' then inc(k);    
  end;
if (t=1) and (k=4) then
  Dg1:=true else
  Dg1:=false;
end;



begin
for i:=1 to 10 do
  begin
  for j:=1 to 10 do
    read(pol[i][j]);
  readln;  
  end;  
otv:=false;  
for i:=1 to 6 do
  for j:=1 to 10 do
    if Gl(i,j)=true then otv:=true;
for i:=1 to 10 do
  for j:=1 to 6 do
    if Sh(i,j)=true then otv:=true;
for i:=1 to 6 do
  for j:=1 to 6 do
    if Dg(i,j)=true then otv:=true;    
for i:=5 to 10 do
  for j:=1 to 6 do
    if Dg1(i,j)=true then otv:=true;    
if otv=true then writeln('YES') else
 writeln('NO'); 
end.