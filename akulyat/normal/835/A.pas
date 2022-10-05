Program Runeri;
var n,v1,v2,t1,t2,i1,i2:longint;

begin
read(n,v1,v2,t1,t2);
i1:=2*t1+n*v1;
i2:=2*t2+n*v2;
if i1=i2 then writeln('Friendship') else
  if i1<i2 then writeln('First') else
    writeln('Second');
end.