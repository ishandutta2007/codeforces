var a:array[0..100] of longint;
    b,c,d,e,i,f:longint;
    s:extended;
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
 a[0]:=0;s:=0;
 readln(b);
 for i:=1 to b do
  read(a[i]);
 qsort(1,b);
 while b>0 do
 begin
  s:=s+pi*sqr(a[b])-pi*sqr(a[b-1]);
  dec(b);dec(b);
 end;
 writeln(s:1:10);
end.