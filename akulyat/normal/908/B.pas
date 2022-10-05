Program CodeF_GB_2017_B;
var i,j,u,n,g,kol,k,l,orda,a,b,a1,b1,qq:longint;
    //m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    s:string;
    w:array[0..3]of longint;
    z:array[1..100]of longint;
    m,po:array[0..100]of array[0..100]of longint;
    con,st:boolean;
    
    
Function shag(c:longint):longint;
begin
if c=0 then dec(a1);
if c=2 then inc(a1);
if c=3 then dec(b1);
if c=1 then inc(b1);
//writeln(a1,b1);
if (a1<1) or (b1<1) or(a1>n) or (b1>g) or (m[a1][b1]=1) then
  shag:=1 else
  if m[a1][b1]=3 then
    shag:=3 else
      shag:=0;
end;

Procedure Create(i:longint);
var j:longint;
begin
j:=-1;
while i>0 do
  begin
  inc(j);
  w[j]:=i mod 4;
  i:=i div 4;
  end;
end;


begin
readln(n,g);
for i:=1 to n do
  begin
  readln(s);
  for j:=1 to length(s) do
    begin
    if s[j]='.' then
      m[i][j]:=0;
    if s[j]='#' then
      m[i][j]:=1;
    if s[j]='S' then
      begin
      m[i][j]:=2;
      a:=i;
      b:=j;
      end;
    if s[j]='E' then
      m[i][j]:=3;  
    end;
  end;
for i:=0 to n+1 do
  begin
  m[i][0]:=1;
  m[i][g+1]:=1;
  end;
for i:=0 to g+1 do
  begin
  m[0][i]:=1;
  m[n+1][i]:=1;
  end;  
orda:=ord('0');  
readln(s);
k:=length(s);
for i:=1 to length(s) do
  begin
  z[i]:=ord(s[i])-orda;
  end;
  
for i:=0 to 255 do
  begin
  Create(i);
  st:=true;
  {for j:=1 to n do
    for u:=1 to g do
      begin
      po[j][u]:=m[j][u];
      end;}
  for j:=0 to 3 do
    for u:=j+1 to 3 do
      begin
      if w[j]=w[u] then
        st:=false;
      end;
  if st=true then
    begin
//    writeln(w[0], ' ',w[1], ' ',w[2], ' ',w[3], ' ');
    a1:=a;
    b1:=b;
    con:=true;
    for j:=1 to k do
      if con then
        begin
        qq:=shag(w[z[j]]);
        if qq=3 then 
          begin
          inc(kol);
          con:=false;
          end;
        if qq=1 then con:=false;       
        end;
    end;
  end;
writeln(kol);


end.