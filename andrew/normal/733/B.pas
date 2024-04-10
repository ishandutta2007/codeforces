var
 a,b:array[1..100000]of longint;
 s1,s2,s,i,j,n,k,m,l,d,l1,r1,r:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(a[i],b[i]);
  inc(l,a[i]);
  inc(r,b[i]);
 end;
 s:=abs(l-r);
 for i:=1 to n do
  if (a[i]>b[i]) then
  begin
   l1:=l-a[i]+b[i];
   r1:=r-b[i]+a[i];
   if s<abs(l1-r1) then begin m:=i; s:=abs(l1-r1); end;
  end;

  for i:=1 to n do
  if (b[i]>a[i]) then
  begin
   l1:=l-a[i]+b[i];
   r1:=r-b[i]+a[i];
   if s<abs(l1-r1) then begin m:=i; s:=abs(l1-r1); end;
  end;
 writeln(m);
end.