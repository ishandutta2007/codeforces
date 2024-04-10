Program CodeF_416_B;
var per,per1:array[1..10000]of longint;
    gg,n,m,i,j,a,b,x:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
  c:=a;
  a:=b;
  b:=c;
end;


Procedure q_sort2(a,b:longint);
var p,q,i,j:longint;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=per1[p];
    swap(per1[p], per1[a]);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while (per1[i]<=q) and (i<b) do inc(i);
          while per1[j]>q  do dec(j);
          if i<j then swap(per1[i], per1[j]);
        end;   
    swap(per1[a], per1[j]);  
    q_sort2(a, j-1);
    q_sort2(j+1, b);
  end                 else
    if (b-a=1) and (per1[a]>per1[b]) then swap(per1[a],per1[b]);


end;  


begin
read(n,m);
for i:=1 to n do
  read(per[i]);
for i:=1 to n do
  per1[i]:=per[i]; 
 
a:=1; b:=1;  
for i:=1 to m do
  begin
    for j:=a to b do
      per1[j]:=per[j];
    read(a,b,x);
    gg:=0;
    for j:=a to b do
      if per1[j]<per1[x] then inc(gg);
      
    if gg=x-a then writeln('Yes')
                       else writeln('No');
  end;


end.