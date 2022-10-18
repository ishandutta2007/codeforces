uses math;
var
  a:array[0..9999999]of longint;
  n,ans:int64;
  i:longint;
begin
  read(n);
  a[0]:=0;
  ans:=0;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    inc(ans,abs(a[i]-a[i-1]));
  writeln(ans);
end.