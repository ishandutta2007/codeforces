var
 a,b,i,n:longint;
 c:char;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(c);
  c:=upcase(c);
  if c='A'then inc(a);
  if c='D'then inc(b);
 end;
 if a=b then writeln('Friendship')else
 if a>b then writeln('Anton')
 else writeln('Danik');
end.