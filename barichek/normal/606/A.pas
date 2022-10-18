uses math;
var
  a,b,c,x,y,z:longint;
  i,j:longint;
begin
  read(a,b,c,x,y,z);
  i:=0;
  j:=0;

  if a>x then inc(i,(a-x)div 2)
    else inc(j,x-a);
  if b>y then inc(i,(b-y)div 2)
    else inc(j,y-b);
  if c>z then inc(i,(c-z)div 2)
    else inc(j,z-c);

  if i>=j then writeln('Yes')
    else writeln('No');
end.