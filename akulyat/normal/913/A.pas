Program CodeF_H_2018_A;
var i,n,m,k:longint;
    //reb:array[1..1]of array[1..2]of longint;


begin
read(n);
read(m);
k:=1;
while (k<=m) and (n>0) do
  begin
  k:=k*2;
  dec(n); 
  end;
writeln(m mod k);

end.