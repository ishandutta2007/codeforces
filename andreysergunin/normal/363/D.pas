var i,m,n,a,l,r,t:longint;
    k,s:int64;
    p,b:array[1..100000] of longint;
procedure qsort1(l,r: integer);
var
  i,j,x,y: integer;
begin
  i:=l; j:=r; x:=b[(l+r) DIV 2];
  repeat
    while b[i]<x do i:=i+1;
    while x<b[j] do j:=j-1;
    if i<=j then
    begin
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
end;

procedure qsort2(l,r: integer);
var
  i,j,x,y: integer;
begin
  i:=l; j:=r; x:=p[(l+r) DIV 2];
  repeat
    while p[i]<x do i:=i+1;
    while x<p[j] do j:=j-1;
    if i<=j then
    begin
      y:=p[i]; p[i]:=p[j]; p[j]:=y;
      i:=i+1; j:=j-1;
    end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
end;


begin
read (n,m,a);
for i:=1 to n do read (b[i]);
for i:=1 to m do read (p[i]);
qsort1(1,n);
qsort2(1,m);
l:=0;
if n<=m then r:=n+1
        else r:=m+1; 
while r-l>1 do
        begin
         t:=(l+r) div 2;
         k:=0;
         for i:=n-t+1 to n do
                begin
                 if b[i]<p[i-n+t] then k:=k+p[i-n+t]-b[i];
                end;
         if k<=a then
                 l:=t
                 else r:=t;

        end;
write (l,' ');
s:=0;
for i:=1 to l do s:=s+p[i];
if a>=s then write ('0')
        else write (s-a);

end.