var a:array[1..200200,1..2]of longint;
    k,pere,i,x,y,n,z1,z2:longint;
procedure qsort(l,r:longint);
var x,z,i,f:longint;
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
 readln(n);k:=0;
 for i:=1 to n do
 begin
  readln(x,y);
  if x=y then begin inc(k);a[k,1]:=x;a[k,2]:=1;end else begin inc(k,2);a[k-1,1]:=x;a[k-1,2]:=1;a[k,1]:=y;a[k,2]:=2;end;
 end;
 qsort(1,k);
 if n mod 2=1 then n:=n div 2+1 else n:=n div 2;
 i:=1;pere:=$7fffffff;
 while i<=k do
 begin
  if a[i,2]=2 then begin z2:=1;z1:=0;end else begin z2:=0;z1:=1;end;
  while a[i,1]=a[i+1,1] do
  begin
   inc(i);
   if a[i,2]=2 then inc(z2) else inc(z1);
  end;
  if (z1+z2>=n)and(n-z1<pere) then pere:=n-z1;
  inc(i);
 end;
 if pere<0 then writeln(0) else if pere=$7fffffff then writeln('-1') else writeln(pere);
end.