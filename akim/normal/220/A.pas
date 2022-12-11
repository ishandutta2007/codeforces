var a,b:array[1..100100]of longint;
    i,n,q:longint;
procedure qsort(l,r:longint);
var i,f,x,z:longint;
begin
 i:=l;f:=r;x:=a[random(r-l)+l];
 while i<=f do
 begin
  while a[i]<x do inc(i);
  while a[f]>x do dec(f);
  if i<=f then begin
                z:=a[i];
                a[i]:=a[f];
                a[f]:=z;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 q:=0;
 readln(n);
 for i:=1 to n do
 begin
  read(a[i]);
  b[i]:=a[i];
 end;
 qsort(1,n);
 for i:=1 to n do
  if a[i]<>b[i] then inc(q);
 if q<3 then writeln('YES') else writeln('NO');
end.