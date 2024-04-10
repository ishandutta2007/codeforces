uses math;
var
  n,m,ans:longint;
  i:longint;
begin
  read(n,m);

  for i:=1 to n div m do
    if (2*i*m>=n) and (i*m<=n) then begin writeln(i*m); halt; end;
  writeln(-1);
end.