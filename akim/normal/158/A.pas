var a:array[1..50]of integer;
   b,l,k,n,i:integer;
begin

read(n,k);
 for i:= 1 to n do read(a[i]);
k:=a[k];
b:=n;
for i:=1 to n do if (a[i]<k)or(a[i]<=0) then dec(b);
write(b);


end.