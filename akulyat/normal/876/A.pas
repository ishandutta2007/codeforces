Program LetsTry;
var  n,i,j,a,b,c,kil:longint;
     mas:array[1..110]of longint;
begin
read(n);
read(a,b,c);
mas[1]:=1;
for i:=2 to n do 
  begin
  if mas[i-1]=3 then
    begin
    if b<c then
      mas[i]:=1 else
      mas[i]:=2;
    end;
  if mas[i-1]=2 then
    begin
    if a<c then
      mas[i]:=1 else
      mas[i]:=3;
    end;
  if mas[i-1]=1 then
    begin
    if b<a then
      mas[i]:=3 else
      mas[i]:=2;
    end;
    end;
for i:=1 to n-1 do
  begin
  if ((mas[i]=1) and (mas[i+1]=2)) or ((mas[i]=2) and (mas[i+1]=1))then kil:=kil+a;
  if ((mas[i]=1) and (mas[i+1]=3)) or ((mas[i]=3) and (mas[i+1]=1))then kil:=kil+b;
  if ((mas[i]=3) and (mas[i+1]=2)) or ((mas[i]=2) and (mas[i+1]=3))then kil:=kil+c;
  end;
writeln(kil);





end.