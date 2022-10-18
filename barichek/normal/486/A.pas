uses math;
var
  n,ans:int64;
begin
  read(n);
  if n mod 2=0 then ans:=n div 2;
  if n mod 2=1 then ans:=n div 2-n;

  writeln(ans);
end.