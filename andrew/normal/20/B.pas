var
 a,b,c,d,x1,x2:extended;
procedure swap(var a,b:extended);
var c:extended;
begin
 c:=a;
 a:=b;
 b:=c;
end;
begin
 readln(a,b,c);
 if(a=0)and(b=0)and(c<>0) then
 begin
  writeln(0);
  halt;
 end;
 if(a=0)and(b=0)and(c=0)then
 begin
  writeln(-1);
  halt;
 end;
 if a=0 then
 begin
  x1:=-c/b;
  writeln(1);
  writeln(x1:0:5);
  halt;
 end;
 d:=sqr(b)-4*a*c;
 if d<0 then begin writeln(0); halt; end;
 x1:=(-b+sqrt(d))/(2*a);
 x2:=(-b-sqrt(d))/(2*a);
 if d=0 then
 begin
  writeln(1);
  writeln(x1:0:5);
 end else
 begin
  if x1>x2 then swap(x1,x2);
  writeln(2);
  writeln(x1:0:5);
  writeln(x2:0:5);
 end;
end.