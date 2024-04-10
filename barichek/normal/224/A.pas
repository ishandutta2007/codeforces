uses math;
var
  a,b,c:int64;
begin
  read(a,b,c);
  writeln(4*(sqrt(a*b*c)/a+sqrt(a*b*c)/b+sqrt(a*b*c)/c):0:0);
end.