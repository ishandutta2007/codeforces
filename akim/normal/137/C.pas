var a:array[1..100100,1..2]of longint;
    s,i,n,m:longint;
procedure swap(var x,y:longint);
var z:longint;begin z:=x;x:=y;y:=z;end;
procedure qsort(l,r:longint);
var i,f,x:longint;
begin
 i:=l;f:=r;
 x:=a[l+random(r-l),1];
 while i<=f do
 begin
  while a[i,1]<x do inc(i);
  while a[f,1]>x do dec(f);
  if i<=f then begin
                swap(a[i,1],a[f,1]);
                swap(a[i,2],a[f,2]);
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
  readln(a[i,1],a[i,2]);
 qsort(1,n);s:=0;
 m:=a[1,2];
 for i:=2 to n do
  if (m>a[i,2]) then begin inc(s);end else m:=a[i,2];
 writeln(s);
end.