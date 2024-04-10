var a:array[0..100100]of longint;
    n,i:longint;
procedure swap(var x,y:longint);
var z:longint;begin z:=x;x:=y;y:=z;end;
procedure qsort(l,r:longint);
var i,f,x:longint;
begin
 i:=l;f:=r;
 x:=a[l+random(r-l)];
 while i<=f do
 begin
  while a[i]<x do inc(i);
  while a[f]>x do dec(f);
  if i<=f then begin
                swap(a[i],a[f]);
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 qsort(1,n);
 a[0]:=1;
 if a[n]=1 then a[n-1]:=2;
 for i:=1 to n do
  write(a[i-1],' ');
end.