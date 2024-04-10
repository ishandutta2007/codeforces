Program CodeF_Edu20_A;
var mas:array[1..200000]of array[1..2]of longint;
    nul:array[1..200000]of longint;
    ch:int64;
    k,n,i,j:longint;
    
begin
read(n);
k:=0;
for i:=1 to n do 
  begin
    read(ch);
    mas[i][1]:=ch;
    if ch=0 then
      begin
        inc(k);
        nul[k]:=i;
      end;  
  end;

for i:=1 to nul[1] do
  mas[i][2]:=nul[1]-i;
for i:=n downto nul[k] do
  mas[i][2]:=i-nul[k];  
  
for j:=1 to k-1 do
  begin
    for i:=nul[j] to nul[j]+((nul[j+1]-nul[j]+1) div 2) do
      mas[i][2]:=i-nul[j];
    for i:=nul[j+1] downto nul[j+1]-((nul[j+1]-nul[j]+1) div 2)+1 do
      mas[i][2]:=nul[j+1]-i; 
  end;

for i:=1 to n do write(mas[i][2],' ');



end.