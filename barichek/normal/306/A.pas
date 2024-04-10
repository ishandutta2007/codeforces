uses math;
var
  n,m:longint;
  i:longint;
begin
  read(n,m);

  for i:=1 to n mod m do
    write(n div m+1,' ');
  for i:=1 to m-n mod m do
    write(n div m,' ');
end.