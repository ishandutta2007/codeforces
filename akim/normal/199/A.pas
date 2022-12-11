var a1,a2,a3,c,x:longint;
begin
 readln(x);
 if x=0 then begin writeln('0 0 0');halt(0);end;
 a1:=1;a2:=0;a3:=1;
 while x<>a3 do
 begin
  c:=a2+a3;
  a1:=a2;
  a2:=a3;
  a3:=c;
 end;
 writeln(0,' ',a1,' ',a2);
end.