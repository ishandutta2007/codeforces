var a:array[1..100]of longint;
    n,i,x:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(x);
  inc(a[x]);
 end;
 x:=0;
 for i:=1 to 100 do
  x:=x+a[i] div 2;
 writeln(x div 2);
end.