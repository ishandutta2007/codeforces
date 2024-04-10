var a,b,c,d,i:longint;
begin
 readln(a);c:=0;d:=0;
 for i:=1 to a do
 begin
  read(b);
  if b mod 2=0 then inc(c);
  d:=d+b;
 end;
 if d mod 2=0 then writeln(c) else writeln(a-c);
end.