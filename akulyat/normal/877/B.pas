Program CodeF_B;
var s:string;
    nach,kon,m:array[0..5010]of longint;
    max,dl,a,b,l,i,kola,kolb,podr:longint;



begin
read(s);
l:=length(s);
for i:=1 to l do
  begin
  if s[i]='a' then
    nach[i]:=nach[i-1]+1 else
    nach[i]:=nach[i-1];
    
  end;

for i:=l downto 1 do
  begin
  if s[i]='a' then
    kon[i]:=kon[i+1]+1 else
    kon[i]:=kon[i+1];
  end;

for i:=1 to l do 
  if s[i]='a' then inc(kola);

a:=0;
b:=0;

for a:=0 to l do
  for b:=a+1 to l+1 do
    begin
    dl:=nach[a]+kon[b]+((l-kola)-(a-nach[a])-((l-b+1)-kon[b]));
    //writeln(a,' ',b,' ',nach[a], ' ',kon[b],' ', dl);
    if dl> max then max:=dl;
    end;
writeln(max);










{read(s);
l:=length(s);
m[0]:=0;
for i:=1 to l do 
  begin
  if s[i]='a' then 
    begin
    m[i]:=m[i-1]+1;
    podr:=0;
    inc(kola);
    end
  else 
    begin
    inc(podr);
    inc(kolb);
    if podr+kola>m[i-1] then
      m[i]:=podr+kola else
      m[i]:=m[i-1];
    end;
  
  
  end;
for i:=1 to l do
  writeln(m[i], ' ');}




end.