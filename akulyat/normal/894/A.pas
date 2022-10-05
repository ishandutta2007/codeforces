Program CodeF_447_A;
var i,j,u,n,kol:longint;
    m:array[1..1]of longint;
    //reb:array[1..1]of array[1..2]of longint;
    s:string;

begin
read(s);
n:=length(s);
for i:=1 to n do
  for j:=i+1 to n do
    for u:=j+1 to n do
      if (s[i]='Q') and (s[j]='A') and (s[u]='Q') then
        inc(kol);
writeln(kol);



end.