var c,d,i,j,k,l,m,n,n1,n2:longint; Z:array[1..100000] of longint;
e:extended; a,b:int64;

Function min(x,y:longint):longint;
begin
if x<y then exit(x) else exit(y);
end;

Function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

Procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
i:=l; j:=r; x:=Z[(l+r)>>1];
repeat
while Z[i]<x do inc(i);
while Z[j]>x do dec(j);
if not(i>j) then
 begin
 y:=Z[i]; Z[i]:=Z[j]; Z[j]:=y;
 inc(i); dec(j);
 end;
until i>j;
if l<j then qsort(l,j);
if i<r then qsort(i,r);
end;

begin
//assign(input,'d:\input.txt'); reset(input);
//assign(output,'d:\output.txt'); rewrite(output);
readln(n,n1,n2);
for i:=1 to n do read(Z[i]);
qsort(1,n);
for i:=n downto n-min(n1,n2)+1 do a:=a+Z[i];
for i:=n-min(n1,n2) downto n-min(n1,n2)-max(n1,n2)+1 do b:=b+Z[i];
e:=a/min(n1,n2)+b/max(n1,n2);
writeln(e:0:7);
end.