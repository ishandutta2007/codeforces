Program Budilniki;
var off,m:array[1..200010]of longint;
    i,j,kol,n,l,k:longint;

procedure swap(a,b:longint);
var c:int64;
begin
   c:=m[a];
   m[a]:=m[b];
   m[b]:=c;
end;


Procedure q_sort2(a,b:longint);
var p,i,j:longint;
    q:int64;

begin
if b-a>1 then
  begin
    p:=random(b-a+1)+a;
    q:=m[p];
    swap(p, a);
    i:=a+1;
    j:=b;
      while i<j do
        begin
          while (m[i]<=q) and (i<b) do inc(i);
          while m[j]>q  do dec(j);
          if i<j then swap(i, j);
        end;    
    swap(a, j);  
    q_sort2(a, j-1);
    q_sort2(j+1, b);
  end                 else
    if (b-a=1) and (m[a]>m[b]) then swap(a, b);
end;  

begin
read(n, l, k);
for i:=1 to n do
  begin
  read(m[i]);
  end;
q_sort2(1, n);

if k=1 then
  begin
  writeln(n);
  exit;
  end;

i:=1;
j:=k;
while j<=n do
  begin
  if (m[j]-m[i]+1>l) or (off[i]=1) then
    begin
    inc(i);
    if (off[i]<>1)then inc(j);
    end else
      begin
      off[j]:=1;
      inc(j);
      inc(kol);
      end;
  end;
writeln(kol);
end.