var a,b:array[1..100000]of longint;
    i,l,r,q,n,m:longint;
procedure qsorta(l,r:longint);
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
 if l<f then qsorta(l,f);
 if i<r then qsorta(i,r);
end;
procedure qsortb(l,r:longint);
var i,f,x,z:longint;
begin
 i:=l;f:=r;x:=b[random(r-l)+l];
 while i<=f do
 begin
  while b[i]<x do inc(i);
  while b[f]>x do dec(f);
  if i<=f then begin
                z:=b[i];
                b[i]:=b[f];
                b[f]:=z;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsortb(l,f);
 if i<r then qsortb(i,r);
end;
begin
 readln(n,m);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n do
  read(b[i]);
 qsorta(1,n);
 qsortb(1,n);
 l:=1;r:=n;q:=0;
 while (l<=n)and(r>=1) do
  if a[l]+b[r]>=m then begin inc(q);dec(r);inc(l);end else inc(l);
 writeln(1,' ',q);
end.