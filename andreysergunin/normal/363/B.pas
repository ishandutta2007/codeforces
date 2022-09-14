var a,b,c,d:array[0..500001] of longint;
    n,i,k:longint;
procedure qsort(l,r: integer);
var
  i,j,x,y: integer;
begin
  i:=l; j:=r; x:=c[l+random (r-l+1)];
  repeat
    while c[i]<x do i:=i+1;
    while x<c[j] do j:=j-1;
    if i<=j then
    begin
      y:=c[i]; c[i]:=c[j]; c[j]:=y;
      y:=d[i]; d[i]:=d[j]; d[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

begin
read (n,k);
for i:=1 to n do read (a[i]);
b[0]:=0;
for i:=1 to n do b[i]:=b[i-1]+a[i];
for i:=1 to n-k+1 do c[i]:=b[i+k-1]-b[i-1];
for i:=1 to n-k+1 do d[i]:=i;
qsort (1,n-k+1);
writeln (d[1]);
end.