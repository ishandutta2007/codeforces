Program TakChtoLi;
var itog,n,i,j,min,max:longint;
    cha:char;
    mas:array[0..100000]of boolean;
    kol:array[0..100000]of longint;
    e,s:array[-100000..100000]of longint;
  
  
begin
readln(n);
for i:=1 to n do 
  begin
  read(cha);
  if cha='0' then mas[i]:=false else
    mas[i]:=true;
  end;
  
for i:=1 to n do 
  if mas[i]=true then
    kol[i]:=kol[i-1]+1 else
      kol[i]:=kol[i-1]-1;
      
     
min:=kol[1];
max:=kol[1];
if min>0 then 
  min:=0;      
if max>0 then 
  max:=0;      
for i:=0 to n do
  begin
  e[kol[i]]:=i;
  if s[kol[i]]=0 then
  s[kol[i]]:=i;
  if min>kol[i] then
    min:=kol[i];
  if max<kol[i] then
    max:=kol[i];    
  end;
s[0]:=0;
itog:=0;
for i:=min to max do
  if e[i]-s[i]>itog
    then itog:=e[i]-s[i];
//for i:=1 to n do
//  write(kol[i], ' ');
//writeln;
//for i:=min to max do write(s[i], ' ', e[i], '   ' );  
//writeln;  
//writeln(min,'  ', max);  
writeln(itog);  
end.