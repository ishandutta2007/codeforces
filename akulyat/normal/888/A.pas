Program MINMAX;
var mas:array[1..1004]of longint;
   kol,n,i:longint;

begin
read(n);
for i:=1 to n do
  begin
  read(mas[i]);
  if i>=3 then
    if ((mas[i-1]>mas[i-2]) and (mas[i-1]>mas[i])) or ((mas[i-1]<mas[i-2]) and (mas[i-1]<mas[i]))
      then inc(kol);
  end;
writeln(kol);




end.