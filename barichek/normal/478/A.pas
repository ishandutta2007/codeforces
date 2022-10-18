uses math;
var
  a,b,c,d,e:longint;
begin
  read(a,b,c,d,e);
  a:=a+b+c+d+e;
  if (a mod 5<>0) or (a=0) then begin writeln(-1); halt; end
  else writeln(a div 5);
end.