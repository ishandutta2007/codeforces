Program CodF_406_B;
var ter,rob:boolean;
    r,kol,n,m,k,i,j,ch:longint;
    lic:array[1..10000]of longint;
    nach,kon,por:array[1..10000]of longint;

procedure swap(var a,b:longint);
var c:longint;
begin
  c:=a;
  a:=b;
  b:=c;
end;


Procedure q_sort(a,b:longint);
var p,q,i,j:longint;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=lic[p];
    swap(lic[p], lic[a]);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while (lic[i]<=q) and (i<b) do inc(i);
          while lic[j]>q  do dec(j);
          if i<j then swap(lic[i], lic[j]);
        end;    
    swap(lic[a], lic[j]);  
    q_sort(a, j-1);
    q_sort(j+1, b);
  end                 else
    if (b-a=1) and (lic[a]>lic[b]) then swap(lic[a],lic[b]);


end;  

begin
kol:=0;
read(n,m);
for i:=1 to m do
  begin
  read(k);
  nach[i]:=kol+1;
  kon[i]:=nach[i]+k-1;
  kol:=kol+k;
  por[i]:=k;
  for j:=nach[i] to kon[i] do
    begin
      read(ch);
      lic[j]:=ch;
    end;  
  end;

r:=1;
for i:=1 to m do
  q_sort(nach[i], kon[i]);  

for i:=1 to m do
  for j:=nach[i] to kon[i]-1 do
    if lic[j]=lic[j+1] then
      begin
        lic[j]:=n+r;
        inc(r);
      end;  
      
for i:=1 to kon[m] do 
  if lic[i]<0 then lic[i]:=-lic[i];      
      
for i:=1 to m do
  q_sort(nach[i], kon[i]);

rob:=false;
for i:=1 to m do
  begin
    ter:=true;
    for j:=nach[i] to kon[i]-1 do
      begin
        if lic[j]=lic[j+1] then
          ter:=false;
      end;    
    if ter=true then rob:=true;  
  end;

if rob=true then write('YES')
            else write('NO');

end.