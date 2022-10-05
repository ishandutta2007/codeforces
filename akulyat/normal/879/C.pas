Program Calc;
var  mas:array[1..10]of  byte;
     j,i,n,ch:longint;
     s:string;
  
Procedure Vi;
var i:longint;
begin
for i:=1 to 10 do
  write(mas[i], ' ');
writeln;
end;  

Procedure ANDi(a:longint);
var i:longint;
    ch:array[1..10]of byte;
begin
for i:=10 downto 1 do
  begin
  ch[i]:=a mod 2;
  a:=a div 2;
  end;

for i:=1 to 10 do
  if ch[i]=0 then
    mas[i]:=0;

end;

Procedure ORi(a:longint);
var i:longint;
    ch:array[1..10]of byte;
begin
for i:=10 downto 1 do
  begin
  ch[i]:=a mod 2;
  a:=a div 2;
  end;

for i:=1 to 10 do
  if ch[i]=1 then
    mas[i]:=1;
end;

Procedure Change(i:longint);
begin
if mas[i]=0 then mas[i]:=1 else
  if mas[i]=1 then mas[i]:=0 else
    if mas[i]=2 then mas[i]:=3 else
      if mas[i]=3 then mas[i]:=2;
end;

Procedure XORi(a:longint);
var i:longint;
    ch:array[1..10]of byte;
begin
for i:=10 downto 1 do
  begin
  ch[i]:=a mod 2;
  a:=a div 2;
  end;

for i:=1 to 10 do
  if ch[i]=1 then
    Change(i);

end;

begin
for i:=1 to 10 do
  mas[i]:=2;
//Vi;

readln(n);
if n<=5 then
writeln(n);
for i:=1 to n do
  begin
  readln(s);
  if n<=5 then writeln(s);
  ch:=0;
  for j:=3 to length(s) do
    begin
    ch:=ch*10;
    ch:=ch+ord(s[j])-ord('0');
    end;
  if s[1]='&' then ANDi(ch);  
  if s[1]='|' then ORi(ch);
  if s[1]='^' then XORi(ch);
  //Vi;
  end;

if n>5 then
begin
writeln(3);

ch:=0;
for i:=1 to 10 do  // 0 1 0 1 0 2 2 1 1 0 
  begin            // 1 0 1 1 0 1 1 0 1 1 
  ch:=ch*2;
  if mas[i]=3 then
    inc(ch);
 end;
writeln('^ ', ch);

ch:=0;
for i:=1 to 10 do
  begin
  ch:=ch*2;  
  if mas[i]<>0 then
    inc(ch);
 end;
writeln('& ', ch);

ch:=0; 
for i:=1 to 10 do
  begin
  ch:=ch*2;
  if mas[i]=1 then
    inc(ch);  
 end;
writeln('| ', ch);
end;
    
end.