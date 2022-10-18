uses math;
var
  a1,a2,a3,b1,b2,b3:longint;
  n,nv:longint;
begin
  read(a1,a2,a3,b1,b2,b3,n);
  a1:=a1+a2+a3;
  b1:=b1+b2+b3;
  nv:=a1 div 5+sign(a1 mod 5)+b1 div 10+sign(b1 mod 10);
  if nv>n then writeln('NO')
  else writeln('YES');
end.