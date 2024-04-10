var n,m,k,l,i:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  k:=0;
  read(l);
  k:=k+l;
  read(l);
  k:=k+l;
  read(l);
  k:=k+l;
  if k>=2 then inc(m);
 end;
 writeln(m);
end.