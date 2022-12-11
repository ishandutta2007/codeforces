var n,m,max,min,i,f,l:longint;
    a,b:array[0..1100]of longint;
procedure qsort(l,r:longint);
var x,z,i,f:longint;
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
                z:=b[i];
                b[i]:=b[f];
                b[f]:=z;
                inc(i);
                dec(f);
               end;
 end;
 if l<f then qsort(l,f);
 if i<r then qsort(i,r);
end;
begin
 readln(n,m);l:=n;
 for i:=1 to m do
 begin
  read(a[i]);
  b[i]:=a[i];
 end;
 qsort(1,m);
 min:=0;
 for f:=1 to m do
  while (a[f]>0)and(n>0) do
  begin
   min:=min+a[f];
   dec(a[f]);
   dec(n);
  end;
 max:=0;f:=m;n:=l;
 while f>0 do
 begin
  while (b[f]>b[f-1])and(n>0) do
  begin
   max:=max+b[f];
   dec(b[f]);
   dec(n);
   while b[f]<b[f+1] do inc(f);
  end;
  dec(f);
 end;
 writeln(max,' ',min);
end.