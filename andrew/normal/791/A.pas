var
 a,b,sc:longint;
begin
 readln(a,b);
 while a<=b do
 begin
  a:=a*3;
  b:=b*2;
  inc(sc);
 end;
 writeln(sc);
end.