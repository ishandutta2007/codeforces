uses math;
var
  a:array[1..10000]of longint;
  n,mini:int64;
  i,j:longint;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  mini:=abs(a[1]-a[n]);
  for i:=2 to n do
    mini:=min(mini,abs(a[i]-a[i-1]));

  if abs(a[1]-a[n])=mini then begin writeln(1,' ',n); halt; end;
  for i:=2 to n do
    if abs(a[i]-a[i-1])=mini then begin writeln(i-1,' ',i); halt; end;
end.