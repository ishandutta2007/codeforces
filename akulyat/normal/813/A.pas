Program CodeF_Edu22_A;
var n,m,i,p,k,t,s:longint;
    a,b:array[1..1000]of longint;
begin
read(n);
for i:=1 to n do
  begin
    read(t); 
    s:=s+t    
  end;  
read(m);
k:=1;
for i:=1 to m do
  begin
    read(a[i],b[i]);
    if (s>=a[i]) and (s<=b[i])then p:=1;
    if a[i]<s then inc(k);
  end;
if s>b[m] then write(-1)
  else
    begin
      if p=1 then write(s)
        else write(a[k]);
    end;
   
end.