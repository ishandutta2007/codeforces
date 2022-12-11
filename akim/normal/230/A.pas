var a:array[1..10000,1..2]of longint;
    s,n,i:longint;
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
begin
 readln(s,n);
 for i:=1 to n do
  read(a[i,1],a[i,2]);
 qsort(1,n);
 for i:=1 to n do
  if s>a[i,1] then s:=s+a[i,2] else begin writeln('NO');halt(0);end;
 writeln('YES');
end.