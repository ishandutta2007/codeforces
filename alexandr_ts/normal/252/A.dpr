var a:array[1..100] of longint;
    n,i,j,k,x,xmax:longint;
begin
read(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n do
    for j:=i to n do
        begin
        x:=0;
        for k:=i to j do
           x:=x xor a[k];
        if x>xmax then
         xmax:=x;
        end;
write(xmax);
end.