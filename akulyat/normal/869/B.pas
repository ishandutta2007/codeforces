Program CodeF_439_B;
var a,b:int64;
    i,k:longint;


begin
read(a,b);
k:=1;

  if ((b div 10)>(a div 10)) then write(0) else
    begin
    for i:=(a mod 10)+1 to (b mod 10) do
      begin
      k:=(k*i) mod 10;
      end;
    write(k);
    end;






end.