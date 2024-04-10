uses math;
var
  a:array[1..10000]of longint;
  n,d,s,sv,ans:longint;
  i:longint;
begin
  read(n,d);
  for i:=1 to n do
    read(a[i]);

  s:=0;
  for i:=1 to n do
    inc(s,a[i]);
  sv:=s+(n-1)*10;
  if sv>d then begin writeln(-1); halt; end;
  dec(d,s);
  ans:=d div 5;

  writeln(ans);
end.