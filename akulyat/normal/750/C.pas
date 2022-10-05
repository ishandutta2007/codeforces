Program Reality;
var cur,full,mi1,mi2,ma1,ma2,i,n,c,d:longint;

begin
read(n);
mi1:=400000001; mi2:=40000001; ma1:=-40000001; ma2:=-40000001;
for i:=1 to n do
  begin
  read(c, d);
  cur:=full+c;
  if d=1 then
    begin
    if full<mi1 then mi1:=full;
    if full>ma1 then ma1:=full;
    end else
    begin
    if full<mi2 then mi2:=full;
    if full>ma2 then ma2:=full;
    end;    
  if (ma2>=mi1) and (ma2<>-40000001) and (mi1<>40000001) then
    begin
    writeln('Impossible');
    exit;
    end;
  full:=full+c;  
  end;
if ma2=-40000001 then
  begin
  writeln('Infinity');
  exit;
  end;

writeln(1899-ma2+full);



end.