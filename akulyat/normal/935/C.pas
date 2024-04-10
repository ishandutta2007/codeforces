Program CodeF_456_A;
var r,x1,x2,y1,y2:int64;
    a,b,l:double;


begin
read(r,x1,y1,x2,y2);
if (sqr(x1-x2)+sqr(y1-y2)>=r*r) then
  begin
  writeln(x1,' ', y1, ' ', r);
  exit;
  end;
l:=sqrt(sqr(x1-x2)+sqr(y1-y2));
if (l<>0) then
  begin
  a:=x1-(x2-x1)*(r/l);
  b:=y1-(y2-y1)*(r/l);
  end else
  begin
  a:=x1+r;
  b:=y1;
  end;
writeln((a+x2)/2, ' ', (b+y2)/2, ' ', (l+r)/2);


end.