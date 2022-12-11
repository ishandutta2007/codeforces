var a:array[1..100000,1..2]of longint;
    n,i,f,x:longint;
procedure qsort(l,r:longint);
var i,f,x,z:longint;
begin
 i:=l;f:=r;x:=a[l+random(r-l),1];
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
 readln(n);
 for i:=1 to n do
 begin
  read(a[i,1]);
  a[i,2]:=i;
 end;
 qsort(1,n);
 if n mod 2=1 then writeln(n div 2+1)else writeln(n div 2);
 for i:=1 to n do
  if i mod 2=1 then write(a[i,2],' ');
 writeln;writeln(n div 2);
 for i:=1 to n do
  if i mod 2=0 then write(a[i,2],' ');
end.