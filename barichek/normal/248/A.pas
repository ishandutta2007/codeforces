uses math;
var
  n,a1,a2,sum1,sum2:longint;
  i:longint;
begin
  read(n);
  sum1:=0;
  sum2:=0;
  for i:=1 to n do
    begin
      read(a1,a2);
      inc(sum1,a1);
      inc(sum2,a2);
    end;
  writeln(min(n-sum1,sum1)+min(n-sum2,sum2));
end.