var a,b,c:longint;d:extended;
begin
 readln(a,b,c);
 d:=sqrt((c*b)/a);
 writeln(((d+c/d+b/d)*4):1:0);
end.