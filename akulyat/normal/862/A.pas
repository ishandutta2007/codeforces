Program Shuba;
var i,n,x,ch,nal,kol:byte;





begin
read(n, x);
for i:=1 to n do 
  begin
  read(ch);
  if ch=x then nal:=1;
  if ch<x then inc(kol);
  end;

writeln(x-kol+nal);





end.