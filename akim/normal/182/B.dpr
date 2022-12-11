var a,b,c,s:int64;i:longint;
begin
 readln(a);
 readln(b);
 for i:=1 to b do
 begin
  read(c);
  s:=s+a-c;
 end;
 s:=s-a+c;
 writeln(s);
end.