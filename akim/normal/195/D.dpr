var a:array[0..100100]of extended;
    n,i,s,k,b:longint;
procedure qsort(l,r:longint);
var i,f:longint;x,z:extended;
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
 readln(n);a[0]:=100000.12;
 for i:=1 to n do
 begin
  readln(k,b);
  if k=0 then begin a[i]:=10.12;continue;end;
  a[i]:=-b/k;
 end;
 qsort(1,n);s:=0;
 for i:=1 to n do
 begin
  if (a[i]<>a[i-1])and(a[i]<>10.12) then inc(s);
 end;
 writeln(s);
end.