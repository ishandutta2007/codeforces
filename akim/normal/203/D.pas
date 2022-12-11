var x,y,z,vx,vy,vz,dx,dz:extended;
begin
 readln(x,z,y);
 readln(vx,vy,vz);
 dx:=abs(vx*(y/-vy));
 dz:=vz*(y/-vy);
 if abs(dx)>x/2 then 
 begin 
  if ((trunc((dx-x/2)/x)+1)mod 2=1) then 
  begin
   if vx>0 then write((x-(frac((dx-x/2)/x)*x)):1:10,' ') else write(((frac((dx-x/2)/x)*x)):1:10,' ');
  end else 
  begin
   if vx>0 then write((frac((dx-x/2)/x)*x):1:10,' ') else write((x-(frac((dx-x/2)/x)*x)):1:10,' ');
  end;
 end else if vx>0 then write((x/2+dx):1:10,' ') else write(x-(x/2+dx):1:10,' ');
 if trunc(dz/z)mod 2=1 then writeln((z-frac(dz/z)*z):1:10) else writeln((frac(dz/z)*z):1:10);
end.