{$h+}
var a,b:ansistring;
    x:array[-3000..3000]of longint;
    max,i,f,l,n:longint;
begin
 max:=0;
 readln(a);
 readln(b);
 n:=length(a);
 l:=length(b);
 for i:=1 to n do
  for f:=1 to l do
   if a[i]=b[f] then inc(x[f-i]);
 for i:=-3000 to 3000 do
  if x[i]>max then max:=x[i];
 writeln(l-max);
end.