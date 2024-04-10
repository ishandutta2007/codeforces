Program CodeF_425_A;
var d:int64;
    a,b,i:longint;
begin
read(a,b);
d:=1;
if a<b then
  for i:=1 to a do
    d:=d*i
  else    
    for i:=1 to b do
      d:=d*i;
write(d);

end.