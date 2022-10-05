Program CodeF_416_A;
var kol,a,b:int64;
begin
read(a,b);
while (a>=0) and (b>=0) do
  begin
  inc(kol);
  if kol mod 2=1 then a:=a-kol
    else b:=b-kol;
  end; 
if a<0 then write('Vladik')
  else write('Valera');


end.