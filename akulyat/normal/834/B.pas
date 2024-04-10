Program Run;
var gran:array[1..26]of array[1..2]of longint;
    pep:array[0..1000001]of byte;
    n,i,j:longint;
    k,ord0:byte;
    s:char;
    other:boolean;
    
begin
readln(n,k);
for i:=1 to 26 do 
  begin
  gran[i][1]:=1000002;
  gran[i][2]:=0;  
  end;
ord0:=ord('A')-1;  
for i:=1 to n do
  begin
  read(s);
  if gran[ord(s)-ord0][1]=1000002 then
    gran[ord(s)-ord0][1]:=i;
  gran[ord(s)-ord0][2]:=i;  
  end;
other:=false;
for i:=1 to 26 do
  for j:=gran[i][1] to gran[i][2] do
    begin
    inc(pep[j]);
    if pep[j]>k then other:=true;
    end;
if other=true then write('Yes') else
  write('No');    
end.