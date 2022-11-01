var k,n,i,j,sum,p,i1:longint;
    a:array [1..1000] of integer;
begin
read (n);
for i:=1 to n do
 read (a[i]);
k:=1;
while p<>1 do
 begin
  for i:=1 to n do
   if a[i]=k then a[i]:=-1;
  if (a[1]=-1) or (a[n]=-1) then p:=1;
  for i:=1 to n-1 do
   if (a[i]=-1) and (a[i+1]=-1) then p:=1;
  inc (k);
 end;
 write (k-1);
end.