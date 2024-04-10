uses math;
var
  a:array[1..100000]of longint;
  n,s,ans:longint;
  i:longint;
begin
  read(n);
  s:=0;
  ans:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      inc(s,a[i]);
    end;

  if s mod 2=0 then
    for i:=1 to n do
      if a[i] mod 2=0 then inc(ans);
  if s mod 2=1 then
    for i:=1 to n do
      if a[i] mod 2=1 then inc(ans);

  writeln(ans);
end.