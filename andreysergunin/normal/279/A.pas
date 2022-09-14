var x,y:longint;
begin
read (x,y);
if (y=0) and (x=0) then write ('0');
if (y>x) and (-x<=y) then write (4*y-2);
if (y>=x) and (-x>y) then write (-4*x-1);
if (y<x) and (y<=-x+1) then write (-4*y);
if (y<=x) and (y>-x+1) then write (4*x-3)

end.