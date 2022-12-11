var a:array[1..10000]of longint;
    n,i,mi:longint;
function max(x,y:longint):longint;
begin
 max:=x;if y>x then max:=y;
end;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 mi:=999999;
 for i:=1 to n-1 do
  if max(a[i],a[i+1])<mi then mi:=max(a[i],a[i+1]);
 if a[1]<mi then mi:=a[1];
 if a[n]<mi then mi:=a[n];
 writeln(mi);
end.