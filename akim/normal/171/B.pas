var a,i:longint;s:int64;
begin
 readln(a);
 s:=1;dec(a);
 for i:=1 to a do
  s:=s+i*12;
 writeln(s);
end.