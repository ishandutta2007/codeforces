var a:array[1..100000]of int64;
    x,s:int64;i,n:longint;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 x:=1;
 for i:=1 to 64 do
  if x<n then x:=x*2 else break;
 for i:=1 to n-1 do
 begin
  if i+x>n then x:=x div 2;
  s:=s+a[i];
  a[i+x]:=a[i+x]+a[i];
  writeln(s);
 end;
end.