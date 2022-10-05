Program LetsTry;
var  n,i,j,k,m,kak,kol:longint;
     os,mas:array[0..100001]of longint;
begin
read(n,k,m);
for i:=1 to n do 
  begin
  read(mas[i]);
  inc(os[mas[i] mod m]);
  end;  

kak:=-1;
for i:=0 to m-1 do
  if os[i]>=k then
    kak:=i;

kol:=0;
i:=1;
if kak=-1 then writeln('No') else    
  begin
  writeln('Yes');
  while kol<>k do
    begin
    if mas[i]mod m=kak then
      begin
      inc(kol);
      write(mas[i], ' ');
      end;
    inc(i)  
    end;
  end;



end.