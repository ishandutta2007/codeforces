Program CodeF_Edu35_r_B;
var i,n,a,b,x:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n, a, b);
x:=a+b+1;
for i:=x downto 1 do
  begin
  if (a div i)+(b div i)>=n then
    if (a>=i) and (b>=i) then
    begin
    writeln(i);
    exit;
    end;
  
  end;
writeln(0);



end.