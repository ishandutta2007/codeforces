var a,b,x,y,x1,y1,x2,y2:extended;kx1,kx2,ky1,ky2,rx,ry:longint;
function max(x,y:longint):longint;
begin max:=x;if y>x then max:=y;end;
function min(x,y:longint):longint;
begin min:=x;if y<x then min:=y;end;
begin
 readln(a,b,x1,y1,x2,y2);
 a:=a*sqrt(2);
 b:=b*sqrt(2);
 x:=x1;y:=y1;
 x1:=x/sqrt(2)-y/sqrt(2);
 y1:=x/sqrt(2)+y/sqrt(2);
 x:=x2;y:=y2;
 x2:=x/sqrt(2)-y/sqrt(2);
 y2:=x/sqrt(2)+y/sqrt(2);
 if x1<0 then x1:=x1-b;
 if x2<0 then x2:=x2-b;
 if y1<0 then y1:=y1-a;
 if y2<0 then y2:=y2-a;
 kx1:=trunc(x1/b);
 ky1:=trunc(y1/a);
 kx2:=trunc(x2/b);
 ky2:=trunc(y2/a);
 rx:=abs(kx1-kx2);
 ry:=abs(ky1-ky2);
 writeln(max(rx,ry));
end.