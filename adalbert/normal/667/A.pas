var d,h,v,e:longint;
m:real;
begin
read(d,h,v,e);
m:=v/pi/d/d*4;
if m>e then
begin
writeln('YES');
writeln(h/(m-e));
end else writeln('NO');


end.