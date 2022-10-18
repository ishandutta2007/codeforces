uses math;
var
  n,m,ans:longint;
  i:longint;
begin
  read(n,m);
  ans:=n;
  repeat
    inc(ans,n div m);
    n:=n div m+n mod m;
  until n<m;
  writeln(ans);
end.