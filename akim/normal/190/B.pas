var x1,y1,r1,x2,y2,r2:longint;
    l:extended;
function max(x,y:extended):extended;
begin max:=x; if x<y then max:=y;end;
begin
 readln(x1,y1,r1,x2,y2,r2);
 l:=sqrt(sqr(x2-x1)+sqr(y2-y1));
 if (l+r1<r2) then writeln(((r2-r1-l)/2):1:10) else
 if (l+r2<r1) then writeln(((r1-r2-l)/2):1:10) else
 writeln((max(l-r1-r2,0)/2):1:10);
end.