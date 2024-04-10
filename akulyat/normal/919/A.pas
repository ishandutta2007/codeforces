var i,n,a,b,m:longint;
    mini:real;

begin
read(n,m);
for i:=1 to n do
  begin
  read(a,b);
  if (mini=0) or (mini>(m*(a/b))) then
    mini:=m*(a/b);
  end;
writeln(mini);



end.