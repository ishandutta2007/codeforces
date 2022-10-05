Program CodeF_Edu35_r_D;
var last,mr,mi,i,n:longint;
    m:array[1..100001]of longint;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n);
mi:=1000000001;
for i:=1 to n do
  begin
  read(m[i]);
  if m[i]<mi then
    mi:=m[i];
  end;  
mr:=n+1;  
for i:=1 to n do
  begin
  if (last<>0) and (m[i]=mi) then
    begin
    if i-last<mr then
      mr:=i-last;
    end;    
  if m[i]=mi then
    last:=i; 
  end;
writeln(mr);




end.