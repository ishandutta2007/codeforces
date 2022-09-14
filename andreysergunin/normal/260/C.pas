var a:array [1..100000] of int64;
    n,x,min,j,k,l:int64;
    i:longint;
begin
read (n,x);
for i:=1 to n do read (a[i]);
min:=1000000000;
for i:=1 to n do if (a[i]<min) then min:=a[i];
k:=x;
while a[k]<>min do
        k:=(k+n-2)mod n +1;
for i:=1 to n do a[i]:=a[i]-min;
l:=k;
i:=0;
if k=x then
       else
       while k<>x do
        begin
         k:=k mod n +1;
         a[k]:=a[k]-1;
         i:=i+1;
        end;
a[l]:=min*n+i;

for i:=1 to n do write (a[i],' ');
end.