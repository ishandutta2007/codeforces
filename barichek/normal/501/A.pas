uses math;
var
  a,b,c,d:longint;
  m,v:real;
begin
  read(a,b,c,d);

  m:=max((3*a)div 10,a-(a*c)div 250);
  v:=max((3*b)div 10,b-(b*d)div 250);
  if m=v then writeln('Tie');
  if m>v then writeln('Misha');
  if m<v then writeln('Vasya');
end.