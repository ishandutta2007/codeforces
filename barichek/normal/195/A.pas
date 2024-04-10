uses math;
var
  a,b,c:longint;
begin
  read(a,b,c);
  writeln((a*c)div b+sign((a*c)mod b)-c);
end.