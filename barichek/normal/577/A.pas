var
  i,n,x,ans:longint;
begin
  read(n,x);
  ans:=0;
  for i:=1 to n do
      if (x mod i=0) and (x div i<=n) then inc(ans);
  writeln(ans);
end.