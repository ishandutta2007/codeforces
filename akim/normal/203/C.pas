var a:array[1..100100,1..2]of int64;
    i:longint;n,m,k,l,x,y:int64;
procedure qsort(l,r:longint);
var i,f:longint;x,z:int64;
begin
 i:=l;f:=r;x:=a[random(r-l)+l,1];
 while i<=f do
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
begin
 readln(n,m);
 readln(k,l);
 for i:=1 to n do
 begin
  readln(x,y);
  a[i,1]:=x*k+y*l;
  a[i,2]:=i;
 end;
 qsort(1,n);k:=m;l:=0;
 for i:=1 to n do
  if k-a[i,1]>=0 then begin inc(l);k:=k-a[i,1];end else break;
 writeln(l);
 for i:=1 to l do
  write(a[i,2],' ');
end.