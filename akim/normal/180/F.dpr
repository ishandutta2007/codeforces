var a,b:array[1..100000]of longint;
    i,n:longint;
procedure qsort(l,r:longint);
var i,f,x,y:longint;
begin
 i:=l;f:=r;x:=b[random(r-l)+l];
 while i<=f do
 begin
  while b[i]<x do inc(i);
  while x<b[f] do dec(f);
  if i<=f then begin
                y:=a[i];
                a[i]:=a[f];
                a[f]:=y;
                y:=b[i];
                b[i]:=b[f];
                b[f]:=y;
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
  read(b[i]);
 for i:=1 to n do
  read(a[i]);
 qsort(1,n);
 for i:=1 to n do
  write(a[i],' ');
end.