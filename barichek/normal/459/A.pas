uses math;
var
  x1,y1,x2,y2,x3,y3,x4,y4:longint;
begin
  read(x1,y1,x2,y2);
  if (x1<>x2) and (y1<>y2) and (abs(x2-x1)<>abs(y2-y1)) then
                                                begin
                                                  writeln(-1);
                                                  halt;
                                                end;
       if x1=x2 then
         begin
           x3:=x1+abs(y1-y2);
           y3:=y1;
           x4:=x3;
           y4:=y2;
         end
  else if y1=y2 then
         begin
           x3:=x1;
           y3:=y1+abs(x2-x1);
           x4:=x2;
           y4:=y3;
         end
  else
         begin
           x3:=x1;
           y3:=y2;
           x4:=x2;
           y4:=y1;
         end;
  writeln(x3,' ',y3,' ',x4,' ',y4);
end.