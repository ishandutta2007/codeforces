uses math;
var
  n:int64;
  i:longint;
  j,ans:extended;
begin
  read(n);
  for i:=1 to n do
    begin
      j:=i;
      ans:=ans+power(2,j);
    end;

  writeln(ans:0:0)
end.