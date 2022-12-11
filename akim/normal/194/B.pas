var a:int64;n,i:longint;
function nod(x,y:int64):int64;
begin if x<>0 then nod:=nod(y mod x,x) else nod:=y;end;
function nok(x,y:int64):int64;
begin nok:=( x div NOD(x,y) ) * y;end;

begin
 readln(n);
 for i:=1 to n do
 begin
  read(a);
  writeln(nok(a+1,a*4) div (a+1)+1);
 end;
end.