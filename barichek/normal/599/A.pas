uses math;
var
  d1,d2,d3:longint;
begin
  read(d1,d2,d3);
  writeln(min(d1+d2+d3,min(2*d1+2*d2,min(2*d1+2*d3,2*d2+2*d3))));
end.