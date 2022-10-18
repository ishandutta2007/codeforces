uses math;
var
  a,b,s:longint;
begin
  read(a,b,s);
  if (abs(a)+abs(b)<=s) and ((abs(a)+abs(b)) mod 2=s mod 2) then writeln('Yes')
  else writeln('No');
end.