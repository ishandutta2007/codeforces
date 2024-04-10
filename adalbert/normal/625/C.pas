var n,k,h,m,z,x:int64;
i,j:longint;
a:array[1..600,1..600] of longint;
begin
read(n,k);
z:=1;
x:=1;
for i:=1 to (k-1)*n do
begin
a[z,x]:=i;
z:=z+1;
if z>k-1 then
    begin
    x:=x+1;
    z:=1;
    end;
end;
z:=k;
x:=1;
for i:= (k-1)*n+1 to n*n do
begin
a[z,x]:=i;
z:=z+1;
if z>n then
    begin
    x:=x+1;
    z:=k;
    end;
end;
z:=0;
for i:=1 to n do
z:=z+a[k,i];
writeln(z);

for i:=1 to n do
begin
for j:=1 to n do write(a[j,i],' ');
writeln;
end;
end.