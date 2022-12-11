var a:array[-10..10]of int64;s:int64;i,n,x:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(x);
  inc(a[x]);
 end;
 s:=a[0]*(a[0]-1)div 2;
 for i:=1 to 10 do
 begin
  s:=s+a[i]*a[-i];
 end;
 writeln(s);
end.