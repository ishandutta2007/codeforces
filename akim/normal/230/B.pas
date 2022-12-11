var a:array[1..1000100]of boolean;
    b:array[1..1000100]of int64;
    n,m,l,r,i,f,q:longint;k:int64;
begin
 q:=0;
 for i:=2 to 1000100 do
  if a[i]=false then
  begin
   f:=i*2;
   while f<=1000100 do begin a[f]:=true;f:=f+i;end;
   inc(q);
   b[q]:=sqr(int64(i));
  end;
 readln(n);
 for i:=1 to n do
 begin
  read(k);
  l:=1;r:=q+1;
  while l+1<r do
  begin
   m:=(l+r)div 2;
   if b[m]<=k then l:=m else r:=m;
  end;
  if b[l]=k then writeln('YES') else writeln('NO');
 end;
end.