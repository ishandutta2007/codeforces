Program ForMoment;
var i,j,n,a,b:integer;
    s:array[1..100]of array[1..2]of integer;
    max:integer;
    uber:boolean;
    
begin
read(n,a,b);
max:=0;
for i:=1 to n do 
 read(s[i][1], s[i][2]);
for i:=1 to n-1 do 
  for j:=i+1 to n do 
    begin
    uber:=false;
    if (s[i][1]+s[j][1]<=a) and (s[i][2]<=b) and (s[j][2]<=b) then
      uber:=true;
    if (s[i][1]+s[j][1]<=b) and (s[i][2]<=a) and (s[j][2]<=a) then
      uber:=true;
    if (s[i][1]+s[j][2]<=a) and (s[i][2]<=b) and (s[j][1]<=b) then
      uber:=true;
    if (s[i][1]+s[j][2]<=b) and (s[i][2]<=a) and (s[j][1]<=a) then
      uber:=true;      
    if (s[i][2]+s[j][2]<=a) and (s[i][1]<=b) and (s[j][1]<=b) then
      uber:=true;      
    if (s[i][2]+s[j][2]<=b) and (s[i][1]<=a) and (s[j][1]<=a) then
      uber:=true;            
    if (s[j][1]+s[i][2]<=a) and (s[j][2]<=b) and (s[i][1]<=b) then
      uber:=true;
    if (s[j][1]+s[i][2]<=b) and (s[j][2]<=a) and (s[i][1]<=a) then
      uber:=true;            
    if (uber=true) and (s[i][1]*s[i][2]+s[j][1]*s[j][2]>max) then 
      max:=s[i][1]*s[i][2]+s[j][1]*s[j][2];
    end;
writeln(max); 
end.