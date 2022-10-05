Program Bukovki;
var kol,max,i,j,u,n:longint;
    mas:array[1..26]of longint;
    por:array[0..201]of longint;
    s:string;

begin
readln(n);
readln(s);
j:=0;
for i:=1 to length(s) do
  if ord(s[i])<=90 then
    begin
    inc(j);
    por[j]:=i;    
    end;
por[0]:=0;
por[j+1]:=n+1;

for i:=0 to j do
  begin
  for u:=1 to 26 do mas[u]:=0;
  kol:=0;
  for u:=por[i]+1 to por[i+1]-1 do
    begin
    inc(mas[ord(s[u])-ord('a')+1]);
    if mas[ord(s[u])-ord('a')+1]=1 then inc(kol);
    end;
  if kol>max then max:=kol;
  end;
writeln(max);



end.