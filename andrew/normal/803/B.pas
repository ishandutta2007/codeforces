var
 a,l,r:array[1..200000]of longint;
 dl1,dl2,sc,n,m,i,j,l1,r1:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
 begin
  if a[i]=0 then l1:=i;
  l[i]:=l1;
 end;

 for i:=n downto 1 do
 begin
  if a[i]=0 then r1:=i;
  r[i]:=r1;
 end;

 for i:=1 to n do
 begin
  dl1:=maxlongint;
  dl2:=maxlongint;
  if l[i]<>0 then dl1:=i-l[i];
  if r[i]<>0 then dl2:=r[i]-i;
  if dl1<dl2 then write(dl1) else write(dl2);
  write(' ');
 end;
end.