uses math;
var
  n,a,sum,ans:longint;
  i:longint;
begin
  read(n);
  sum:=0;
  for i:=1 to n do
    begin
      read(a);
      inc(sum,a);
    end;

  ans:=0;
  for i:=1 to 5 do
    if (sum+i)mod(n+1)<>1 then inc(ans);
  writeln(ans);
end.