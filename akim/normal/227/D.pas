var a,b:array[0..1000000]of int64;
    l,r,s,y,m:int64;n,k,i,f,t:longint;log:boolean;
procedure qsort(l,r:longint);
var i,f:longint;z,x:int64;
begin
 i:=l;f:=r;x:=a[random(r-l)+l];
 while i<f do
 begin
  while a[i]>x do inc(i);
  while a[f]<x do dec(f);
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
 readln(n);
 for i:=0 to n-1 do
  read(a[i]);
 qsort(0,n-1);
 b[0]:=a[0];
 for i:=1 to n-1 do
  b[i]:=b[i-1]+a[i];
 readln(m);log:=false;
 for i:=1 to m do
 begin
  read(k);
  if k=1 then
  begin
   if not(log) then
   begin
    y:=0;log:=true;
    for f:=1 to n-1 do
     y:=y+a[f]*f;
    s:=y;
   end else
    s:=y;
  end else
  begin
   l:=0;r:=k;s:=0;t:=1;
   while l<=n-1 do
   begin
    if l+r>=n-1 then s:=s+(b[n-1]-b[l])*t else s:=s+(b[l+r]-b[l])*t;
    l:=l+r;r:=r*k;inc(t);
   end;
  end;
  write(s,' ');
 end;
end.