Program Azx;
var z,a,kol,n,k:longint;

begin
read(z,k);
n:=240-k;
a:=5;
while ((n-a)>=0) and (z>0) do
  begin
  n:=n-a;
  a:=a+5;
  inc(kol);
  dec(z);
  end;
writeln(kol);

end.