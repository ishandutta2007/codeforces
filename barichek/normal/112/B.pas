uses math;
var
  n,x,y:longint;
  h:longint;
begin
  read(n,x,y);
  h:=0;
  if (x=n div 2) or (x=n div 2+1) then inc(h);
  if (y=n div 2) or (y=n div 2+1) then inc(h);

  if h=2 then writeln('NO')
  else writeln('YES');
end.