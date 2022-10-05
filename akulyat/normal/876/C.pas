Program Chislo;
var  n,i,kol:longint;
     mas:array[1..100]of longint;
 


Function Tryy(a:longint);
var a1:longint;
begin
a1:=a;
while a1>0 do
  begin
  a:=a+(a1 mod 10);
  a1:=a1 div 10;
  end;
Tryy:=a;
end; 

begin
read(n);
for i:=n-1 downto n-1-100 do
  begin
  if i>=1 then
    if tryy(i)=n then
      begin
      inc(kol);
      mas[kol]:=i;
      end;
  end;

writeln(kol);
for i:=kol downto 1 do
  begin
  writeln(mas[i], ' ');
  end;


end.