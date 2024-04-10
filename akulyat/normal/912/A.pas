Program Balls;
var a,b,x,y,z:int64;

Function min(a,b:int64):int64;
begin
if a<b then
  min:=a else
  min:=b;

end;
begin
read(a,b);
read(x,y,z);
a:=a-2*x-y;
if a>0 then a:=0;
b:=b-3*z-y;
if b>0 then b:=0;
writeln(-a-b);

end.