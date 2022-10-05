Program CodeF_451_A;
var i,n,a,b,kol:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n, a, b);
while (n mod b<>0) and (n>=0)  do
  begin
  n:=n-a;
  inc(kol)
  end;

if n<0 then
  begin
  writeln('NO');
  exit;
  end;

writeln('YES');
writeln(kol, ' ', n div b);




end.