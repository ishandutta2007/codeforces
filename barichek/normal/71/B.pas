uses math;
var
  n,k,t,ans:longint;
  i:longint;
begin
  read(n,k,t);
  ans:=trunc(n*k*t/100);

  for i:=1 to ans div k do
    write(k,' ');
  if t<>100 then write(ans mod k,' ');
  for i:=1 to n-ans div k-1 do
    write(0,' ');
  writeln;

end.