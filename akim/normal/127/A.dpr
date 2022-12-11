var i,n,m,x1,x2,y1,y2:longint;o:extended;
begin
 readln(n,m);
 readln(x1,y1);
 o:=0;
 for i:=2 to n do
 begin
  readln(x2,y2);
  o:=o+sqrt(sqr(x1-x2)+sqr(y1-y2));
  x1:=x2;y1:=y2;
 end;
 o:=o/50*m;
 writeln(o:1:10);
end.