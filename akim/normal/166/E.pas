var a,b,c,d,e,f:int64;
    i:longint;
begin
 readln(d);
 a:=0;b:=3;c:=0;
 for i:=2 to d do
 begin
  c:=a;
  a:=b;
  b:=(b*2+c*3) mod 1000000007;
 end;
 writeln(a);
end.