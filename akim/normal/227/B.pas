var a:array[1..100000,1..2]of longint;
    p,s,l:int64;
    k,i,n,o:longint;
procedure qsort(l,r:longint);
var i,f,x,z:longint;
begin
 i:=l;f:=r;x:=a[random(r-l)+l,1];
 while i<f do
 begin
  while a[i,1]<x do inc(i);
  while a[f,1]>x do dec(f);
  if i<=f then begin
                z:=a[i,1];
                a[i,1]:=a[f,1];
                a[f,1]:=z;
                z:=a[i,2];
                a[i,2]:=a[f,2];
                a[f,2]:=z;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
function bp(x:longint):longint;
var l,r,m:longint;
begin
 l:=1;r:=n+1;
 while l+1<r do
 begin
  m:=(l+r)div 2;
  if a[m,1]<=x then l:=m else r:=m;
 end;
 bp:=a[l,2];
end;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(a[i,1]);
  a[i,2]:=i;
 end;
 qsort(1,n);
 readln(o);
 for i:=1 to o do
 begin
  read(k);
  l:=bp(k);
  p:=p+l;
  s:=s+n-l+1;
 end;
 writeln(p,' ',s);
end.