uses math;
var
  a,b,r:longint;
begin
  read(a,b,r);
  r:=2*r;
  r:=(a div r)*(b div r);
  if r=0 then writeln('Second')
  else writeln('First');
end.