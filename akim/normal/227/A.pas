var x1,x2,x3,y1,y2,y3:longint;
begin
 readln(x1,y1);
 readln(x2,y2);
 readln(x3,y3);
 if int64(x2-x1)*(y3-y2)-int64(y2-y1)*(x3-x2)<0 then writeln('RIGHT') else
 if int64(x2-x1)*(y3-y2)-int64(y2-y1)*(x3-x2)>0 then writeln('LEFT') else
  writeln('TOWARDS');
end.