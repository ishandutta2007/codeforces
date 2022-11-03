var i:longint;
n,s,max:int64;
a:array[1..1000000] of int64;
begin
read(n);
for i:=1 to n do read(a[i]);
for i:=1 to n do if a[i]>max then max:=a[i];
for i:=1 to n do s:=s+a[i];
s:=s-max;
writeln(max-s+1);
end.