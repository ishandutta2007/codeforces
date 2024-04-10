Program CodeF_425_A;
var nene,otv,n,i,j,l,r:integer;
    lab:array[1..50]of array[1..50]of longint;

begin
read(n);
for i:=1 to n do
  for j:=1 to n do 
    read(lab[i][j]);
    
for l:=1 to n do
  for r:=1 to n do
    begin
        nene:=1;
        if lab[l][r]=1 then nene:=0 else
        for i:=1 to n do
          for j:=1 to n do
            if (i<>r) and (j<>l) and (lab[l][i]+lab[j][r]=lab[l][r]) then nene:=0; 
      if nene=1 then otv:=1;    
    end;
if otv=1 then write('No') else write('Yes');    




end.