program z1;
var a,b,c,d,x1,x2,x3,y1,y2,y3:longint;
begin
readln(x1,y1);
readln(x2,y2);
readln(x3,y3);
writeln(3);
writeln(x1+(x2-x3),' ',y1+(y2-y3));
writeln(x1+(x3-x2),' ',y1+(y3-y2));
writeln(x3+(x2-x1),' ',y3+(y2-y1));
end.